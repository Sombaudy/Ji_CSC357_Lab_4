#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkit.h"
#include "array_list.h"

void test1() {
   char *e1 = "hello";
   char *e2 = "world";

   struct Arraylist *some_array_ptr = array_list_new();
	struct Arraylist some_array = *some_array_ptr;

   array_list_add_to_end(&some_array, "hello");
	array_list_add_to_end(&some_array, "world");

   for (size_t i = 0; i < some_array.size; i++)
 	{
 		printf("%s\n", some_array.list[i]);
 	}

   checkit_string(some_array.list[0], e1);
   checkit_string(some_array.list[1], e2);
   checkit_int(some_array.size, 2);
   checkit_int(some_array.capacity, 2);

   freeArrayList(&some_array);
	free(some_array_ptr);
}

void test2() {
   struct Arraylist *some_array_ptr = array_list_new();
	struct Arraylist some_array = *some_array_ptr;

   array_list_add_to_end(&some_array, "hello");
	array_list_add_to_end(&some_array, "world");
   array_list_add_to_end(&some_array, "HI HI");
   
   checkit_string(some_array.list[0], "hello");
   checkit_string(some_array.list[1], "world");
   checkit_string(some_array.list[2], "HI HI");
   checkit_int(some_array.size, 3);
   checkit_int(some_array.capacity, 3);

   freeArrayList(&some_array);
	free(some_array_ptr);
}


int main(void) {
   test1();
   test2();
   return 0;
}
