#include "main.h"
/**
 * change_dir - a function changes the working directory
 * @d: a directory name desired to change
 * @h: a unsied head pointer
 * Return: returns the path to the desired dir, or d the supplied string
 */
char *change_dir(char *d, __attribute__((unused)) list_t *h)
{
	char *value, *old_dir;

	old_dir = _getcwd();
	if (old_dir == NULL)
		return (NULL);
	if (d[0] == '\0' || d == NULL)
	{
		value = getenv("HOME");
		ch_dir(old_dir, value, 0);
		return (value);
	}
	if ((_strcmp(d, "~") == 0) || (_strcmp(d, "$HOME") == 0))
	{
		value = getenv("HOME");
		ch_dir(old_dir, value, 0);
		return (value);
	}
	if (_strcmp(d, "-") == 0)
	{
		value = getenv("OLDPWD");
		ch_dir(old_dir, value, 0);
		return (value);
	}
	if (ch_dir(old_dir, d, 1) == 0)
	{
		value = getenv("PWD");
		return (value);
	}
	value = getenv("PWD");
	write(1, d, strlen(d));
	write(1, ":no such file or directory\n", 27);
	return (value);
}
