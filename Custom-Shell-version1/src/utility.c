/* Name: Mahmoud Yousif, Student Number: 22703519 */
/* Declaration: I acknowledge the DCU Academic Integrity Policy. */

#include "myshell.h" /* Included the header files and functions defined in myshell.h so I can write the code functionalities here. */

/* this Function will display a welcome sign when opening the shell. */
/* This code snippet helped me understand how to change text color in the terminal: https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c */
void welcomeOutput()
{
    printf("\x1b[36m"); /* Set text colour to cyan. */
    printf("\n Welcome to MyShell! :) \n\n Type help to open the manual\n Type pause to pause the shell \n Type quit to exit the shell\n\n");
    printf("\x1b[0m"); /* Resetting back to the base colour. */
}


/* This function will display a goodbye message when exiting the shell. */
void goodbyeOutput()
{
    printf("\x1b[34m"); /* Set text colour to red */
    printf("\n Thanks for using my shell!, Goodbye! :)\n\n");
    printf("\x1b[0m"); /* Resetting back to the base colour. */
}


/* This function will change the directory. */
/* This code snippet helped me understand how to change the directory: https://stackoverflow.com/questions/35424178/chdir-in-a-custom-shell-in-unix */
/* I used perror as it prints a more discriptive error message helping me indentify errors: https://www.tutorialspoint.com/c_standard_library/c_function_perror.htm*/
void changingDir(char **args)
{
    if (args[1] == NULL) /* If the user does not enter a directory. */
    {
        char cwd[1024];                       /* Buffer to store the current directory */
        if (getcwd(cwd, sizeof(cwd)) != NULL) /* Get the current directory */
        {
            printf("%s\n", cwd); /* Print the current directory */
        }
        else
        {
            perror("getcwd() error after cd"); /* Print an error message if getcwd() fails */
        }
    }
    else
    {
        if (chdir(args[1]) == 0) /* If the directory is changed successfully. */
        {
            /* Successfully changed the directory */
            char myDirectory[1024];                               /* Buffer to store the current directory */
            if (getcwd(myDirectory, sizeof(myDirectory)) != NULL) /* Get the current directory */
            {
                /* Set the PWD environment variable to the current directory */
                setenv("PWD", myDirectory, 1);
            }
            else
            {
                perror("getcwd() error after cd"); /* Print an error message if getcwd() fails */
            }
        }
        else
        {
            perror("cd failed"); /* Print an error message if chdir() fails */
        }
    }
}


/* This function will clear the shell. */
/* I used the system command to clear the shell: https://www.geeksforgeeks.org/clear-console-c-language/ */
void clearShell()
{
    system("clear"); /* Clear the screen. */
}


/* This function will list the contents of the current directory. */
/* This code snippet helped me understand how to list the contents of a directory: https://stackoverflow.com/questions/3554120/open-directory-using-c */
void listDir()
{
    DIR *mydir;           /* Create a pointer to the directory. */
    struct dirent *entry; /* Create a pointer to the directory entry. */

    mydir = opendir("."); /* Open the current directory. */
    if (mydir != NULL)
    { /* If the directory is opened successfully. */
        while ((entry = readdir(mydir)) != NULL)
        {                                  /* While there are still entries in the directory. */
            printf("%s\n", entry->d_name); /* Print the name of the entry. */
        }

        closedir(mydir); /* Close the directory. */
    }
    else
    {
        perror("opendir() error"); /* Display an error message pertaining to the failure of opendir() */
        return;
    }
}


/* This function will list the environment variables. */
void environFunc(char **envp)
{
    int i = 0; /* Create a variable to store the index of the environment variable. */
    while (envp[i] != NULL)
    {                            /* While there are still environment variables. */
        printf("%s\n", envp[i]); /* Print the environment variable. */
        i++;                     /* Increment the index. */
    }
}


/* This function will echo the input. */
void echoFunc(char **args)
{
    int i = 1;
    while (args[i] != NULL) /* This while loop, loops through the arguments and print them */
    {
        printf("\n");
        printf("%s ", args[i]); /* Print each enviromental variable */
        i++;
    }
    printf("\n\n"); /* Print a new line */
}


