#include "main.h"
/**
* _getpath - gets the path from the environment variable
* @command: input string from user
*
* Return: (full_cmd) or NULL
*/
char *_getpath(char *command)
{
	char *env_path, *full_cmd, *dir;

	struct stat st;
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
	}

	env_path = _getenv("PATH");
	if (env_path == NULL)
		return (NULL);

	dir = strtok(env_path, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(command) + 2);
		if (full_cmd != NULL)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
			{
				free(env_path);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;

			dir = strtok(NULL, ":");
		}
	}
	free(env_path);
	return (NULL);
}

/**
* _getenv - gets the environment variable
* @env_var: the target environment variable
*
* Return: (env) or NULL
*/
char *_getenv(char *env_var)
{
	char *env, *temp, *key, *value;

	int i;

	for (i = 0; environ[i]; i++)
	{
		temp = _strdup(environ[i]);
		key = strtok(temp, "=");
		if (_strcmp(key, env_var) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(temp);
			return (env);
		}
		free(temp);
	}
	return (NULL);
}

/**
* print_error - gets the path from the environment variable
* @input: input from user
* @cmd: input value from user
* @idx: command index
*
* Return: (void)
*/
void print_error(char *input, char *cmd, int idx)
{
	char *index, msg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, input, _strlen(input));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(index);
}
