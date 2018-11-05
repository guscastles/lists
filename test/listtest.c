#include <stdio.h>
#include <list.h>

int main(int argc, char *argv) {
   int list_size = 0;
   if (argc > 0)
      list_size = (int) argv[0];
   List list = create_list(list_size);
   update_list(list, 77, 0);
   printf("Static libray liblist.a%s installed\n", element_at(list, 0) == 77 ? "" : " not");
   return 0;
}
