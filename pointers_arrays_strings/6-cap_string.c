#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to modify
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *str)
{
	int i;
	int capitalize;

	i = 0;
	capitalize = 1;

	while (str[i] != '\0')
	{
		if (capitalize && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
			capitalize = 0;
		}
		else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			 str[i] == ',' || str[i] == ';' || str[i] == '.' ||
			 str[i] == '!' || str[i] == '?' || str[i] == '"' ||
			 str[i] == '(' || str[i] == ')' || str[i] == '{' ||
			 str[i] == '}')
		{
			capitalize = 1;
		}
		else
		{
			capitalize = 0;
		}
		i++;
	}
	return (str);
}
