#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024
#define MAX_ARG_LEN 100

int main() {
    char command[MAX_CMD_LEN];
    char *args[MAX_ARG_LEN];
    pid_t pid;
    int status;

    while (1) {
        printf("myshell> ");
        if (!fgets(command, sizeof(command), stdin)) {
            break; // Exit on EOF
        }

        command[strcspn(command, "\n")] = 0;

        char *token = strtok(command, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARG_LEN - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; // Null-terminate the argument list

        pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) { // Child process
            if (execvp(args[0], args) == -1) {
                perror("Execution failed");
                exit(1);
            }
        } else {
            do {
                waitpid(pid, &status, WUNTRACED); // Wait for child to finish
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }
    return 0;
}
