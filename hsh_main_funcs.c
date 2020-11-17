#include "hsh.h"

/**
 * hsh_getline - gets the line
 *
 * Return: A string containing the command to execute
 */

char *hsh_getline(void)
{
	char *line = NULL;
	size_t buf = BUFSIZE;

	getline(&line, &buf, stdin);

	return (line);
}

/**
 * hsh_tokens - splits the line
 *
 * @line: the command line typed by the user
 *
 * Return: an array of strings containing all tokens
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
 * hsh_exec - executes a command from its tokens
 *
 * @toks: the array of argv tokens
 *
 * Return: a status code
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
