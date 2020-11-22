#include "hsh.h"

/**
 * _getenv - respin of getenv()
 *
 * @data: the data struct
 * @name: Requested key
 *
 * Return: Value of requested key
 */

char *_getenv(data_t *data, char *name)
{
	int i = 0, j = 0;

	while (data->env[i] != NULL)
	{
		while (data->env[i][j] == name[j])
		{
			j++;
			if (data->env[i][j] == '=')
			{
				j++;
				return (&data->env[i][j]);
			}
		}
		i++;
	}
	return (NULL);
}

/**
 * _setenv - sets an env variable
 *
 * @data: the data struct
 * @name: name of the variable
 * @value: value of the variable
 *
 * Return: Always 0
 */

int _setenv(data_t *data, char *name, char *value)
{
	int i = 0, osizenv = 0, nsizenv = 0;
	int tok1siz = _strlen(name), tok2siz = _strlen(value);

	if (name == NULL || value == NULL)
	{
		puts("setenv takes 2 parameters!");
		return (1);
	}

	if (_getenv(data, name))
	{
		_unsetenv(data, name);
	}

	while (data->env[i] != NULL)
		i++;

	osizenv = sizeof(char *) * (i + 1);
	nsizenv = sizeof(char *) * (i + 2);
	data->env = _realloc(data->env, osizenv, nsizenv);
	data->env[i] = malloc(sizeof(char) * (tok1siz + tok2siz + 2));

	_strcpy(data->env[i], name);
	_strcat(data->env[i], "=");
	_strcat(data->env[i], value);

	i++;
	data->env[i] = NULL;
	return (1);
}

/**
 * _unsetenv - unsets an environment variable
 *
 * @data: the data struct
 * @name: name of varible
 */

int _unsetenv(data_t *data, char *name)
{
	int i = 0, j = 0, oldS, newS;

	if (!name)
	{
		puts("No argument provided.");
		return (0);
	}

	while (data->env[i])
		i++;


	while (_strncmp(data->env[j], name, _strlen(name)) != 0)
		j++;	if (j == i)
		{
			_puts("env variable not found\n");
			return (1);
		}

	free(data->env[j]);

	while (j < i)
	{
		data->env[j] = data->env[j + 1];
		j++;
	}

	oldS = sizeof(char *) * (i + 2);
	newS = sizeof(char *) * (i + 1);
	data->env = _realloc(data->env, oldS, newS);

	return (1);
}

