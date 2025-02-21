#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Function prototypes (declare before use)
void shell_loop(void);
char *read_line(void);
char **split_line(char *line);
int execute_command(char **args);

int main() {
    shell_loop();  // Start the shell loop
    return EXIT_SUCCESS;
}

void shell_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");  // Display shell prompt
        line = read_line();  // Read user input
        args = split_line(line);  // Parse input
        status = execute_command(args);  // Execute command

        free(line);  // Free memory
        free(args);
    } while (status);  // Repeat until status is 0
}

char *read_line(void) {
    char *line = NULL;
    size_t bufsize = 0;
    getline(&line, &bufsize, stdin);  // Read input from the user
    return line;
}

#define TOKEN_BUFFER_SIZE 64
#define DELIMITERS " \t\r\n\a"

char **split_line(char *line) {
    int bufsize = TOKEN_BUFFER_SIZE;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;
    int position = 0;

    token = strtok(line, DELIMITERS);  // Get first word
    while (token != NULL) {
        tokens[position] = token;
        position++;

        token = strtok(NULL, DELIMITERS);  // Get next word
    }
    tokens[position] = NULL;  // NULL-terminate array
    return tokens;
}

int execute_command(char **args) {
    if (args[0] == NULL) {
        return 1;  
    }
    
    if (strcmp(args[0], "exit") == 0) {
        return 0;  // Exit the shell
    }

    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("shell");
    } else {
        wait(NULL);
    }

    return 1;
}

