#define List struct arraylist

List create_list(int size);

void update_list(List list, int new_value, int position);

int element(List list, int position);

int list_size(List list);

void release_list(List list);

List add_element(List list, int value);

void no_element(List list, int position);

struct arraylist {
   int *list;
   int size;
};

