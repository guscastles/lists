#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <limits.h>
#include <malloc.h>
#include <stdio.h>
#include "list.h"

struct list_object {
  List (*push)(List l, int element);
  Tuple (*pop)(List l);

} LIST;

void test_create_list_with_zero_elements(void) {
   List list = create_list(0);
   CU_ASSERT_EQUAL(list.size, 0);
}

