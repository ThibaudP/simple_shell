#include "hsh.h"

/**
 *  * _putchar - writes the character c to stdout
 *   *
 *    * @c: The character to print
 *     *
 *      * Return: On success 1.
 *       * On error, -1 is returned, and errno is set appropriately.
 *        */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *  * _strcat - concatenates two strings
 *   *
 *    * @s1: the first string
 *     * @s2: the second string
 *      *
 *       * Return: a pointer to the new string, or NULL on failure
 *        */

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
 *  * _strtok - respin of strtok()
 *   *
 *    * @str: string to split
 *     * @delim: string of delimiters
 *      *
 *       * Return: pointer to next token
 *        */

char *_strtok(char *str, char *delim)
{
	char *end = NULL;
	static char *ptrtok;

	if (str == NULL)
		str = ptrtok;

	if (*str == '\0')
	{
		ptrtok = str;
		return (NULL);
	}

	str = str + _strspn(str, delim);
	if (*str == '\0')
	{
		ptrtok = str;
		return (NULL);
	}

	end = str + strcspn(str, delim);
	if (*end == '\0')
	{
		ptrtok = end;
		return (str);
	}

	*end = '\0';
	ptrtok = end + 1;

	return (str);
}

/**
 *  * _strspn - Gets the length of a prefix substring.
 *   *
 *    * @s: string to be searched
 *     * @accept: string of accepted chars to match
 *      *
 *       * Return: the index of the last matching char
 *        */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, n = 0, m = 0;
	int j;

	for (i = 0; s[i]; i++)
	{
		m = 0;
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
			{
				n++;
				m++;
			}
		}
		if (m == 0)
			break;
	}
	return (n);
}

/**
 *  * _strcspn - Gets the length of a prefix substring NOT matching a given string
 *   *
 *    * @s: string to be searched
 *     * @reject: string of rejected chars to match
 *      *
 *       * Return: the index of the first non matching char
 *        */

unsigned int _strcspn(char *s, char *reject)
{
	unsigned int i, n = 0, m = 0;
	int j;

	for (i = 0; s[i]; i++)
	{
		m = 0;
		for (j = 0; reject[j]; j++)
		{
			if (s[i] != reject[j])
			{
				n++;
				m++;
			}
		}
		if (m == 0)
			break;
	}
	return (n);
}

