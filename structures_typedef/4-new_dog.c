#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: pointer to the new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	char *name_copy;
	char *owner_copy;
	int i, len_name, len_owner;

	if (name == NULL || owner == NULL)
		return (NULL);

	len_name = 0;
	while (name[len_name])
		len_name++;

	len_owner = 0;
	while (owner[len_owner])
		len_owner++;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	name_copy = malloc(sizeof(char) * (len_name + 1));
	if (name_copy == NULL)
	{
		free(dog);
		return (NULL);
	}

	owner_copy = malloc(sizeof(char) * (len_owner + 1));
	if (owner_copy == NULL)
	{
		free(name_copy);
		free(dog);
		return (NULL);
	}

	for (i = 0; i < len_name; i++)
		name_copy[i] = name[i];
	name_copy[i] = '\0';

	for (i = 0; i < len_owner; i++)
		owner_copy[i] = owner[i];
	owner_copy[i] = '\0';

	dog->name = name_copy;
	dog->age = age;
	dog->owner = owner_copy;

	return (dog);
}
