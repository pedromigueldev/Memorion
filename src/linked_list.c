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

    NodeT* result = malloc(sizeof(NodeT));
    result->node = some_element;
    result->type = type_t;
    result->next = NULL;
    result->prev = NULL;

    return result;
}

NodeT* list_find_node(ListEnds* list_ends, int index)
{
    if (list_ends->end == NULL || list_ends->head == NULL) {
        printf("\x1B[31mHead and tail are null\x1B[0m\n");
        return list_ends->head;
    }

    NodeT* nodes = list_ends->end;
    NodeT* temp = nodes;

    if (index == 0) return list_ends->head;

    for (int i = 1; i < index; i++) {
        if (!temp->prev) return list_ends->head;
        temp = temp->prev;
    };
    return temp;
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

void list_print_node(NodeT* node) {
    switch (node->type) {
            case L_STRING_T:
                printf("%s", (char*)node->node);
                break;
            case L_INT_T:
                printf("%d", *(int*)node->node);
                break;
            case L_FLOAT_T:
                printf("%f", *(float*)node->node);
            break;
    }
}
//TODO: IMPLEMENT list_print
void list_print(ListEnds* list_ends);
