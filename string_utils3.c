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
