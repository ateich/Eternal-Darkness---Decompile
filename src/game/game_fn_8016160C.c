typedef struct Node {
    void* object;
    int unused;
    struct Node* next;
    short count;
} Node;

typedef struct List {
    int unused;
    Node* head;
} List;

extern void fn_80161428(void*);

void fn_8016160C(List* list, Node* node)
{
    if (node->next == node) {
        if (node->count == 0)
            fn_80161428(node->object);
        node->next = list->head;
        list->head = node;
    }
}
