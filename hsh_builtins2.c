#include "hsh.h"

/**
 * hsh_setenv - add or overwrite an env
 *
 * @data: the data struct
 *
 * Return: 1 if success, -1 if failure
 */

int hsh_setenv(data_t *data)
{
	/* char *tmp;*/
	int i = 0, j = 0, k = 0, osizenv = 0, nsizenv = 0;
	int tok1siz = _strlen(data->toks[1]), tok2siz = _strlen(data->toks[2]);

	if (!data->toks[2])
	{
		puts("setenv takes 2 parameters!");
		return (1);
	}
/*
 *	if (_getenv(name))
 *	{
 *		if (overwrite = 1)
 *			_unsetenv(name);
 *		else
 *			return (0);
 *	}
 */
	while (data->env[i] != NULL)
		i++;

	osizenv = sizeof(char *) * (i + 1);
	nsizenv = sizeof(char *) * (i + 2);
	data->env = _realloc(data->env, osizenv, nsizenv);
	data->env[i] = malloc(sizeof(char) * (tok1siz + tok2siz));

	for (j = 0; data->toks[1][j]; j++)
		data->env[i][j] = data->toks[1][j];

	data->env[i][j++] = '=';

	while (data->toks[2][k])
		data->env[i][j++] = data->toks[2][k++];

	data->env[i++][j] = '\0';

	data->env[i] = NULL;
	return (1);
}
