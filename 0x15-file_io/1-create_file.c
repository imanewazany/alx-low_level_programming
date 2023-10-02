#include "main.h"

/**
 * create_file - creates a file
 * @filename: file's name.
 * @text_content: NULL terminated string to write to the file
 * Return: 1 if it success. -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int f;
	int c;
	int w;

	c = 0;
	if (!filename)
		return (-1);
	f = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (f == -1)
		return (-1);
	if (text_content)
	{
		while (text_content[c])
			c++;
		w = write(f, text_content, c);

		if (w == -1)
			return (-1);
	}
	close(f);
	return (1);
}
