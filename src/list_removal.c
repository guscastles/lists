#include <malloc.h>
#include <limits.h>
#include "list.h"

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

