#include "simple_shell.h"

/**
* is_postive - check if number passed to it is positve
* @str: input string
*
* Return: 0 if positive or 1 if not
*/
int is_postive(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
* _atoi - converts string to integer
* @str: input string
*
* Return: the converted integer
*/
int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}

/**
* _itoa - converts integer to string
* @n: input integer
*
* Return: the converted string
*/
char *_itoa(int n)
{
	char buffer[20];

	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (_strdup(buffer));
}
