#include "hsh.h"

/**
 * _strchr - locates a character in a string
 *
 * @s: the string to look inside
 * @c: the character to find
 *
 * Return: a pointer to the first occurence of c in s, or NULL if not found
 */

char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	if (s[i] == c)
		return (s + i);
	return (NULL);
}

/**
 * wordcnt - counts words in string separated by delim
 *
 * @str: pointer to string
 * @delim: delimiter to check against
 *
 * Return: the number of words in that string
 */

int wordcnt(char *str, char delim)
{
	int i = 0, cnt = 0;

	while (str[i])
	{
		if (str[i] == delim)
			i++;
		else
		{
			while (str[i] && str[i] != delim)
				i++;
			cnt++;
		}
	}
	return (cnt);
}

/**
 * sig_ign - handler for SIGINT
 *
 * @sig_num: signal to handle
 */

void sig_ign(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_putchar('\n');
		_puts(PROMPT);
	}
}
