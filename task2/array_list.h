#ifndef TASK2_H
#define TASK2_H

struct Arraylist
{
	char** list;
	int capacity;
	int size;
};

void freeArrayList(struct Arraylist* array);
struct Arraylist *array_list_new();
void array_list_add_to_end(struct Arraylist *array, char *newString);


#endif
//hello