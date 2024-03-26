/* Name: Mahmoud Yousif, Student Number: 22703519 */
/* Declaration: I acknowledge the DCU Academic Integrity Policy. */

#include "myshell.h"

char startDir[PATH_MAX]; /* Declaration of the global variable to store the initial directory. */

int main(int argc, char **argv, char **envp)
{
    /* Save the initial directory */
    if (getcwd(startDir, sizeof(startDir)) == NULL)
    {
        perror("Error fetching initial directory"); /* If there is an error fetching the initial directory. */
        exit(1);
    }

    if (argc > 1) /* If the user enters more than one argument. */
    {
        batchProcessFunc(argv[1], envp); /* Run batchmode and process the file. */
    }
    else
    {
        startShell(envp); /* Else Start the shell. */
    }
}
