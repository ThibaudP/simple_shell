#include "hsh.h"

/**
 * _getenv - getenv() function
 * @name: Env desired
 * Return: Env
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
				printf("%s\n", &environ[i][j]);
				return (&environ[i][j]);
			}
		}
		i++;
	}
}
