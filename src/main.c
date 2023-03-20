#include "list.h"

void test_list_with_stack_values() {
    List list = list_create();
    int a=1, b=2, c=3;
    list_insert_last(list, &a); // [1]
    list_insert_last(list, &b); // [1]->[2]
    list_insert_last(list, &c); // [1]->[2]->[3]

    int x = *(int*)list_get_last(list);
    printf("%d\n", x);

    list_destroy(list, NULL);
}

void free_ints(void * element) {
    free(element);
}

void test_list_with_heap_values() {
    List list = list_create();
    int* a= malloc(sizeof(int));
    int* b= malloc(sizeof(int));
    int* c= malloc(sizeof(int));
    *a = 1;
    *b = 2;
    *c = 3;
    list_insert_last(list, a); // [1]
    list_insert_last(list, b); // [1]->[2]
    list_insert_last(list, c); // [1]->[2]->[3]

    int x = *(int*)list_get_last(list);
    printf("%d\n", x);

    list_destroy(list, free_ints);
}

int main() {
    // test_list_with_stack_values();
    test_list_with_heap_values();

    return 0;
}
