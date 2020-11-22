#include "hsh.h"

/**
 * errcmp - compares toks[0] with value, error if match
 *
 * @data: the data struct
 * @compare: the string to compare to
 */

void errcmp(data_t *data, char *compare)
{
	char errmsg[200];
	int hist = 1;

	if (_strcmp(data->toks[0], compare) == 0)
	{
		_strcpy(errmsg, "hsh: ");
		_strcat(errmsg, _itoa(hist));
		_strcat(errmsg, " ");
		_strcat(errmsg, data->toks[0]);
		_strcat(errmsg, ": not found");

		_puts(errmsg);
		_putchar('\n');
	}
}
