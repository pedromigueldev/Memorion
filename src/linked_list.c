#include "./linked_list.h"

ListEnds list_create_ends()
{
    ListEnds list_ends = {
        .head = NULL,
        .end = NULL
    };
    return list_ends;
}

NodeT* list_create_node(void* some_element)
{
    NodeT* result = malloc(sizeof(NodeT));
    result->node = some_element;
    result->next = NULL;
    result->prev = NULL;
    return result;
}

int list_insert_node(ListEnds* list_ends, NodeT* node)
{
    if (list_ends->head == NULL) {
        list_ends->end = node;
    }

    node->next = list_ends->head;
    if (list_ends->head != NULL) {
        list_ends->head->prev = node;
    }
    list_ends->head = node;

    return list_ends->head == node? 0 : -1;
}
