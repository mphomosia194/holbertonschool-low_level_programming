#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content: NULL-terminated string to append
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written;
	ssize_t length = 0;

	if (filename == NULL)
		return (-1);

	/* Open file in append mode, do not create */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* If text_content is NULL, do not write anything */
	if (text_content != NULL)
	{
		while (text_content[length])
			length++;

		bytes_written = write(fd, text_content, length);
		if (bytes_written == -1 || bytes_written != length)
		{
			close(fd);
			return (-1);
		}
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}
