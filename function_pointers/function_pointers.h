#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h>

/**
 * print_name - prints a name using a function pointer
 * @name: name to print
 * @f: pointer to a function that prints a name
 */
void print_name(char *name, void (*f)(char *));

/**
 * array_iterator - executes a function on each element of an array
 * @array: array of integers
 * @size: size of the array
 * @action: pointer to the function to execute
 */
void array_iterator(int *array, size_t size, void (*action)(int));

/**
 * int_index - searches for an integer in an array
 * @array: array of integers
 * @size: number of elements
 * @cmp: comparison function
 *
 * Return: index or -1
 */
int int_index(int *array, int size, int (*cmp)(int));

#endif /* FUNCTION_POINTERS_H */
