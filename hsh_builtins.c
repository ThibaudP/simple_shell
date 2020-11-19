#include "hsh.h"

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
	int i;


	if (args[1])
	{
		i = atoi(args[1]);
		exit(i);
	}
	else
		exit(0);

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
