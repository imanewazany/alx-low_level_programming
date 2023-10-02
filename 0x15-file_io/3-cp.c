#include "main.h"

/**
 * main - copy the content of a file to another file.
 * @argc: number of arguments.
 * @argv: arguments
 * Return: 0 on sucess
 */
int main(int argc, char *argv[])
{
	int f, f2, w;
	ssize_t s;
	char buf[1024];

	s = 1024;
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	}
	f = open(argv[1], O_RDONLY);
	if (f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	f2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0664);
	if (f2 == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	while (s == 1024)
	{
		s = read(f, buf, 1024);
		if (s == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		w = write(f2, buf, s);
		if (w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
		}
	}
	if (close(f) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f), exit(100);
	}
	if (close(f2) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f2), exit(100);
	return (0);
}
