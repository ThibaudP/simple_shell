#include "hsh.h"

/**
 * free_star
 */

void free_star(char **args)
{
	int i = 1;

	while (args[i - 1])
	{
		free(args[i]);
		i++;
	}
	free(args);
}


/**
 * hsh_getline - gets the line
 */

char *hsh_getline(void)
{
	char *line = NULL;
	ssize_t buf = 0;

	getline(&line, &buf, stdin);

	return (line);
}

/**
 * hsh_tokens - splits the line
 */

char **hsh_tokens(char *line)
{
	int i = 0, j = 0, num_toks = 0;
	char **toks = NULL;
	char *tmp;
	char *delim = TOK_DELIM;

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
			num_toks++;
		}
	}

	toks = malloc(sizeof(char *) * (num_toks + 1));

	tmp = strtok(line, delim);
	while (tmp != NULL)
	{
		toks[j] = tmp;
		j++;
		tmp = strtok(NULL, delim);
	}
	toks[j] = NULL;

	return (toks);
}

/**
 * hsh_exec
 */

int hsh_exec(char **toks)
{
	pid_t child_pid;
	int status;


	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (child_pid == 0)
	{
		status = execve(toks[0], toks, NULL);
		perror("execve");
	}
	else
	{
		wait(&status);
	}
	return (1);
}


/**
 * main - super simple shell
 *
 * Return: always 0
 */

int main(void)
{
	char *line = NULL;
	char **toks = NULL;
	int status = 1;

	while (status)
	{	
		printf("$ ");
		line = hsh_getline();
		toks = hsh_tokens(line);
		status = hsh_exec(toks);
		free(line);
		free_star(toks);
	}

	return (0);
}
