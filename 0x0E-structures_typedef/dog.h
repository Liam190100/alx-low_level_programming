#define _DOG.H_
#ifndef _DOG.H_
#include <stdio.h>
	/**
	 * struct dog - Dog character
	 * @name: First name of the dog
	 * @age: The age of the dog
	 * @owner: The owner of the dog
	 *
	 * Description: The character of the dog
	 */
	struct dog
	{
		char *name;
		float age;
		char *owner;
	};


	/**
	 * dog_t - typedef for dog character
	 */
	typedef struct dog dog_t;


	void init_dog(struct dog *d, char *name, float age, char *owner);
	void print_dog(struct dog *d);
	dog_t *new_dog(char *name, float age, char *owner);
	void free_dog(dog_t *d);
	char *_strcpy(char *dest, char *src);
	int _strlen(char *s);


	#endif

