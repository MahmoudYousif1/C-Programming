/* Name: Mahmoud Yousif, Student Number: 22703519*/
/* I acknowledge the DCU Academic Integrity Policy. */

/* Include files */
#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <string.h>    /* for strlen, strcmp, strcpy, strtok, etc */
#include <unistd.h>    /* for fork, execve, chdir*/
#include <sys/types.h> /* for pid_t*/
#include <sys/stat.h>  /* for stat */
#include <fcntl.h>     /* for O_RDONLY, O_WRONLY, O_CREAT */
#include <errno.h>     /* for errno */
#include <signal.h>    /* for signal */
#include <dirent.h>    /* for opendir, readdir, closedir */
#include <stdbool.h>   /* for bool, true, false */
#include <limits.h>    /* for PATH_MAX */
#include <sys/wait.h>  /* for wait */

/* Defining constants */
#define MAX_BUFFER 1024         /* max line buffer */
#define MAX_ARGS 64             /* max # args */
#define SEPARATORS " \t\n"      /* token separators */
extern char startDir[PATH_MAX]; /* Declaration of the global variable to store the initial directory */

/* Function prototypes */
void welcomeOutput();                                                                     /* Function to display a welcome message when starting the shell. */
void goodbyeOutput();                                                                     /* Function to display a goodbye message when exiting the shell. */


/* Function prototypes for both built in and external shell commands. */
void clearShell();                                                                        /* Function to clear the shell. */
void changingDir(char **args);                                                            /* Function to change directories. */
void listDir();                                                                           /* Function to list the contents of the current directory. */
void environFunc(char **envp);                                                            /* Function to list the environment variables. */
void echoFunc(char **args);                                                               /* Function to echo the input. */
void helpFunc();                                                                          /* Function to display the manual. */
void pauseFunc();                                                                         /* Function to pause the shell. */
void closeShell(int sig);                                                                 /* Function to handle the signal. */
void quitFunc();                                                                          /* Function to exit the shell. */
void exeExternalCommands(char *cmd, char **args);                                         /* Function to execute the external commands. */


/* Function prototypes to run the shell. */
void exeShellCommands(char *cmd, char **args, char **envp);                               /* Function to execute all commands. */
void printCurrentPrompt();                                                                /* Function to print the current prompt. */
void startShell(char **envp);                                                             /* Function to start the shell. */


/* Function prototypes for the processing and reading in batch mode. */
void readUsers(char *users_input);                                                        /* Function to read the users. */
void parseUsersInput(char *users_input, char **args);                                     /* Function to parse the users. */
void batchProcessFunc(const char *filename, char **envp);                                 /* Function to process the batch file. */
void batchParse(char *line, char **envp);                                                 /* Function to parse the batch file. */


/* Function prototypes for the I/O redirection and background processing. */
void redirectingInput(char *filename);                                                    /* Function to redirect the input. */
void redirectingOutput(char *filename);                                                   /* Function to redirect the output. */
void redirectAppend(char *filename);                                                      /* Function to redirect the output with append. */
void ioRedirectionFunc(char **args, int *stdin_copy, int *stdout_copy, int *stderr_copy); /* Function to handle the I/O redirection. */
void IOrestoreFunc(int *standardInput, int *standardOutput, int *standardError);          /* Function to restore the I/O redirection. */
bool backgroundProcessFunc(char **args);                                                  /* Function to handle the background process. */