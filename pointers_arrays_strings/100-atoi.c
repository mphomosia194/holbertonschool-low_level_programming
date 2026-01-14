#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: integer value
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int result = 0;

	/* Handle signs */
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign = -sign;
		else if (s[i] >= '0' && s[i] <= '9')
			break;
		i++;
	}

	/* Convert digits */
	while (s[i] >= '0' && s[i] <= '9')
	{
		/* Build result as negative to avoid overflow */
		result = result * 10 - (s[i] - '0');
		i++;
	}

	if (sign < 0)
		return (result);

	return (-result);
}
