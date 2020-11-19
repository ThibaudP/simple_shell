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
 *  * hsh_tokens - splits the line
 *   *
 *    * @line: the command line typed by the user
 *     *
 *      * Return: an array of strings containing all tokens
 *       */

char **hsh_tokens(char *line)
{
	int i = 0, j = 0, num_toks = 0;
	char **toks = NULL;
	char *delim = TOK_DELIM, *tmp;

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

	tmp = _strtok(line, delim);
	while (tmp != NULL)
	{
		toks[j++] = tmp;
		tmp = _strtok(NULL, delim);
	}
	toks[j] = NULL;

	return (toks);
}

/**
 *  * hsh_exec - executes a command from its tokens
 *   *
 *    * @toks: the array of argv tokens
 *     *
 *      * Return: a status code
 *       */

int hsh_exec(char **toks)
{
	pid_t child_pid;
	int status;

	/* CHECK FOR ALIASES THEN BUILTINS THEN IN PATH THEN FULL PATH HERE */
<<<<<<< HEAD
	
=======

>>>>>>> ee5d37087e1c4073300e1357f3758083f531facc
	if (hsh_check_builtins(toks) == 1)
		return (1);

	/* IF NOT ALIAS NOR BUILTIN, CHECK FOR COMMAND IN PATH */
	hsh_checkpath(toks);

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
<<<<<<< HEAD
 * hsh_checkpath - checks command against all PATH folders
 *
 * @toks: array of arguments
 *
 * Return: the array of arguments (with full path of command if it exists)
 */

char **hsh_checkpath(char **toks)
{
	char *path = NULL, *origpath = NULL, *tmp = NULL;
	char **paths = NULL;
=======
 *  * hsh_checkpath - checks command against all PATH folders
 *   *
 *    * @toks: array of arguments
 *     *
 *      * Return: the array of arguments (with full path of command if it exists)
 *       */

char **hsh_checkpath(char **toks)
{
	char *path, *origpath, *tmp;
	char **paths;
>>>>>>> ee5d37087e1c4073300e1357f3758083f531facc
	int i = 0, j = 0, k = 0, num_toks = 0;

	origpath = _getenv("PATH");
	path = _strdup(origpath);

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
	while (j < (num_toks - 1))
	{
		if (j == 0)
			paths[j++] = _strtok(path, ":");
		else
			paths[j++] = _strtok(NULL, ":");
	}

	while (paths[k])
	{
		tmp = _strdup(paths[k++]);
		tmp = _strcat(tmp, "/");
		tmp = _strcat(tmp, toks[0]);
		if (access(tmp, X_OK) == 0)
			toks[0] = _strdup(tmp);
	}
	free(tmp);
	free(path);
	free(paths);

	return (toks);
}

/**
<<<<<<< HEAD
 * hsh_check_builtins - checks for builtins
 *
 * @args: arguments passed
 *
 * Return: 1 if success, -1 if failure
 */
=======
 *  * hsh_check_builtins - checks for builtins
 *   *
 *    * @args: arguments passed
 *     *
 *      * Return: 1 if success, -1 if failure
 *       */
>>>>>>> ee5d37087e1c4073300e1357f3758083f531facc

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
<<<<<<< HEAD
/*	if (_strcmp(args[0], "env") == 0)
		return (hsh_env(args));
	if (_strcmp(args[0], "setenv") == 0)
		return (hsh_setenv(args));
	if (_strcmp(args[0], "unsetenv") == 0)
		return (hsh_unsetenv(args));
*/
=======
	/*	if (_strcmp(args[0], "env") == 0)
	 *			return (hsh_env(args));
	 *				if (_strcmp(args[0], "setenv") == 0)
	 *						return (hsh_setenv(args));
	 *							if (_strcmp(args[0], "unsetenv") == 0)
	 *									return (hsh_unsetenv(args));
	 *									*/
>>>>>>> ee5d37087e1c4073300e1357f3758083f531facc
	return (0);
}
