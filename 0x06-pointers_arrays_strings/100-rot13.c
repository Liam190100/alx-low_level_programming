#include "main.h"
/**
 * rot13 - encodes a string using rot13
 * @x: input string.
 * Return: the pointer to destination
 * betty style doc for function main goes there
 * @y: input string.
 * Return: the pointer to dest.
 */
char *rot13(char *x)

char *rot13(char *y)
{
int encode = 0, i;
char alph[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char rot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
while (*(x + encode) != '\0')
{
for (i = 0; i < 52; i++)
{
if (*(x + encode) == alph[i])
{
*(x + encode) = rot13[i];
break;
}
}
encode++;
}
return (x);
}
	int count = 0, i;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	while (*(y + count) != '\0')
	{
		for (i = 0; i < 52; i++)
		{
			if (*(y + count) == alphabet[i])
			{
				*(y + count) = rot13[i];
			break;
			}
		}
		count++;
	}

	return (y);
}
