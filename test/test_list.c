#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <limits.h>
#include <malloc.h>
#include <stdio.h>
#include "list.h"

void test_create_empty_list(void) {
   List list = create_list(0);
   CU_ASSERT_EQUAL(list.size, 0);
}

void test_create_a_list(void) {
   int size = 10;
   List list = create_list(size);
   CU_ASSERT_EQUAL(list_size(list), size);
   for (int i = 0; i < size; ++i) {
      update_list(list, i + 1, i);
      CU_ASSERT_EQUAL(element_at(list, i), i + 1);
   }
}

void test_append_elements(void) {
   List list = create_list(0);
   for (long l = 0; l < 1e7; ++l)
      list = append_element(list, 77);
   CU_ASSERT_EQUAL(list_size(list), 1e7);
   CU_ASSERT_EQUAL(element_at(list, 1e6), 77);
}

void test_no_element(void) {
   List list = create_list(2);
   int position = 3;
   for (int i = 0; i < 2; ++i)
       CU_ASSERT_FALSE(element_at(list, i) == INT_MIN);
   CU_ASSERT_TRUE(element_at(list, position) == INT_MIN);
   CU_ASSERT_TRUE(element_at(list, -1) == INT_MIN);
}

void test_create_a_list_of_lists(void) {
   List *lists = malloc(3 * sizeof(List));
   lists[0] = create_list(0);
   lists[0] = append_element(lists[0], 1);
   CU_ASSERT_EQUAL(list_size(lists[0]), 1);
   free(lists);
}

