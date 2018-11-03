#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <limits.h>
#include "list.h"

void test_create_empty_list(void) {
   List list = create_list(0);
   CU_ASSERT_EQUAL(list.size, 0);
}

void test_append_element(void) {
   List list = create_list(0);
   append_element(list, 1);
   CU_ASSERT_EQUAL(element_at(list, 0), 1);
}

void test_create_a_list() {
   int size = 10;
   List list = create_list(size);
   CU_ASSERT_EQUAL(list_size(list), size);
   for (int i = 0; i < size; ++i) {
      update_list(list, i + 1, i);
      CU_ASSERT_EQUAL(element_at(list, i), i + 1);
   }
}

List add_elements(List list) {
   List more_elements = list;
   for (long l = 0; l < 1e7; ++l)
      more_elements = add_element(more_elements, 77);
   printf("List size: %d\nElement %0.f: %d\n", list_size(more_elements), 1e7, element_at(more_elements, 1e6));

   return more_elements;
}

void no_element(List list, int position) {
   int elem[2];
   for (int i = 0; i < 2; ++i) {
       elem[i] = element_at(list, position + i);
       char *str = elem[i] == INT_MIN ? "does not exist in position\0" : "is in position\0";  
       printf("Element %d %s %d\n", elem[i], str, position + i);
   }
}

