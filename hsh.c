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
	int status = 1;
	data_t *data;
	(void)av;
	(void)env;

	signal(SIGINT, sig_ign);

	data = data_new(env);

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
			data->line = hsh_getline();
			if (data->line[0] != '\n')
			{
				data = hsh_tokens(data);
				status = hsh_exec(data);
				free(data->toks);
			}
			free(data->line);
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
		dupl_env(new, env);
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

data_t *dupl_env(data_t *data, char **env)
{
	int i = 0, j = 0;

	while (env[i])
		i++;
	data->env = malloc(sizeof(char *) * (i + 1));
	if (!data->env)
		return (NULL);

	while (env[j])
	{
		data->env[j] = _strdup(env[j]);
		j++;
	}

	data->env[j] = NULL;

	return (data);
}
