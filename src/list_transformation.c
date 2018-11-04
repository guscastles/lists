#include "list.h"
#include <malloc.h>
#include <limits.h>

#define MAX_LIST_SIZE 1e9

int _position_out_of_limits(int position, size_t size) {
  return position < 0 || position >= size;
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

List append_element(List list, int element) {
   if (list.size <= MAX_LIST_SIZE) {
      list.list = realloc(list.list, (list.size + 1) * sizeof(int));
      list.list[list.size] = element;
      ++list.size;
   }
   return list;
}

