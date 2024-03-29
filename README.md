# SIMPLE SHELL
This repository contains the 'simple' shell project. A project mimicking the Unix shell first invented by Ken Thompson. Collaborative effort

### By
- Akinade Hassan Babatunde [github](https://github.com/LichtCode)

## 1. Simple shell 0.1
Write a UNIX command line interpreter.
- Usage: simple_shell

Your Shell should:
- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:
- use the PATH
- implement built-ins
- handle special characters : ", ', `, \, *, &, #
- be able to move the cursor
- handle commands with arguments

## 2. Simple shell 0.2
Simple shell 0.1 +
- Handle command lines with arguments

## 3. Simple shell 0.3
Simple shell 0.2 +
- Handle the PATH
- fork must not be called if the command doesn’t exist

## 4. Simple shell 0.4
Simple shell 0.3 +
- Implement the exit built-in, that exits the shell
- Usage: exit
- You don’t have to handle any argument to the built-in exit

## 5. Simple shell 1.0
Simple shell 0.4 +
- Implement the env built-in, that prints the current environment

## 6. Simple shell 0.1.1
Simple shell 0.1 +
- Write your own getline function
- Use a buffer to read many chars at once and call the least possible the read system call
- You will need to use static variables
- You are not allowed to use getline

You don’t have to:
- be able to move the cursor

## 7. Simple shell 0.2.1
Simple shell 0.2 +
- You are not allowed to use strtok

## 8. Simple shell 0.4.1
Simple shell 0.4 +
- handle arguments for the built-in exit
- Usage: exit status, where status is an integer used to exit the shell

## 9. setenv, unsetenv