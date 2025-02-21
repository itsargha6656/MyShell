# MyShell

A simple command-line shell implemented in C that reads user input, parses commands, and executes them.

## Features
- Reads user input from standard input.
- Parses input into commands and arguments.
- Executes system commands using `execvp`.
- Implements a basic shell loop.
- Supports the `exit` command to terminate the shell.

## Getting Started

### Prerequisites
- GCC compiler
- Unix-based operating system (Linux or macOS)

### Installation
1. Clone the repository:
   ```sh
   git clone <repository-url>
   cd myshell
   ```
2. Compile the shell:
   ```sh
   gcc myshell.c -o myshell
   ```

3. Run the shell:
   ```sh
   ./myshell
   ```

## Usage
Once the shell is running, type any system command (e.g., `ls`, `pwd`, `echo Hello`) and press Enter.

Example:
```
> ls
file1.txt  file2.c  myshell.c
> echo "Hello, World!"
Hello, World!
> exit
```

## Code Structure
- **main()**: Calls `shell_loop()` to run the shell.
- **shell_loop()**: Loops, taking input and executing commands.
- **read_line()**: Reads input from the user.
- **split_line()**: Splits the input into command and arguments.
- **execute_command()**: Executes the given command using `fork()` and `execvp()`.

## Contributing
Feel free to fork this project and submit pull requests.



