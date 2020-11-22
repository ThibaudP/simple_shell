#include "hsh.h"

/**
 * hsh_getline - gets the line
 *
 * @data: the data struct
 *
 * Return: A string containing the command to execute
 */

data_t *hsh_getline(data_t *data)
{
	size_t buf = 0;

	if ((getline(&(data->line), &buf, stdin)) == EOF)
		exit(0);
	return (data);
}

/**
 * hsh_tokens - splits the line
 *
 * @data: the data struct
 *
 * Return: char** containing all tokens in the struct
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
 * @data: the data struct
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
 * @data: the data struct
 *
 * Return: the data struct
 */

data_t *hsh_checkpath(data_t *data)
{
	char *path, *tmp, *origtok = data->toks[0];
	char **paths;
	int i = 0, j = 0, num_toks = 0, cmp1, cmp2, lentok;

	cmp1 = _strncmp(data->toks[0], "/", 1);
	cmp2 = _strncmp(data->toks[0], "./", 2);
	if (cmp1 == 0 || cmp2 == 0)
	{
		if (access(data->toks[0], X_OK) != 0)
			errcmp(data, origtok);
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
			lentok = _strlen(data->toks[0]);
			tmp = malloc(sizeof(char) * (_strlen(paths[j]) + lentok + 2));
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
	errcmp(data, origtok);
	return (data);
}

/**
 * hsh_check_builtins - checks for builtins
 *
 * @data: the data struct
 *
 * Return: 1 if success, 0 if failure
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
