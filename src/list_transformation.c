#include "list.h"
#include <malloc.h>
#include <limits.h>

#define MAX_LIST_SIZE 1e9

void update_list(List list, int new_value, int position) {
   if (!OUT_OF_LIMITS(position, list_size(list)))
      list.list[position] = new_value;
}

List append_element(List list, int element) {
   if (list.size <= MAX_LIST_SIZE) {
      list.list = realloc(list.list, (list.size + 1) * sizeof(int));
      list.list[list.size] = element;
      ++list.size;
   }
   return list;
}