/* This function will display the manual. */
/* This make sure that the manual can be displayed no matter what directory you're in, I had to firstly create a variable to store the path to the manual
and then I copied the orignal path to the current path and opened the file. */
/* this query on stackoverflow helped me understand how to use snprintf: https://stackoverflow.com/questions/14973668/how-do-i-open-a-file-in-c-that-is-in-the-same-directory-as-the-program */
void helpFunc()
{
    FILE *file;                /* Create a variable to store the file. */
    char manualPath[PATH_MAX]; /* Create a variable to store the path to the manual. */
    if (snprintf(manualPath, sizeof(manualPath), "%s/manual/readme.md", startDir) >= sizeof(manualPath))
    {
        perror("Manual path is too long"); /* Print an error message if the manual path is too long */
        return;
    }
    file = fopen(manualPath, "r"); /* Open the manual file. */
    if (file == NULL)              /* If the file is not opened successfully. */
    {
        perror("Failed to open manual file"); /* Print an error message. */
        return;
    }
    int chars;                           /* Create a variable to store the character. */
    while ((chars = fgetc(file)) != EOF) /* While the end of the file is not reached. */
    {
        putchar(chars); /* Print the character. */
    }
    fclose(file); /* Close the file. */
}



/* This function will pause the shell. */
void pauseFunc()
{
    printf("\x1b[31m");                                    /* Seting the text colour to red */
    printf("Shell is paused, press Enter to continue..."); /* Print the message to the user. */
    printf("\x1b[0m");                                     /* Resetting back to the base colour. */
    while (getchar() != '\n')
    { /* While the user does not press enter. */
    }
}



/* This function will handle the signal for the quit function. */
/* I took inspiration from this post to create this signal Handler to close the shell: https://stackoverflow.com/questions/16294153/what-is-the-signal-function-sigint */
void closeShell(int sig)
{
    goodbyeOutput(); /* Display the goodbye message. */
    exit(0);         /* Exit the shell. */
}


/* This function will quit the shell. */
void quitFunc()
{
    raise(SIGINT); /* Raises the SIGINT signal to trigger the handler and close the shell. */
}



/* This function will execute the external commands. */
/* This code snippet helped me understand how to execute external commands with fork and execvp: https://stackoverflow.com/questions/4204915/implementation-of-shell-in-c-and-how-execlp-works */
void exeExternalCommands(char *cmd, char **args)
{
    int stdin_copy = dup(0);  /* Create a variable to store the copy of the standard input file descriptor. */
    int stdout_copy = dup(1); /* Create a variable to store the copy of the standard output file descriptor. */
    int stderr_copy = dup(2); /* Create a variable to store the copy of the standard error file descriptor. */

    ioRedirectionFunc(args, &stdin_copy, &stdout_copy, &stderr_copy); /* Handle the input/output redirection. */

    pid_t pid = fork(); /* Create a child process. */
    if (pid == 0)
    {                             /* If the child process is created successfully. */
        execvp(cmd, args);        /* Execute the commands */
        perror("execvp() error"); /* Print an error message if execvp() fails */
        exit(1);
    }
    else if (pid < 0)
    {                           /* If the child process is not created successfully. */
        perror("fork() error"); /* Print an error message if fork() fails */
    }
    else
    {
        if (!backgroundProcessFunc(args))
        {               /* If the command is not a background command. */
            wait(NULL); /* Wait for the child process to finish. */
        }
    }

    IOrestoreFunc(&stdin_copy, &stdout_copy, &stderr_copy); /* Restore the input/output redirection. */
}

/* This function will execute the shell commands. */
/* I took inspiration from this site to implement my built in commmands(View step 7): https://medium.com/@winfrednginakilonzo/guide-to-code-a-simple-shell-in-c-bd4a3a4c41cd */
void exeShellCommands(char *cmd, char **args, char **envp)
{
    if (strcmp(cmd, "cd") == 0)
    {                      /* If the command is cd. */
        changingDir(args); /* Change the directory. */
    }
    else if (strcmp(cmd, "clr") == 0)
    {                 /* If the command is clr. */
        clearShell(); /* Clear the shell. */
    }
    else if (strcmp(cmd, "dir") == 0)
    {              /* If the command is dir. */
        listDir(); /* List the contents of the directory. */
    }
    else if (strcmp(cmd, "environ") == 0)
    {                      /* If the command is environ. */
        environFunc(envp); /* List the environment variables. */
    }
    else if (strcmp(cmd, "echo") == 0)
    {                   /* If the command is echo. */
        echoFunc(args); /* Echo the input. */
    }
    else if (strcmp(cmd, "help") == 0)
    {               /* If the command is help. */
        helpFunc(); /* Display the manual. */
    }
    else if (strcmp(cmd, "pause") == 0)
    {                /* If the command is pause. */
        pauseFunc(); /* Pause the shell. */
    }
    else if (strcmp(cmd, "quit") == 0)
    {               /* If the command is quit. */
        quitFunc(); /* Quit the shell. */
    }
    /* else if the command is an external command then run this */
    else
    {
        exeExternalCommands(cmd, args); /* Execute the external commands. */
    }
}

