#include "simple_shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int x = 0, i = 0;

	while (dest[x] != '\0')
	{
		x++;
	}

	while (src[i] != '\0')
	{
		dest[x] = src[i];
		x++;
		i++;
	}

	dest[x] = '\0';
	return (dest);
}


/**
 * reverse_string - Reverse strings
 * @str: string value
 * @len: length  of string
 *
 * Return: the reversed string
 */
void reverse_string(char *str, int len)
{
	char temp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
