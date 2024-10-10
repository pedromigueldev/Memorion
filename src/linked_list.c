#include "./linked_list.h"
#include <stdio.h>
#include <stdlib.h>

ListEnds list_create_ends()
{
    ListEnds list_ends = {
        .head = NULL,
        .end = NULL
    };
    return list_ends;
}

NodeT* list_create_node(NodeType type_t, void* some_element)
{
    if (sizeof(some_element) != type_t) {
        printf("Error: type given is diferent from the element's size!\n");
        return NULL;
    }

    NodeT* result = malloc(sizeof(NodeT));
    result->node = some_element;
    result->type = type_t;
    result->next = NULL;
    result->prev = NULL;

    return result;
}

//TODO: IMPLEMENT list_find_note
NodeT* list_find_note(ListEnds* list_ends, int index);

void list_insert_node(ListEnds* list_ends, NodeT* node)
{
    if (list_ends->head == NULL)
        list_ends->end = node;

    node->next = list_ends->head;
    if (list_ends->head != NULL) {
        list_ends->head->prev = node;
    }
    list_ends->head = node;
}

void list_remove_node(ListEnds* list_ends, NodeT* node)
{
    if (list_ends->end == node) {
        list_ends->end = node->prev;

        if (list_ends->end != NULL)
            list_ends->end->next = NULL;
    }

    if (list_ends->head == node) {
        list_ends->head = node->next;

        if (list_ends->head != NULL)
            list_ends->head->prev = NULL;

        goto clean_exit;
    }

    node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;

    clean_exit:
    node->next = NULL;
    node->prev = NULL;
    free(node);
}

//TODO: IMPLEMENT list_print_node
void list_print_node(NodeT* node);
//TODO: IMPLEMENT list_print
void list_print(ListEnds* list_ends);
