#define DOG_H
#ifndef DOG_H
#include <stdio.h>
	/**
	 * struct dog - a dog in the structure
	 * @name: First name
	 * @age: Second name
	 * @owner: Third name
	 *
	 * Description: Discribe the structure 
	 */
	struct dog
	{
		char *name;
		float age;
		char *owner;
	};


	/**
	 * dog_t - typedef for struct dog
	 */
	typedef struct dog dog_t;


	void init_dog(struct dog *d, char *name, float age, char *owner);
	void print_dog(struct dog *d);
	dog_t *new_dog(char *name, float age, char *owner);
	void free_dog(dog_t *d);
	char *_strcpy(char *dest, char *src);
	int _strlen(char *s);


	#endif

