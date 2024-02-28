#include "main.h"

/**
 * main - Simple shell main function
 * @argc: Counts of arguments
 * @argv: arguments List
 * Return: 0 Always (success)
 */

int main(int argc, char **argv)
{
	char *user_input = NULL, **command = NULL;
	int status = 0, idx = 0;
	(void)argc;

	while (1)
	{
		user_input = get_user_input();
		if (user_input == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		idx++;
		command = tokenizer(user_input);
		if (command == NULL)
			continue;

		if (is_builtin(command[0]))
			handle_builtin(command, argv, &status, idx);
		else
			status = _execute(argv, command, idx);

	}
}
