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
	int status = 1, i = 0;
	data_t *data;
	(void)av;
	(void)env;

	signal(SIGINT, sig_ign);

	data = data_new(env);

	while (i < 2)
		puts(data->env[i++]);

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

/**
 * data_new - Populates the data struct
 *
 * @line: line from getline
 * @env: environment array
 * @toks: toks from hsh_tokens
 *
 * Return: a data_t struct
 */

data_t *data_new(char **env)
{
	data_t *new = NULL;

	new = malloc(sizeof(data_t));
	if (new)
	{
		new->env = dupl_env(env);
	}

	return (new);
}

/**
 * dupl_env - Duplicates the **env
 *
 * @env: the environment
 *
 * Return: an array of strings
 */

char **dupl_env(char **env)
{
	int i = 0, j = 0;
	char **new;

	while (env[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	
	while (env[j])
	{
		new[j] = _strdup(env[j]);
		j++;
	}

	new[j] = NULL;

	return (new);
}
