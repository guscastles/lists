#include <malloc.h>
#include <limits.h>
#include "list.h"

Tuple test_pop(List list) {
   List new_list = add_element(add_element(list, 4), 5);
   return pop(new_list);
}

int main(void){
   List list = create_list(0);
   Tuple last_element = test_pop(list);
   printf("Last element should be 5: %s\n", last_element.element == 5 ? "True" : "False");
   printf("List size should be 1: %s\n", list_size(last_element.list) == 1 ? "True" : "False");
   printf("%d\n", list_size(last_element.list));
   
   return 0;
}
