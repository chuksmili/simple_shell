#include "shell.h"

/**
  * remove_new_line - Removes new line chr from str
  * @str: The string
  *
  * Return: The string without a new line character
  */
char *remove_new_line(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}

	return (str);
}
