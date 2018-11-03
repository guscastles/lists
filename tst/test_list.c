#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "list.h"

void test_create_list(void) {
   List list = create_list(0);
   CU_ASSERT_EQUAL(list.size, 0);
}

void test_append_element(void) {
   List list = create_list(0);
   append_element(list, 1);
   CU_ASSERT_EQUAL(element_at(list, 0), 1);
}