/* This function will print the current prompt. */
void printCurrentPrompt()
{
    char cwd[PATH_MAX];       /* Create a variable to store the current working directory. */
    getcwd(cwd, sizeof(cwd)); /* Get the current working directory. */
    printf("%s ==> ", cwd);   /* Print the current working directory as the shell prompt. */
}


/* This function will read the users input. */
void readUsers(char *users_input)
{
    fgets(users_input, MAX_BUFFER, stdin);       /* Get the input from the user. */
    users_input[strlen(users_input) - 1] = '\0'; /* Remove the newline character. */
}


/* This function will parse the users input. */
/* This site helped me understand how to parse input in c: https://cs.slu.edu/~dferry/courses/old/csci3500_sp19/studios/06_strtok.html#:~:text=Parsing%20input%20in%20C%20is,user%20input%20with%20fgets() */
void parseUsersInput(char *users_input, char **args)
{
    char *cmd; /* Create a variable to store the command. */

    cmd = strtok(users_input, SEPARATORS); /* Get the command from the input. */
    if (cmd == NULL)
    {           /* If the command is empty. */
        return; /* Return. */
    }

    args[0] = cmd; /* Store the command in the arguments array. */
    for (int i = 1; i < MAX_ARGS; i++)
    {                                       /* For each argument. */
        args[i] = strtok(NULL, SEPARATORS); /* Get the argument from the input. */
        if (args[i] == NULL)
        {          /* If the argument is empty. */
            break; /* Break the loop. */
        }
    }
}

/* This function will start the shell. */
void startShell(char **envp)
{
    char users_input[MAX_BUFFER]; /* Create a variable to store the users input. */
    char *args[MAX_ARGS];         /* Create an array to store the arguments. */

    welcomeOutput();            /* Display the welcome message. */
    signal(SIGINT, closeShell); /* Handle the signal for the quit function. */

    while (1)
    {                                          /* While the shell is running. */
        printCurrentPrompt();                  /* Print the current prompt. */
        readUsers(users_input);                /* Read the users input. */
        parseUsersInput(users_input, args);         /* Parse the users input. */
        exeShellCommands(args[0], args, envp); /* Execute the shell commands. */
    }
}



/* This function will parse the lines in the batchfile */
void batchParse(char *line, char **envp)
{
    char *args[MAX_ARGS];                     /*Array to store the arguments */
    char *command = strtok(line, SEPARATORS); /* Get the first line in the file */
    int i = 0;                                /* Counter for the arguments */

    while (command != NULL)
    {
        args[i++] = command;                /* Store the command in the arguments array */
        command = strtok(NULL, SEPARATORS); /* Get the next command */
    }
    args[i] = NULL; /* Set the last argument to NULL */

    if (args[0] != NULL)
    {                                          /* If the command is not empty */
        exeShellCommands(args[0], args, envp); /* Execute the shell commands */
    }
}



/* This function will process the batch file. */
/* This code snippet helped me understand how to open a file in c: https://www.geeksforgeeks.org/c-program-open-read-file/ */
/* I was having trouble with whitespace and end of line character and this query on stackoverflow helped me understand how to fix it: https://stackoverflow.com/questions/42756232/batch-processing-in-a-simple-shell */
void batchProcessFunc(const char *filename, char **envp)
{
    FILE *file = fopen(filename, "r"); /* Open the batch file */
    if (!file)
    {
        perror("Failed to open batch file"); /* Print an error message if the file is not opened successfully */
        exit(EXIT_FAILURE);
    }

    char line[MAX_BUFFER]; /* Create a buffer to store the line */
    while (fgets(line, sizeof(line), file) != NULL)
    {
        line[strcspn(line, "\r\n")] = 0; /* Remove the newline character */
        batchParse(line, envp);          /* Call this function to parse the lines correctly */
    }
    fclose(file); /* Close the file at the end after parsing each commnad */
}


