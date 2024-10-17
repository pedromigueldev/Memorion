#include <criterion/criterion.h>
#include "../src/linked_list.h"
#include <criterion/internal/test.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ListEnds list_ends;

void list_setup() {
    printf("\033[33mSetting up heads and tails\033[0m\n");
    list_ends = list_create_ends();
}

void list_teardown() {;
}

TestSuite(list_test, .init=list_setup, .fini=list_teardown);

Test(list_test, create_ends){
    cr_expect(list_ends.end == NULL, "The creation of ends should be NULL.");
    cr_expect(list_ends.head == NULL, "The creation of ends should be NULL.");
}

Test(list_test, create_node){
    NodeT* some_node = list_create_node(L_STRING_T, "teste");

    cr_expect(some_node != NULL, "The creation errord due to type checking error.");
    cr_expect(some_node->node != NULL, "The element should be added");

    free(some_node);
}

Test(list_test, insert_node) {
    NodeT* some_node = list_create_node(L_STRING_T, "teste");
    list_insert_node(&list_ends, some_node);

    cr_expect(list_ends.head == some_node, "The new head should be the we're adding.");

    list_remove_node(&list_ends, some_node);
    cr_expect(list_ends.head == NULL);
    cr_expect(list_ends.end == NULL);
}

Test(list_test, remove_node) {
    NodeT* some_node = list_create_node(L_STRING_T, "teste");
    NodeT* some_node_2 = list_create_node(L_STRING_T, "teste_2");
    NodeT* some_node_3 = list_create_node(L_STRING_T, "teste_3");

    list_insert_node(&list_ends, some_node);
    list_insert_node(&list_ends, some_node_2);
    list_insert_node(&list_ends, some_node_3);

    list_remove_node(&list_ends, some_node);

    cr_expect(some_node->prev == NULL);
    cr_expect(some_node->next == NULL);
    cr_expect(list_ends.head == some_node_3);
    cr_expect(list_ends.end == some_node_2);
}

Test(list_test, find_node) {
    NodeT* some_node = list_create_node(L_STRING_T, "teste");
    NodeT* some_node_2 = list_create_node(L_STRING_T, "teste_2");
    NodeT* some_node_3 = list_create_node(L_STRING_T, "teste_3");

    list_insert_node(&list_ends, some_node);
    list_insert_node(&list_ends, some_node_2);
    list_insert_node(&list_ends, some_node_3);

    NodeT* node = list_find_node(&list_ends, 3);

    cr_expect(strcmp((char*)node->node, "teste_3") == 0, "Should return 3rd element: teste_3.");

    list_remove_node(&list_ends, some_node);
    list_remove_node(&list_ends, some_node_2);
    list_remove_node(&list_ends, some_node_3);
}

Test(list_test, find_node_out_of_bounds) {
    NodeT* some_node = list_create_node(L_STRING_T, "teste");
    NodeT* some_node_2 = list_create_node(L_STRING_T, "teste_2");
    NodeT* some_node_3 = list_create_node(L_STRING_T, "teste_3");

    list_insert_node(&list_ends, some_node);
    list_insert_node(&list_ends, some_node_2);
    list_insert_node(&list_ends, some_node_3);

    NodeT* node = list_find_node(&list_ends, 5);

    cr_expect(node == list_ends.head, "It should return head if out of bounds.");

    list_remove_node(&list_ends, some_node);
    list_remove_node(&list_ends, some_node_2);
    list_remove_node(&list_ends, some_node_3);
}
