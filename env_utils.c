#include "hsh.h"

/**
 * _getenv - respin of getenv()
 *
 * @name: Requested key
 *
 * Return: Value of requested key
 */

char *_getenv(const char *name)
{
	extern char **environ;
	int i;
	int j;

	i = 0;
	while (environ[i] != NULL)
	{
		j = 0;
		while (environ[i][j] == name[j])
		{
			j++;
			if (environ[i][j] == '=')
			{
				j++;
				return (&environ[i][j]);
			}
		}
		i++;
	}
	return (0);
}
