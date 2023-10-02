#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: file's name
 * @letters: the numbers of letters it should read and print.
 * Return: the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *pf;
	int f, rf;

	if (!filename)
		return (0);
	pf = malloc(sizeof(char) * letters);
	if (!pf)
		return (0);
	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	rf = read(f, pf, letters);
	write(STDOUT_FILENO, pf, rf);
	close(f);
	free(pf);
	return (rf);
}
