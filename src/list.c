#include "list.h"
#include <malloc.h>
#include <limits.h>

#define MAX_LIST_SIZE 1e9

int _position_out_of_limits(int position, size_t size) {
  return position < 0 || position >= size;
}

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
   if (!_position_out_of_limits(position, list_size(list)))
      list.list[position] = new_value;
}

int element_at(List list, int position) {
   if (_position_out_of_limits(position, list.size))
      return INT_MIN;
   return list.list[position];
}

int list_size(List list) {
   return list.size;
}

List add_element(List list, int element) {
   if (list.size + 1 > MAX_LIST_SIZE)
      return list;
   list.list = realloc(list.list, (list.size + 1) * sizeof(int));
   list.list[list.size] = element;
   ++list.size;
   return list;
}

void append_element(List list, int element) {
   if (list.size < MAX_LIST_SIZE) {
      list.list = realloc(list.list, (list.size + 1) * sizeof(int));
      list.list[list.size] = element;
      ++list.size;
   }
}

void release_list(List list) {
   free(list.list);
   list.size = 0;
}

List remove_element(List list, int position) {
   int current_size = list_size(list);
   List new_list = create_list(current_size - 1);
   for (int i = 0, pos = 0; i < current_size; ++i)
      if (i != pos) {
         update_list(new_list, element_at(list, i), pos);
         ++pos;
      }
   release_list(list);
   return new_list;
}

Tuple pop(List list) {
   int size = list_size(list);
   Tuple tuple;
   if (size == 0) {
      tuple.list = list;
      tuple.element = INT_MIN;
      return tuple;
   }
   int position = size - 1;
   int last_element = element_at(list, position);
   tuple.list = remove_element(list, position);
   tuple.element = last_element;
   return tuple;
}

