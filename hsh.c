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
	int status = 1;
	(void)av;
	(void)env;

	signal(SIGINT, sig_ign);

	if (ac > 1)
	{
		/*filemode*/
	}
	else
	{
		while (status)
		{
			if (isatty(STDIN_FILENO))
					_puts(PROMPT);
			line = hsh_getline();
			if (line[0] != '\n')
			{
				toks = hsh_tokens(line);
				status = hsh_exec(toks);
				free(toks);
			}
			free(line);
		}
	}

	return (0);
}

