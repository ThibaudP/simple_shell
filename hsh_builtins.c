#include "hsh.h"

/**
 * hsh_setenv - add or overwrite an env
 *
 * @args: name of env
 *
 * Return: 0 if success, -1 if failure
 */

int hsh_setenv(char **args)
{
	extern char **environ;
	/* char *tmp;*/
	int i;
	int j;
	int k;

/*
 *	if (_getenv(name))
 *	{
 *		if (overwrite = 1)
 *			_unsetenv(name);
 *		else
 *			return (0);
 *	}
 */
	i = 0;
	while (environ[i] != NULL)
	{
		i++;
	}
	environ[i] = malloc(_strlen(args[1]) + _strlen(args[2]) + 2);
	j = 0;
	while (args[1])
	{
		environ[i][j] = args[1][j];
		j++;
	}
	environ[i][j] = '=';
	j++;
	k = 0;
	while (args[2])
	{
		environ[i][j++] = args[2][k++];
	}
	environ[i][j] = '\0';
	i++;
	environ[i] = NULL;
	return (0);
}

/**
 * hsh_env - print environment variables
 *
 * Return: 0 if success, -1 if failure
 */

int hsh_env(void)
{
	extern char **environ;
	int i;

	i = 0;
	while (environ[i])
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
	return (0);
}

/**
 * hsh_cd - changes directory
 *
 * @args: array of args
 *
 * Return: 1 if success, -1 if failure
 */

int hsh_cd(char **args)
{
	if (!args[1])
	{
		chdir("~");
		return (1);
	}
	else
	{
		if (chdir(args[1]) == -1)
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

int hsh_exit(char **args)
{
	int i = 0;

	if (args[1])
		i = _atoi(args[1]);
	free(args);
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

int hsh_help(char **args)
{
	int i;
	char *builtin_str[] = {"cd", "help", "exit"};
	(void)args;

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
