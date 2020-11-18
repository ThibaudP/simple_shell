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
	

/* CHECK FOR ALIASES THEN BUILTINS THEN IN PATH THEN FULL PATH HERE */

/* 	if (toks[0])
	{
*/		

	/* IF NOT ALIAS NOR BUILTIN, CHECK FOR COMMAND IN PATH */
	hsh_checkPATH(toks);
	

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (child_pid == 0)
	{
		status = execve(toks[0], toks, NULL);
		perror(toks[0]);
	}
	else
	{
		wait(&status);
	}

	return (1);
}

/**
 * hsh_checkPATH - checks command against all PATH folders
 *
 * @toks: array of arguments
 *
 * Return: the array of arguments (with full path of command if it exists)
 */

char **hsh_checkPATH(char **toks)
{
	char *path = NULL;
	char **paths = NULL;
	int i = 0, num_toks = 0;

	path = getenv("PATH");

	while (path[i])
	{
		if (path[i] == ':')
			i++;
		else
		{
			while (path[i] && path[i] != ':')
				i++;
			num_toks++;
		}
	}

	paths = malloc(sizeof(char *) * (num_toks + 1));
	paths[0] = strtok(path, ":");

	i = 0;
	while (paths[i] != NULL)
	{
		i++;
		paths[i] = strtok(NULL, ":");
	}

	
	return (pathexists(toks, paths));
}

/**
 * pathexists - checks if provided command exists in the PATH
 *
 * @toks: array of arguments
 * @paths: array of paths
 *
 * Return: the array of arguments
 */

char **pathexists(char **toks, char **paths)
{
	int i = 0;
	char *tmp1 = NULL, *tmp2 = NULL;
	struct stat st;

	while (paths[i])
	{
		tmp1 = _strcat(paths[i], "/");
		tmp2 = _strcat(tmp1, toks[0]);

		if (stat(tmp2, &st) == 0)
		{
			toks[0] = tmp2;
		}
		i++;
	}
	free(paths);

	return (toks);

}
