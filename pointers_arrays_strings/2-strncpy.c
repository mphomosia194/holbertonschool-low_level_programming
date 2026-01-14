#include "main.h"

/**
 * _strncpy - copies a string using at most n bytes
 * @dest: destination buffer
 * @src: source string
 * @n: number of bytes to copy
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	/* copy characters from src to dest */
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	/* pad with null bytes if src is shorter than n */
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
