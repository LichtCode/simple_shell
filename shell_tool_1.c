#include "simple_shell.h"

/**
* tokenizer - converts command from prompts into tokens
* @user_input: input value from user
*
* Return: (command) the list of user inputs or NULL
*/
char **tokenizer(char *user_input)
{

	char *token = NULL, **command = NULL;

	int index = 0, count = 0;

	if (user_input == NULL)
		return (NULL);

	count = count_args(user_input);
	if (count == 0)
	{
		free(user_input);
		return (NULL);
	}

	command = malloc(sizeof(char *) * (count + 1));
	if (command == NULL)
	{
		free(user_input), user_input = NULL;
		return (NULL);
	}
	token = strtok(user_input, DELIM);
	while (token)
	{
		command[index] = _strdup(token);
		token = strtok(NULL, DELIM);
		index++;
	}
	free(user_input), user_input = NULL;
	command[index] = NULL;
	return (command);
}

/**
* count_args - counts the number of strings
* @user_input: input value from user
*
* Return: (count) or 0
*/
int count_args(char *user_input)
{
	int count = 0;

	char *token = NULL, *temp = NULL;

	temp = _strdup(user_input);
	token = strtok(temp, DELIM);
	if (token == NULL)
	{
		free(temp), temp = NULL;
		return (0);
	}

	while (token)
	{
		count++;
		token = strtok(NULL, DELIM);
	}
	free(temp), temp = NULL;

	return (count);
}

/**
* get_user_input - converts command from prompts into tokens
* @void: input value from user
*
* Return: (user_input) user input
*/
char *get_user_input(void)
{
	char *user_input = NULL;

	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "### ", 4);

	n = getline(&user_input, &len, stdin);
	if (n == -1)
	{
		free(user_input);
		return (NULL);
	}

	return (user_input);
}


/**
* _execute - converts command from prompts into tokens
* @argv: input from user through main
* @command: input value from user
* @idx: command index
*
* Return: Status or 127
*/
int _execute(char **argv, char **command, int idx)
{
	pid_t child;
	int status;

	char *full_cmd;

	full_cmd = _getpath(command[0]);
	if (full_cmd == NULL)
	{
		print_error(argv[0], command[0], idx);
		free_cmd(command);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			free_cmd(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free(full_cmd), full_cmd = NULL;
		free_cmd(command);
	}
	return (WEXITSTATUS(status));
}


/**
* free_cmd - converts command from prompts into tokens
* @cmd: input value from user
*
* Return: (void)
*/
void free_cmd(char **cmd)
{
	int index = 0;

	if (!cmd)
		return;
	for (index = 0; cmd[index]; index++)
	{
		free(cmd[index]);
		cmd[index] = NULL;
	}

	free(cmd), cmd = NULL;
}

