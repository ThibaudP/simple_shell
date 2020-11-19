#include "hsh.h"

/**
 * main - simple shell
 *
 * @ac: argument count
 * @av: argument values
 * @env: environment
 *
 * Return: always 0
 */

int main(int ac, char **av, char **env)
{
	char *line = NULL;
	char **toks = NULL;
	char *prompt = PROMPT;
	int status = 1;
	int i = 0;
	(void)ac;
	(void)av;
	(void)env;
	/* NON-INTERACTIVE MODE */



	/* INTERACTIVE MODE */
	while (status)
	{
		_puts(prompt);
		line = hsh_getline();
		toks = hsh_tokens(line);
		status = hsh_exec(toks);
		free(line);
		while (toks[i])
			i++;
		free_star(toks, i);
	}

	return (0);
}
