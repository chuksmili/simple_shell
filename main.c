#include "shell.h"

/**
<<<<<<< HEAD
  * main - Redirect to the Shell
  *
  * Return: Always zero.
  */
int main(void)
{
	char *line = NULL, **u_tokns = NULL;
	int w_len = 0, execFlag = 0;
	size_t line_size = 0;
	ssize_t line_len = 0;

	while (line_len >= 0)
	{
		signal(SIGINT, signal_handler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		line_len = getline(&line, &line_size, stdin);
		if (line_len == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		w_len = count_input(line);
		if (line[0] != '\n' && w_len > 0)
		{
			u_tokns = tokenize(line, " \t", w_len);
			execFlag = execBuiltInCommands(u_tokns, line);
			if (!execFlag)
			{
				u_tokns[0] = find(u_tokns[0]);
				if (u_tokns[0] && access(u_tokns[0], X_OK) == 0)
					exec(u_tokns[0], u_tokns);
				else
					perror("./hsh");
			}

			frees_tokens(u_tokns);
		}
	}

	free(line);
	return (0);
=======
* main - entry point
* @ac: arg count
* @av: arg vector
*
* Return: 0 on success, 1 on error
*/
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);

return (EXIT_SUCCESS);
>>>>>>> 08693f947ea348c0aaf63176a284b8e82bc8608e
}
