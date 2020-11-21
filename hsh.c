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
	(void)ac;
	(void)av;
	(void)env;
	/* NON-INTERACTIVE MODE */



	/* INTERACTIVE MODE */
	signal(SIGINT, SIG_IGN);
	while (status)
	{
		_puts(prompt);
		line = hsh_getline();
		if (line[0] != '\n')
		{
			toks = hsh_tokens(line);
			status = hsh_exec(toks);
			free(toks);
		}
		free(line);
	}

	return (0);
}
