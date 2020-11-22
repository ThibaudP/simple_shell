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
	return (0);
}
