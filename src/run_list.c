#include "run_list.h"

int _main(void){
   list_play();
   return 0;
}

   void list_play() {
      List list = create_a_list(10);
      list = add_elements(list);
      no_element(list, -1);
      release_list(list);
   }

      List create_a_list(int size) {
         List list = create_list(size);
         printf("List size: %d\n", list_size(list));
         for (int i = 0; i < size; ++i) {
            update_list(list, i + 1, i);
            printf("Element %d: %d\n", i, element(list, i));
         }

         return list;
      }

      List add_elements(List list) {
         List more_elements = list;
         for (long l = 0; l < 1e7; ++l)
            more_elements = add_element(more_elements, 77);
         printf("List size: %d\nElement %0.f: %d\n", list_size(more_elements), 1e7, element(more_elements, 1e6));

         return more_elements;
      }

      void no_element(List list, int position) {
	 int elem[2];
	 for (int i = 0; i < 2; ++i) {
	    elem[i] = element(list, position + i);
	    char *str = elem[i] == INT_MIN ? "does not exist in position\0" : "is in position\0";  
	    printf("Element %d %s %d\n", elem[i], str, position + i);
	 }
      }

