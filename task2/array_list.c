#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_list.h"

// struct Arraylist
// {
// 	char** list;
// 	int capacity;
// 	int size;
// };

void freeArrayList(struct Arraylist* array)
{
	// Free allocated memory for strings
	for (size_t i = 0; i < array->size; i++)
	{
		printf("free: %s\n", array->list[i]);
		free(array->list[i]);
	}
	
	free(array->list);
}

struct Arraylist *array_list_new()
{
	struct Arraylist *ptr = (struct Arraylist *)malloc(sizeof(struct Arraylist));
	
	if (ptr == NULL)
	{
		printf("Memory allocation for Arraylist failed. \n");
		exit(1);
	}
	
	ptr->list = NULL;
	ptr->capacity = 0;
	ptr->size = 0;
	
	return ptr;
}

void array_list_add_to_end(struct Arraylist *array, char *newString)
{
	// Reallocate memory for the array of pointers
	char **temp_list_ptr = realloc(array->list, (array->size + 1) * sizeof(char *));

	// Check if realloc was successful
	if (temp_list_ptr == NULL)
	{
		printf("Error: Memory allocation failed. Unable to add string.\n");
		freeArrayList(array);
		exit(1);
	}
	array->list = temp_list_ptr;

	// Allocate memory for the new string and copy it
	array->list[array->size] = (char *)malloc((strlen(newString) + 1) * sizeof(char *));
	if(array->list[array->size] == NULL)
	{
		printf("Error: Memory allocation failed. Unable to add string.\n");
		freeArrayList(array);
		exit(1);
	}

	strcpy(array->list[array->size], newString);

	// Increment the size of the array and change the capacity
	array->size++;
	array->capacity = array->size;
}

// int main(void)
// {
// 	struct Arraylist *some_array_ptr = array_list_new();
// 	struct Arraylist some_array = *some_array_ptr;
	
// 	array_list_add_to_end(&some_array, "hello");
// 	array_list_add_to_end(&some_array, "world");
	
// 	for (size_t i = 0; i < some_array.size; i++)
// 	{
// 		printf("%s\n", some_array.list[i]);
// 	}
	
// 	freeArrayList(&some_array);
// 	free(some_array_ptr);
	
// 	return 0;
// }
