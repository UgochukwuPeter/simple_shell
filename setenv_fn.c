#include "main.h"
/**
 * setenv_fn - a function changes the enviroment
 * @d: a string contains enviroment variable and desired to change value
 * @h: an unused var at this time
 * Return: returns NULL
 */
char *setenv_fn(char *d, __attribute__((unused)) list_t *h)
{
	char *value, *var;
	int ret;

	var = strtok(d, " ");
	value = strtok(NULL, " ");
	ret = setenv(var, value, 1);
	if (ret == -1)
		perror("access denied");
	return (NULL);
}
