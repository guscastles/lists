#include <stdio.h>

int test() {
   return (void *) 0;
}


int main(void) {
   int ret = test();
   printf("%d\n", ret);
   return 0;
}
