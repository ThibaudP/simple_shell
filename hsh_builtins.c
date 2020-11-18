#include "hsh.h"

/**
 * hsh_cd - changes directory
 *
 * @args: array of args
 *
 * Return: status code
 */

int hsh_cd(char **args)
{
	if (!args[1])
	{
		chdir("~");
		return (0);
	}
	else
	{
		if (chdir(args[1]) == -1)
			perror("cd");
		return (0);
	}
	return (-1);
}

/**
 * hsh_exit - Exits the shell
 *
 * @args: arguments to command
 */

void hsh_exit(char **args)
{
	(void)args;

/*	if (args[1] && atoi(args[1]))
		exit(atoi(args[1])); */
	exit(0);
}

/**
 * hsh_help - user help
 *
 * @args: arguments to command
 *
 * Return: status code
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

/**
 * check/exec_builtins
 */
/*
int hsh_check_builtin(char **args)
{
	int *builtin_func[] = {&hsh_cd, &hsh_help, &hsh_exit};
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}
	i = 0;
	while (i < 2)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return (*builtin_func[i]);
		}
		i++;
	}
	return (hsh_exec(args));
} */
