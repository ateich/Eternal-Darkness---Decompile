typedef struct Node {
    char pad00[0x10];
    struct Node* next;
    struct Node* owner;
} Node;

typedef struct Collection {
    char pad00[0x28];
    Node* nodes;
} Collection;

extern void fn_8016783C(Collection*, Node*);

void fn_80161AA0(Collection* collection)
{
    Node** link = &collection->nodes;

    while (*link != 0) {
        Node* node = *link;
        if (node->owner != node) {
            node->owner = node;
            link = &node->next;
        } else {
            *link = node->next;
            fn_8016783C(collection, node);
        }
    }
}
