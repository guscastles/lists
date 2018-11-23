#include "../include/list.h"
#include <malloc.h>
#include <limits.h>

List create_list(int size) {
   int *array = malloc(size * sizeof(int));
   for (int i = 0; i < size; ++i)
      array[i] = 0;
   List new_list;
   new_list.list = array;
   new_list.size = size;

   return new_list;
}

void release_list(List list) {
   free(list.list);
   list.size = 0;
}

