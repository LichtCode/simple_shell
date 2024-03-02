#include "simple_shell.h"
/**
* is_builtin - checks if the command is builtin
* @command: input value from user
*
* Return: 1 if builtin or 0 if not
*/
int is_builtin(char *command)
{
	char *builtins[] = {

		"exit", "env", "setenv", "cd", NULL
	};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(command, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
* handle_builtin - calls neccesary funtion if command is builtin
* @command: input value from user
* @argv: input from user by main
* @status: status of execution
* @idx: command index
*
* Return: (void)
*/
void handle_builtin(char **command, char **argv, int *status, int idx)
{
	if (_strcmp(command[0], "exit") == 0)
		exit_shell(command, status, argv, idx);
	else if (_strcmp(command[0], "env") == 0)
		print_env(command, status);
}

/**
* exit_shell - exits the prompt
* @command: input value from user
* @status: status of execution
* @argv: input from user by main
* @idx: command index
*
* Return: (void)
*/
void exit_shell(char **command, int *status, char **argv, int idx)
{
	int exit_status = *status;

	char *index, msg[] = "exit: Illegal number: ";

	if (command[1])
	{
		if (is_postive(command[1]))
		{
			exit_status = _atoi(command[1]);
		}
		else
		{
			index = _itoa(idx);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, msg, _strlen(msg));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			free_cmd(command);
			*status = 2;
			return;
		}
	}
	free_cmd(command);
	exit(exit_status);
}

/**
* print_env - exits the prompt
* @command: input value from user
* @status: status of execution
*
* Return: (void)
*/
void print_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_cmd(command);
	*status = 0;
}
