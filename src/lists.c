#include <stdio.h>
#include "../include/list.h"

int main() {
    List list = create_list(3);
    printf("Lists and the Lot, size %d\n", list_size(list));
    release_list(list);
    return 0;
}

