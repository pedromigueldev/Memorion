#ifndef NOTES_LIKED
#define NOTES_LIKED

#include "stdlib.h"
#include "stdio.h"

struct NodeT {
    int index;
    void* node;
    struct NodeT* next;
    struct NodeT* prev;
};
typedef struct NodeT NodeT;

typedef struct {
    NodeT* head;
    NodeT* end;
} ListEnds;

ListEnds list_create_ends();

NodeT* list_create_node(void* some_element);
NodeT* list_find_note(ListEnds* list_ends, int index);

void list_insert_node(ListEnds* list_ends, NodeT* node);
void list_remove_node(ListEnds* list_ends, NodeT* node);

#endif
