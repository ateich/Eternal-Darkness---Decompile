typedef struct Node {
    char pad00[4];
    struct Node* next;
    struct Node* owner;
} Node;

typedef struct Collection {
    char pad00[0x24];
    Node* nodes;
} Collection;

extern void fn_80161380(Collection*, Node*);

void fn_80161A34(Collection* collection)
{
    Node** link = &collection->nodes;

    while (*link != 0) {
        Node* node = *link;
        if (node->owner != node) {
            node->owner = node;
            link = &node->next;
        } else {
            *link = node->next;
            fn_80161380(collection, node);
        }
    }
}
