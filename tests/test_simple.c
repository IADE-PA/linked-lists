#include "unity/unity.h"
#include "../src/list.h"

void setUp() { }

void tearDown() { }

void test_insert_from_stack() {
    List list = list_create();
    char c1='a', c2='b', c3='c'; // reserva memória
    list_insert_last(list, &c1); // (node1)
    list_insert_last(list, &c2); // (node2)
    list_insert_last(list, &c3); // (node3)
    char *p = (char*)list_get_last(list);
    char c = *p;
    // printf("%c\n", c); // 'c'
    TEST_ASSERT_EQUAL('c', c);
    list_destroy(list, NULL);
}

void free_cenas(void * element) {
    // char* p = (char*) element;
    // free(p);
    free(element);
}

void test_insert_from_heap() {
    List list = list_create();
    char* c1 = malloc(sizeof(char));
    char* c2 = malloc(sizeof(char));
    char* c3 = malloc(sizeof(char));
    *c1 = 'a';
    *c2 = 'b';
    *c3 = 'c';
    list_insert_last(list, c1); // (node1)
    list_insert_last(list, c2); // (node2)
    list_insert_last(list, c3); // (node3)
    char *p = (char*)list_get_last(list);
    char c = *p;
    // printf("%c\n", c); // 'c'
    TEST_ASSERT_EQUAL('c', c);
    list_destroy(list, free_cenas);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_insert_from_stack);
    RUN_TEST(test_insert_from_heap);
    return UNITY_END();
}