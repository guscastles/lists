#include <CUnit/Basic.h>
#include <stdio.h>
#include "list.h"

Tuple pop_list(List list) {
   List new_list = append_element(append_element(list, 4), 5);
   return pop(new_list);
}

void test_pop(void) {
   List list = create_list(0);
   Tuple last_element = pop_list(list);
   CU_ASSERT_EQUAL(last_element.element, 5);
   int size_of_list = list_size(last_element.list);
   CU_ASSERT_EQUAL(size_of_list, 1);
}

