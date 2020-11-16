#include "holberton.h"

/**
 * free_star
 */

void free_star(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

/**
 * main - super simple shell
 *
 * Return: always 0
 */

int main(void)
{
	char *line;
	size_t bufsize = 0;
	char *arr = NULL;
	char **args = NULL;
	int toks = 0, i = 0, j = 0;
	pid_t child_pid;
	int status = 0;

	while (1)
	{	
		status = 0;
		i = 0;
		j = 0;
		toks = 0;

		printf("$ ");
		getline(&line, &bufsize, stdin);

		while (line[i])
		{
			if (line[i] == ' ')
			{
				i++;
			}
			else
			{
				while (line[i] && line[i] != ' ')
					i++;
				toks++;
			}
		}

		args = malloc(sizeof(char *) * (toks + 1));

		*arr = strtok(line, " \n");
		while (arr != NULL)
		{
			args[j] = arr;
			j++;
			*arr = strtok(NULL, " \n");
		}

		args[j] = NULL;


		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			return (1);
		}
		if (child_pid == 0)
		{
			status = execve(args[0], args, NULL);
			perror("execve");
		}
		else
		{
			wait(&status);
		}
	}

	return (0);
}

