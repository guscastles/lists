typedef struct arraylist {
   int *list;
   int size;
} List;

typedef struct tuple {
     List list;
     int element;
} Tuple;

List create_list(int size);

void update_list(List list, int new_value, int position);

int element_at(List list, int position);

int list_size(List list);

void release_list(List list);

List append_element(List list, int value);

List remove_element(List list, int position);

Tuple pop(List list);
 
