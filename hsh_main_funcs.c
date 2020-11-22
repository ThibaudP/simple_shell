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

	if ((getline(&line, &buf, stdin)) == EOF)
		exit(0);
	return (line);
}

/**
 * hsh_tokens - splits the line
 *
 * @data: the command line typed by the user
 *
 * Return: an array of strings containing all tokens
 */

data_t *hsh_tokens(data_t *data)
{
	int i = 0, num_toks = 0;
	char *delim = TOK_DELIM, *tmp;

	num_toks = wordcnt(data->line, ' ');

	data->toks = malloc(sizeof(char *) * (num_toks + 1));

	tmp = _strtok(data->line, delim);
	while (tmp != NULL)
	{
		data->toks[i++] = tmp;
		tmp = _strtok(NULL, delim);
	}
	data->toks[i] = NULL;
	return (data);
}

/**
 * hsh_exec - executes a command from its tokens
 *
 * @toks: the array of argv tokens
 *
 * Return: a status code
 */

int hsh_exec(data_t *data)
{
	pid_t child_pid;
	int status;
	char *tmp = data->toks[0];

	if (hsh_check_builtins(data))
		return (1);

	hsh_checkpath(data);

	if (data->toks[0] == NULL)
		return (1);

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (child_pid == 0)
	{
		status = execve(data->toks[0], data->toks, NULL);
		perror(data->toks[0]);
		_exit(status);
	}
	else
	{
		wait(&status);
	}

	if (_strcmp(data->toks[0], tmp) != 0)
		free(data->toks[0]);

	return (1);
}
/**
 * hsh_checkpath - checks command against all PATH folders
 *
 * @toks: array of arguments
 *
 * Return: the array of arguments (with full path of command if it exists)
 */

data_t *hsh_checkpath(data_t *data)
{
	char *path, *tmp, *origtok = data->toks[0], error[200];
	char **paths;
	int i = 0, j = 0, num_toks = 0;

	if (_strncmp(data->toks[0], "/", 1) == 0 || _strncmp(data->toks[0], "./", 2) == 0)
	{
		if (access(data->toks[0], X_OK) == 0)
			return (data);
	}
	else
	{
		path = _strdup(_getenv(data, "PATH"));
		num_toks = wordcnt(path, ':');
		paths = malloc(sizeof(char *) * (num_toks + 1));
		while (i < (num_toks + 1))
		{
			if (i == 0)
				paths[i++] = _strtok(path, ":");
			else
				paths[i++] = _strtok(NULL, ":");
		}
		while (paths[j])
		{
			tmp = malloc(sizeof(char) * (_strlen(paths[j]) + _strlen(data->toks[0]) + 2));
			_strcat(_strcat(_strcpy(tmp, paths[j++]), "/"), data->toks[0]);
			if (access(tmp, X_OK) == 0)
			{
				data->toks[0] = _strdup(tmp);
				free(tmp);
				break;
			}
			free(tmp);
		}
		free(path);
		free(paths);
	}
	if (data->toks[0] == origtok)
	{
		puts(_strcat(_strcat(_strcpy(error, "hsh: 1: "), data->toks[0]), ": not found"));
		data->toks[0] = NULL;
	}
	return (data);
}

/**
 * hsh_check_builtins - checks for builtins
 *
 * @args: arguments passed
 *
 * Return: 1 if success, -1 if failure
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
