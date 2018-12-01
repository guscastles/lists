#include <malloc.h>
#include <limits.h>
#include "list.h"

int element_at(List list, int position) {
   if (OUT_OF_LIMITS(position, list.size))
      return INT_MIN;
   return list.list[position];
}

int list_size(List list) {
   return list.size;
}

