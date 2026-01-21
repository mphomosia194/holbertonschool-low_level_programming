#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * close_fd - closes a file descriptor
 * @fd: file descriptor
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * open_source - opens source file
 * @filename: source filename
 *
 * Return: file descriptor
 */
int open_source(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * open_dest - opens destination file
 * @filename: destination filename
 * @fd_from: source file descriptor
 *
 * Return: file descriptor
 */
int open_dest(char *filename, int fd_from)
{
	int fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", filename);
		close_fd(fd_from);
		exit(99);
	}
	return (fd);
}

/**
 * copy_file - copies data between file descriptors
 * @fd_from: source fd
 * @fd_to: destination fd
 * @from: source filename
 * @to: destination filename
 */
void copy_file(int fd_from, int fd_to, char *from, char *to)
{
	ssize_t r, w;
	char buffer[BUF_SIZE];

	while ((r = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", to);
			close_fd(fd_from);
			close_fd(fd_to);
			exit(99);
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", from);
		close_fd(fd_from);
		close_fd(fd_to);
		exit(98);
	}
}

/**
 * main - copies the content of a file to another file
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO,
			"Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_source(av[1]);
	fd_to = open_dest(av[2], fd_from);
	copy_file(fd_from, fd_to, av[1], av[2]);
	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
