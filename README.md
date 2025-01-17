
# Minishell

Minishell is a simple shell project implemented in C that replicates the functionality of a Unix shell. It provides features like command execution, pipes, redirections, environment variable handling, and built-in commands.

---

## Features

### 1. **Command Execution**

- Executes system commands (e.g., `ls`, `grep`, `cat`) using absolute or relative paths.
- Handles commands found via the `PATH` environment variable.

### 2. **Built-in Commands**

- `echo` with `-n` option.
- `cd` for directory changes, including `cd -` for switching to the previous directory.
- `pwd` to display the current working directory.
- `export` to set environment variables.
- `unset` to unset environment variables.
- `env` to display all environment variables.
- `exit` to terminate the shell.

### 3. **Redirections**

- Input redirection (`<`): Redirects input from a file.
- Output redirection (`>`): Redirects output to a file.
- Append redirection (`>>`): Appends output to a file.
- Heredoc (`<<`): Accepts input until a specified delimiter.

### 4. **Pipes**

- Supports pipelines (e.g., `ls | grep minishell`).

### 5. **Environment Variables**

- Expands variables like `$HOME`, `$USER`, and `$?` in commands.

### 6. **Abstract Syntax Tree (AST)**

- Built an AST to optimize the parsing and execution of complex command structures.

### 7. **Cache Implementation**

- Developed a cache using a hashtable for efficient lookup and management of environment variables and command paths.

### 8. **Wildcard Expansion**

- Implemented wildcard matching using a dynamic programming table for efficient pattern matching.

### 9. **Signal Handling**

- Handles `ctrl-C`, `ctrl-D`, and `ctrl-\` similar to Bash:
  - `ctrl-C`: Interrupts the current command and displays a new prompt.
  - `ctrl-D`: Exits the shell if no input is provided.
  - `ctrl-\`: Does nothing.

### 10. **Error Handling**

- Displays meaningful error messages for invalid commands, syntax errors, and redirection issues.

---

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/Rami-Fayad/Minishell.git
   ```
   or
   ```bash
   git clone https://github.com/salmadalaty/Minishell.git
   ```


2. Navigate to the project directory:

   ```bash
   cd Minishell
   ```

3. Build the project using `make`:

   ```bash
   make
   ```

4. Run the shell:

   ```bash
   ./minishell
   ```

---

## Usage

1. **Running Commands**:

   ```bash
   minishell> ls -l
   minishell> echo "Hello, World!"
   ```

2. **Using Pipes**:

   ```bash
   minishell> cat file.txt | grep "search_term"
   ```

3. **Redirections**:

   ```bash
   minishell> echo "Output" > output.txt
   minishell> cat < input.txt
   minishell> echo "Append" >> output.txt
   ```

4. **Environment Variables**:

   ```bash
   minishell> echo $HOME
   minishell> export MY_VAR=42
   minishell> echo $MY_VAR
   ```

5. **Built-in Commands**:

   ```bash
   minishell> cd /path/to/directory
   minishell> pwd
   minishell> exit
   ```

---

## Project Structure

- `minishell.c`: Entry point of the program.
- `parser`: Handles tokenization and builds the abstract syntax tree (AST).
- `executor.c`: Executes commands and handles pipes and redirections.
- `signals`: Manages signal handling for `ctrl-C`, `ctrl-D`, and `ctrl-\`.
- `env.c`: Manages environment variables.
- `cache`: Implements the hashtable-based cache.
- `builtins`: Implements built-in commands such as exit, cd, pwd, env, and export.
- `expansion`: Handles wildcard expansion using dynamic programming.
- `Makefile`: Automates the build process.

---

## Known Issues

- Memory leaks: Ensure all allocated memory is freed.
- Some edge cases with complex commands might not be handled.

---

## BONUS

- Added support for `&&` and `||` operators.
- Improved wildcard expansion using dynamic programming.
- Handled subshells and advanced redirection combinations.

---

## Contributors

- [Rami Al Fayad](https://github.com/Rami-Fayad)
- [Salma Dalaty](https://github.com/salmadalaty)

---

## License

This project is licensed under the MIT License. See the LICENSE file for details.
