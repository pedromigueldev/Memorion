#ifndef NOTES_LIKED
#define NOTES_LIKED

#include "stdlib.h"
#include "stdio.h"

typedef enum {
    HEAD,
    TAIL
} ListDirection ;

typedef enum {
    L_STRING_T,
    L_INT_T,
    L_FLOAT_T
} NodeType;

struct NodeT {
    int index;
    void* node;
    NodeType type;
    struct NodeT* next;
    struct NodeT* prev;
};
typedef struct NodeT NodeT;

typedef struct {
    NodeT* head;
    NodeT* end;
} ListEnds;

ListEnds list_create_ends();

NodeT* list_create_node(NodeType type_t, void* some_element);
NodeT* list_find_node(ListEnds* list_ends, int index);

void list_insert_node(ListEnds* list_ends, NodeT* node);
void list_remove_node(ListEnds* list_ends, NodeT* node);
void list_print_node(NodeT* node);
void list_print(ListEnds* list_ends, ListDirection direction);

#endif
