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

NodeT* list_create_node(void* some_element)
{
    NodeT* result = malloc(sizeof(NodeT));
    result->node = some_element;
    result->next = NULL;
    result->prev = NULL;
    return result;
}

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
    // if the node is at the tail set the tail to previous node
    // if the tail is NULL then set the next pointer to NULL
    if (list_ends->end == node) {
        list_ends->end = node->prev;

        if (list_ends->end != NULL)
            list_ends->end->next = NULL;
    }

    // if the node is the hrad then set head to the next node
    // if the head is not empty then set prev to NULL
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
