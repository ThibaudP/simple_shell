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
	(void)args;

/*	if (args[1] && atoi(args[1]))
		exit(atoi(args[1])); */
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

/**
 * hsh_check_builtin - checks for builtins
 *
 * @args: arguments passed
 * 
 * Return: 1 if success, -1 if failure
 */

int hsh_check_builtin(char **args)
{
	int (*builtin_func[]) (char **) = {&hsh_cd, &hsh_help, &hsh_exit};
	char *builtin_str[] = {"cd", "help", "exit"};
	int i;

	if (args[0] == NULL)
	{
		return (-1);
	}
	i = 0;
	while (i < 2)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			(*builtin_func[i])(args);
			return (1);
		}
		i++;
	}
	return (-1);
}
