#include "list.h"
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

void update_list(List list, int new_value, int position) {
   list.list[position] = new_value;
}


int _position_out_of_limits(int position, size_t size) {
  return position < 0 || position >= size;
}

int element(List list, int position) {
   if (_position_out_of_limits(position, list.size))
      return INT_MIN;
   return list.list[position];
}

int list_size(List list) {
   return list.size;
}

List add_element(List list, int element) {
   if (list.size + 1 > 100000000)
      return list;
   list.list = realloc(list.list, (list.size + 1) * sizeof(int));
   list.list[list.size] = element;
   list.size++;
   return list;
}

void release_list(List list) {
   free(list.list);
   list.size = 0;
}
