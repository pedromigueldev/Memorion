#include "criterion/criterion.h"
#include "../src/linked_list.h"
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <string.h>

ListEnds list_ends;

void list_setup() {
    list_ends = list_create_ends();
}

void list_teardown() {
    printf("test ended\n");
}

TestSuite(list_test, .init=list_setup, .fini=list_teardown);

Test(list_test, create_ends){
    cr_expect(list_ends.end == NULL, "The creation of ends should be NULL.");
    cr_expect(list_ends.head == NULL, "The creation of ends should be NULL.");
}

Test(list_test, create_node){
    NodeT* some_node = list_create_node("teste");

    cr_expect(some_node != NULL);
    cr_expect(some_node->node != NULL, "The element should be added");
}

Test(list_test, insert_node) {
    NodeT* some_node = list_create_node("teste");
    int status = list_insert_node(&list_ends, some_node);

    cr_expect(status >= 0, "It should return 0 if successfull.");
    cr_expect(list_ends.head == some_node, "The new head should be the we're adding.");
}
