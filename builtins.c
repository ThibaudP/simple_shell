#include "hsh.h"

/**
 * cd builtin
 */

int hsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		printf("expect arg after cd");	
		return (1);
	}
	else
	{
		if (chdir(args[1] != 0)
			perror("wrong directory or smthg like that");
	}
	return (1);
}

/**
 * exit builtin
 */

int hsh_exit(char **args)
{
	return (0);
}

/**
 * help builtin
 */

int hsh_help(char **args)
{
	int i;
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

int hsh_check_builtin(char **args)
{
	char *builtin_str[] = {"cd", "help", "exit"};
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
}
