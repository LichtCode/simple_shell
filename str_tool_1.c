#include "simple_shell.h"

/**
 * _strdup - duplicate to new memory space location
 * @str: char
 * Return: 0
 */
char *_strdup(const char *str)
{
	char *rev_str;
	int index, count = 0;

	if (str == NULL)
		return (NULL);
	while (str[count] != '\0')
		count++;

	rev_str = malloc(sizeof(char) * (count + 1));

	if (rev_str == NULL)
		return (NULL);

	for (index = 0; index <= count; index++)
		rev_str[index] = str[index];

	return (rev_str);
}


/**
 * _strlen - returns the length of a string
 * @str: string
 * Return: length
 */
int _strlen(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}

	return (len);
}


/**
 * _strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int count = 0, index = 0;

	while (*(src + count) != '\0')
	{
		count++;
	}

	for ( ; index < count ; index++)
	{
		dest[index] = src[index];
	}

	dest[count] = '\0';
	return (dest);
}


/**
 * _strcmp - compare string values
 * @str1: input value
 * @str2: input value
 *
 * Return: str1[i] - str2[i]
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}
