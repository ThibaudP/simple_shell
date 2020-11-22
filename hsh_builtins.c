#include "hsh.h"

/**
 * hsh_setenv - add or overwrite an env
 *
 * @args: name of env
 *
 * Return: 0 if success, -1 if failure
 */

int hsh_setenv(data_t *data)
{
	/* char *tmp;*/
	int i = 0, j = 0, k = 0;

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
	data->env = _realloc(data->env, (sizeof(char *) * (i + 1)), (sizeof(char *) * (i + 2)));
	data->env[i] = malloc(sizeof(char) * (_strlen(data->toks[1]) + _strlen(data->toks[2]) + 2));

	while (data->toks[1][j])
	{
		data->env[i][j] = data->toks[1][j];
		j++;
	}
	data->env[i][j] = '=';
	j++;

	while (data->toks[2][k])
	{
		data->env[i][j] = data->toks[2][k];
		j++;
		k++;
	}
	data->env[i][j] = '\0';
	i++;
	
	data->env[i] = NULL;
	return (1);
}

/**
 * hsh_env - print environment variables
 *
 * Return: 0 if success, -1 if failure
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
 * @args: array of args
 *
 * Return: 1 if success, -1 if failure
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
 * @args: arguments to command
 *
 * Return: exit
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

	return (1);
}

/**
 * hsh_help - user help
 *
 * @args: arguments to command
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
