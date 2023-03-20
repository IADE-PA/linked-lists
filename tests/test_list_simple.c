#include "unity/unity.h"
#include "../src/list.h"

void setUp() {}

void tearDown() {}

void test_list_with_stack_values() {
    List list = list_create();
    int a=1, b=2, c=3;
    list_insert_last(list, &a); // [1]
    list_insert_last(list, &b); // [1]->[2]
    list_insert_last(list, &c); // [1]->[2]->[3]

    int x = *(int*)list_get_last(list);
    // printf("%d\n", x);
    TEST_ASSERT_EQUAL(3, x);

    list_destroy(list, NULL);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_list_with_stack_values);
    UNITY_END();
}