#include "hsh.h"

/**
 *
 * ADD HERE
 * 3 FUNCTIONS
 * THAT HANDLE THE 3 MODES OF EXECUTION
 *
 * INTERACTIVE MODE
 * NON INTERACTIVE MODE
 * FILE MODE
 *
 * AND CALL THEM FROM MAIN()
 *
 *
 *
 *
 *
 *
 *
 */

/**
 * main - super simple shell
 *
 * Return: always 0
 */

int main(void)
{
	char *line = NULL;
	char **toks = NULL;
	char *prompt = PROMPT;
	int status = 1;
	int i = 0;

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
