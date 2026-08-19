typedef struct Node {
    char pad00[0x26];
    short active;
    struct Node* next;
} Node;

typedef struct Collection {
    char pad00[0x20];
    Node* nodes;
} Collection;

extern void fn_80161284(Collection*, Node*);

void fn_801619BC(Collection* collection)
{
    int zero = 0;
    Node** link = &collection->nodes;

    while (*link != 0) {
        Node* node = *link;
        if (node->active != 0) {
            node->active = zero;
            link = &node->next;
        } else {
            *link = node->next;
            fn_80161284(collection, node);
        }
    }
}
