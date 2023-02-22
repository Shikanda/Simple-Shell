#include "main.h"

int _len(char *s);
char *_strdup(char *str);
void *_realloc(void *ptr, unsigned int old, unsigned int newer);
char *_strcpy(char *dest, char *src);
/**
**_strcpy - copies string pointed
*@dest: a pointer
*@src: a pointer
*Return: pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/**
*_len - gets length of string
*@s: string
*
*Return: length
*/
int _len(char *s)
{
	int length;

	length = 0;
	while (*s++)
	{
		length++;
	}
	return (length);
}

/**
*_realloc - reallocs old pinter to a newer one
*@ptr: old pointer
*@old: old size of the pointer
*@newer: new size of the pointer
*
*Return: void pointer
*/
void *_realloc(void *ptr, unsigned int old, unsigned int newer)
{
	unsigned int i;
	char *newptr;

	if (old == newer)
		return (ptr);
	if (newer == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	newptr = malloc(sizeof(char) * newer);

	if (newptr == NULL)
		return (NULL);

	if (ptr)
	{
		for (i = 0; i < old; i++)
		{
			newptr[i] = *((char *)ptr + i);
		}
	}
	free(ptr);
	return (newptr);
}

/**
*_strdup - mallocs a new str and copies new str into it
*@str: string to copy
*
*Return: pointer to the new string
*/
char *_strdup(char *str)
{
	unsigned int i;
	int count;
	char *dest;

	count = 0;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		count++;
	}

	count += 1;

	dest = malloc(count * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		dest[i] = str[i];
	}

	dest[i] = str[i];
	return (dest);
}
