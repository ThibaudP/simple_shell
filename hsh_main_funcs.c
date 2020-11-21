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
 * @line: the command line typed by the user
 *
 * Return: an array of strings containing all tokens
 */

char **hsh_tokens(char *line)
{
	int i = 0, num_toks = 0;
	char **toks = NULL;
	char *delim = TOK_DELIM, *tmp;

	num_toks = wordcnt(line, ' ');

	toks = malloc(sizeof(char *) * (num_toks + 1));

	tmp = _strtok(line, delim);
	while (tmp != NULL)
	{
		toks[i++] = tmp;
		tmp = _strtok(NULL, delim);
	}
	toks[i] = NULL;
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
	char *tmp = toks[0];

	if (hsh_check_builtins(toks))
		return (1);

	hsh_checkpath(toks);

	if (toks[0] == NULL)
		return (1);

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
		_exit(status);
	}
	else
	{
		wait(&status);
	}

	if (_strcmp(toks[0], tmp) != 0)
		free(toks[0]);

	return (1);
}
/**
 * hsh_checkpath - checks command against all PATH folders
 *
 * @toks: array of arguments
 *
 * Return: the array of arguments (with full path of command if it exists)
 */

char **hsh_checkpath(char **toks)
{
	char *path, *tmp, *origtok = toks[0], error[200];
	char **paths;
	int i = 0, j = 0, num_toks = 0;

	if (_strncmp(toks[0], "/", 1) == 0 || _strncmp(toks[0], "./", 2) == 0)
	{
		if (access(toks[0], X_OK) == 0)
			return (toks);
	}
	else
	{
		path = _strdup(_getenv("PATH"));
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
			tmp = malloc(sizeof(char) * (_strlen(paths[j]) + _strlen(toks[0]) + 2));
			_strcat(_strcat(_strcpy(tmp, paths[j++]), "/"), toks[0]);
			if (access(tmp, X_OK) == 0)
			{
				toks[0] = _strdup(tmp);
				free(tmp);
				break;
			}
			free(tmp);
		}
		free(path);
		free(paths);
	}
	if (toks[0] == origtok)
	{
		puts(_strcat(_strcat(_strcpy(error, "hsh: 1: "), toks[0]), ": not found"));
		toks[0] = NULL;
	}
	return (toks);
}

/**
 * hsh_check_builtins - checks for builtins
 *
 * @args: arguments passed
 *
 * Return: 1 if success, -1 if failure
 */

int hsh_check_builtins(char **args)
{
	if (args[0] == NULL)
		return (-1);

	if (_strcmp(args[0], "cd") == 0)
		return (hsh_cd(args));
	if (_strcmp(args[0], "help") == 0)
		return (hsh_help(args));
	if (_strcmp(args[0], "exit") == 0)
		return (hsh_exit(args));
	if (_strcmp(args[0], "env") == 0)
		return (hsh_env());
	if (_strcmp(args[0], "setenv") == 0)
		return (hsh_setenv(args));
	/*
	 * if (_strcmp(args[0], "unsetenv") == 0)
	 * return (hsh_unsetenv(args));
	 */
	return (0);
}