/* This function will redirect the input. */
/* Using the notes on I/O redirection in lab 4/5, I was able to implement these functions using dup2: https://loop.dcu.ie/mod/book/view.php?id=2322719&chapterid=492184 */
/* This site helped me understand how to use dup/dup2 : https://www.geeksforgeeks.org/dup-dup2-linux-system-call/ */
void redirectingInput(char *filename) { 
    FILE *file = fopen(filename, "r"); /* Open the file */
    if (file == NULL) { /* If the file is not opened successfully */
        perror("error opening file"); /* Print an error message */
        return;
    }
    dup2(fileno(file), STDIN_FILENO); /* Else redirect the input */
    fclose(file); /* Close the file */
}


/* This function will redirect the output. */
void redirectingOutput(char *filename) {
    FILE *file = fopen(filename, "w"); /* Open the file */
    if (file == NULL) { /* If the file is not opened successfully */
        perror("error creating file"); /* Print an error message */
        return;
    }
    dup2(fileno(file), STDOUT_FILENO); /* Else redirect the output */
    fclose(file); /* Close the file */
}


/* This function will redirect the output with append. */
void redirectAppend(char *filename) {
    FILE *file = fopen(filename, "a"); /* Open the file */
    if (file == NULL) { /* If the file is not opened successfully */
        perror("error opening file"); /* Print an error message */
        return;
    }
    dup2(fileno(file), STDOUT_FILENO); /* Else redirect the output */
    fclose(file); /* Close the file */
}


/* This function will handle the input/output redirection. */
/* This query on stackoverflow helped me understand how to handle input/output redirection better and I took inspiration from the post: https://stackoverflow.com/questions/52939356/redirecting-i-o-in-a-custom-shell-program-written-in-c */
void ioRedirectionFunc(char **args, int *stdin_copy, int *stdout_copy, int *stderr_copy) {
    char *args_clean[MAX_ARGS]; /* Create an array to store the cleaned arguments */
    int cleanedArgs = 0; /* Create a variable to store the cleaned arguments */

    for (int j = 0; args[j] != NULL; j++) { /* For each argument */
        if (!strcmp(args[j], "<")) { /* If the argument is < */
            ++j; /* Increment the index */
            redirectingInput(args[j]); /* Redirect the input */
            continue;
        }

        if (!strcmp(args[j], ">")) { /* If the argument is > */
            ++j;
            redirectingOutput(args[j]); /* Redirect the output */
            continue;
        }

        if (!strcmp(args[j], ">>")) { /* If the argument is >> */
            ++j;
            redirectAppend(args[j]); /* Redirect the output with append */
            continue;
        }

        args_clean[cleanedArgs++] = args[j]; /* Store the cleaned arguments */
    }

    args_clean[cleanedArgs] = NULL; /* Set the last argument to NULL */
    memcpy(args, args_clean, sizeof(char *) * (cleanedArgs + 1)); /* Copy the cleaned arguments */
}



/* This function will restore the input/output redirection. */
void IOrestoreFunc(int *standardInput, int *standardOutput, int *standardError)
{
    dup2(*standardInput, STDIN_FILENO); /* Restore back to standardInput */
    close(*standardInput);
    dup2(*standardOutput, STDOUT_FILENO); /* Restore back to standardOutput */
    close(*standardOutput);
    dup2(*standardError, STDERR_FILENO); /* Restore back to standardError */
    close(*standardError);
}



/* This function will handle the background process. */
/* Used the notes on week 4/5 for Backround exection of external commands to create this function using the ampersand at the end of the command line */
bool backgroundProcessFunc(char **args)
{ /* This function will check if the command is a background process */
    for (int i = 0; args[i] != NULL; i++)
    { /* For each argument */
        if (strcmp(args[i], "&") == 0)
        {                   /* If the argument is & */
            args[i] = NULL; /* Set the argument to NULL */
            return true;    /* Return true */
        }
    }
    return false; /* Otherwise return false */
}
