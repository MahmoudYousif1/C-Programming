
# Welcome to the shell Manual!

This is a comprehensive manual for the shell that will show you how to use the shell to its full potential. 
This manual is designed to be easy to read and understand, and is suitable for both beginners and experienced users.


# Operations & Commands

1. Cd - This command changes the current working directory. Firstly the initial directory is created 
   and the current working directory is updated when changing directories.

2. clr - This command uses a system function to clear the terminal.

3. dir - This command lists the contents of current working directory. Using the opendir function
   (opens a directory/folder) it prints the name of each directory.

4. environ - Lists all enviromental strings.

5. echo - returns the string input from the command line e.g echo hello.

6. help - This command displays the shell manual.

7. pause - Pauses all operations of the shell until enter is paused.

8. quit - Exits the shell.




# Enviroment Concepts[1]

## what is the Enviroment in Shell Programming

The enviroment in computer science is used to initialize files, variables and commands and just about anything else in the terminal. It basically stores information and data about your shell and what's in it[1]. Programs use the data in the enviroment to deterime facts about our configuration[1]. When you start your system, startup files in your home directory that define your layout and personal files are defined[1].

Using the command 'environ' in the shell terminal allows:
  1. The shell to print all enviroment variables in your configurations.
  2. For easy use of debugging and maintainence to check the current state of the environment variables.



# I/O Input & Output Redirection

## what is Redirection

Redirection allows use to experiment with different ways showcasing outputs, inputs, reading and piping etc[2]. Most shells implement redirection as it is a must have for fast processing. Accord to Tom Ryder's book(Bash quick start guide), redirection and piping allows us to effeciently and effectively work with mutiple files and even combine them[2] so instead of writing hundreds of lines, all you need is a couple of lines[2]. Some redirection techniques include Input redirection and Output redirection.

  1. # Input Redirection

  Commands from shells are mostly taken from the command line where they are processed as string inputs[2]. For example, grep, echo are unix commands. Input redirection is taking input from a different source such as a file. This is invoked by using '<' in the command line after a unix command[2].

  for example: dir < file_a.txt
  this will retrieve all directories in the current directory and display it. This is how input redirection works on a simple basis.


  2. # Output Redirection

  This is basically the opposite of Input redirection and it is invoked by using '>' in the command line[2] and it puts the command line arguements into a file of your choosing[2].

  E.g: environ > file_b.txt
  This will display all enviromental variables into a file called file_b.txt which will be created automatically.


  3. # Output Redirection & Appending

  If want to display the command output in the same file where you already have other command outputs, then you can append them to the end of the file so you don't replace the other commands[3]. This is done by invoking '>>' in the command line[3].

  E.g: ls >> file_b.txt
  This will print the contents of the current working directory under the environ output that we called already.



# The Process Concept & Background/Foreground Execution

# The Process Concept
According to Abraham's Silberchatz's book(Operating System Concepts), 'A process is the unit of work in a modern-time-sharing system'[4].
In my opinion, A process is a fundamental term in computers and operating systems, that represents an instance of a computer programme that is running.In linux a running programming or a command is called a process[5:page 92].The more complex a system is the more the users raise it's expectation of it[4]. It's main functionalties are executing user commands, monitoring commands, etc[4].


# Difference Between Foreground & Background Execution

Two ways of running background processes include[5: page 94]:
  1. Foreground Execution
  2. Background Execution

  In Foreground exection, the parent process is pushed aside while the child process takes over[4] while in background execution, commands can be processed while other tasks are running in the foreground and when this background process is complete, a user is notified[5]. To run a command in the background you can this symbol & at the end of your command in the command prompt[5].

  E.g 1. touch file_A.txt
  When using touch in the foreground the shell waits for the command to be completed first before it allows you to enter another commnad

  E.g 2. grep hello file_B > file_A.txt &
  With the added & at the end, this process will now run in the background but it will also return the command back to you, allow you to continue working on your shell. 




# REFERENCES

RESOURCE 1 - THE LINUX COMMAND LINE, A COMPLETE INTRODUCTION - BY WILLIAM E.SHOTTS, JR: https://www.google.ie/books/edition/The_Linux_Command_Line/OCFKdl3wEDIC?hl=en&gbpv=1&dq=The+Linux+Command+Line:+A+Complete+Introduction%22+by+William+E.+Shotts,+Jr.&printsec=frontcover

RESOURCE 2 - BASH QUICK START GUIDE - BY TOM RYDER: https://www.google.ie/books/edition/Bash_Quick_Start_Guide/SP1wDwAAQBAJ?hl=en&gbpv=1


RESOURCE 3 - UNIX OPERATING SYSTEM, THE DEVELOPMENT TUTORIAL VIA UNIX KERNAL SERVICES - BY YUKUN LIU, YONG YUE, LIEWEI GUO: https://www.google.ie/books/edition/UNIX_Operating_System/-Mq5ve5KHXQC?hl=en&gbpv=1&dq=Y.+Liu,+Y.+Yue,+L.+Guo,+UNIX+I/O+System,+I/O+Redirection+and+Piping.+Springer,+Berlin,+Heidelberg,+2011,+doi:+10.1007/978-3-642-20432-6_7.&printsec=frontcover


RESOURCE 4 - OPERATING SYSTEM CONCEPTS - BY ABRAHAM SILBERCHATZ: https://www.google.ie/books/edition/Operating_System_Concepts/FH8fAQAAIAAJ?hl=en&gbpv=1&bsq=Operating+system+concepts&dq=Operating+system+concepts&printsec=frontcover


RESOURCE 5 - OPERATING SYSTEMS CONCEPTS - BY SHITAL VIVEK GHATE: https://www.google.ie/books/edition/Operating_System_Concepts_and_Basic_Linu/mHs6DwAAQBAJ?hl=en&gbpv=1&dq=operating+system+concepts&printsec=frontcover


/* Name: Mahmoud Yousif, Student Number: 22703519*/
/* I acknowledge the DCU Academic Integrity Policy. */
