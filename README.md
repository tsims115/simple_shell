# Simple Shell Project

The Simple Shell is a recreation of the Shell used to interface with the computer system, specifically designed in and for Ubuntu.

# Usage

To use the Simple Shell, enter the command ./hsh. From there, a prompt will be printed, and a command can be entered.
The available built-in commands are listed below.

# Builtins
This Simple Shell is capable running:

* `env`: This command will print out all the environment variables on the current machine.

* `exit`: This command will close the Simple Shell process and free all the memory associated with it,

# Files

* `main.h`: The header file, containing all the necessary #includes, prototypes, and structures.

* `simple_shell.c`: The main file of the program - this contains the main function which takes user input and matches it against built-ins or sends it the `run` function.

* `splitter.c`: This file contains the `splitter` function, taking the user input from `main` and separating it into multiple strings to be parsed.

* `run.c`: If the entered command from the prompt matches an existing system call, such as `ls`, it is sent here, where the `run` function will call `execve` to execute the command.

* `path_list.c`: Used to create a linked list containing each of the PATH directories to search through inthe `run` function.

* `_printf.c`: A recreation of the printf function for our ease of use.

* `spec_funcs.c`: Functions to assist with _printf.c

* `string_funcs.c`: Recreations of functions `strdup`, `strcact`, `strchr`, `strcpy`, and `putchar`.

* `_itoa`: Recreation of the `itoa` function for `_printf`.

# Authors

* Geoffrey Sims
* Joseph Williams