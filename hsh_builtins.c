#include "hsh.h"

/**
 * hsh_setenv - add or overwrite an env
 *
 * @data: the data struct
 *
 * Return: 1 if success, -1 if failure
 */

int hsh_setenv(data_t *data)
{
	/* char *tmp;*/
	int i = 0, j = 0, k = 0, osizenv = 0, nsizenv = 0;
	int tok1siz = _strlen(data->toks[1]), tok2siz = _strlen(data->toks[2]);

	if (!data->toks[2])
	{
		puts("setenv takes 2 parameters!");
		return (1);
	}
/*
 *	if (_getenv(name))
 *	{
 *		if (overwrite = 1)
 *			_unsetenv(name);
 *		else
 *			return (0);
 *	}
 */
	while (data->env[i] != NULL)
		i++;

	osizenv = sizeof(char *) * (i + 1);
	nsizenv = sizeof(char *) * (i + 2);
	data->env = _realloc(data->env, osizenv, nsizenv);
	data->env[i] = malloc(sizeof(char) * (tok1siz + tok2siz));

	for (j = 0; data->toks[1][j]; j++)
		data->env[i][j] = data->toks[1][j];

	data->env[i][j++] = '=';

	while (data->toks[2][k])
		data->env[i][j++] = data->toks[2][k++];

	data->env[i++][j] = '\0';

	data->env[i] = NULL;
	return (1);
}

/**
 * hsh_env - print environment variables
 *
 * @data: the data struct
 *
 * Return: Always 1
 */

int hsh_env(data_t *data)
{
	int i;

	i = 0;
	while (data->env[i])
	{
		_puts(data->env[i]);
		_putchar('\n');
		i++;
	}
	return (1);
}

/**
 * hsh_cd - changes directory
 *
 * @data: the data struct
 *
 * Return: 1 if success, -1 if folder doesn't exist
 */

int hsh_cd(data_t *data)
{
	if (!data->toks[1])
	{
		chdir("~");
		return (1);
	}
	else
	{
		if (chdir(data->toks[1]) == -1)
			perror("cd");
		return (1);
	}
	return (-1);
}

/**
 * hsh_exit - Exits the shell
 *
 * @data: the data struct
 *
 * Return: -1 if failure
 */

int hsh_exit(data_t *data)
{
	int i = 0, j = 0;

	if (data->toks[1])
		i = _atoi(data->toks[1]);
	free(data->toks);

	while (data->env[j])
		j++;

	free_star(data->env, j);
	free(data->line);
	free(data);

	_exit(i);

	return (-1);
}

/**
 * hsh_help - user help
 *
 * @data: the data struct
 *
 * Return: 1 if success, -1 if failure
 */

int hsh_help(data_t *data)
{
	int i;
	char *builtin_str[] = {"cd", "help", "exit"};
	(void)data;

	printf("Usage : program name + argument + enter\n");
	printf("Here are builtins :\n");
	i = 0;
	while (i < 2)
	{
		printf("%s\n", builtin_str[i]);
		i++;
	}
	return (1);
}
