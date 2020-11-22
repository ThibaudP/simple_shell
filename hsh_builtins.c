#include "hsh.h"

/**
 * hsh_check_builtins - checks for builtins
 *
 * @data: the data struct
 *
 * Return: 1 if success, 0 if failure
 */

int hsh_check_builtins(data_t *data)
{
	if (data->toks[0] == NULL)
		return (-1);

	if (_strcmp(data->toks[0], "cd") == 0)
		return (hsh_cd(data));
	if (_strcmp(data->toks[0], "help") == 0)
		return (hsh_help(data));
	if (_strcmp(data->toks[0], "exit") == 0)
		return (hsh_exit(data));
	if (_strcmp(data->toks[0], "env") == 0)
		return (hsh_env(data));
	if (_strcmp(data->toks[0], "setenv") == 0)
		return (hsh_setenv(data));
	/*
	 * if (_strcmp(data->toks[0], "unsetenv") == 0)
	 * return (hsh_unsetenv(data));
	 */
	return (0);
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
