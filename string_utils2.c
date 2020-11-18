#include "hsh.h"

/**
 * _putchar - writes the character c to stdout
 *
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcat - concatenates two strings
 *
 * @s1: the first string
 * @s2: the second string
 *
 * Return: a pointer to the new string, or NULL on failure
 */

char *_strcat(char *s1, char *s2)
{
	char *str;
	int i = 0, j = 0;

	str = malloc(sizeof(char) * (_strlen(s1) + _strlen(s2) + 1));
	if (!str)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	if (s2 != NULL)
	{
		while (s2[j] != '\0')
		{
			str[i + j] = s2[j];
			j++;
		}
	}
	str[i + j] = '\0';
	return (str);
}

/**
 * _strtok - respin of strtok()
 *
 * @str - string to split
 * @delim - string of delimiters
 *
 * Return: pointer to next token
 */

char *_strtok(char *str, char *delim)
{
	char *tok = NULL;
	static char *ptrtok;
	int i = 0, j = 0;

	if (str)
		tok = str;
	else if (ptrtok)
	{
		str = ptrtok;
		tok = ptrtok;
	}
	else
		perror("_strtok");

	while (delim[i])
	{
		j = 0;
		while (str[j] && str[j] != delim[i])
			j++;

		if (str[j] == delim[i] || str[j] == '\0')
		{
			if (str[j] == delim[i])
			{
				str[j] = '\0';
				ptrtok = (char *)&str[++j];
			}
			else
			{
				ptrtok = NULL;
				tok = NULL;
			}
			return (tok);
		}
		i++;
	}

	return (tok);
}
