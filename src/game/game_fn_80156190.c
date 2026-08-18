typedef struct Node Node;

struct Node {
    char pad[8];
    Node* next;
    Node* prev;
};

int fn_80156190(Node* node, Node* previous)
{
    Node* next = previous->next;

    node->next = next;
    node->prev = previous;
    previous->next = node;
    if (next != 0)
        next->prev = node;
    return 1;
}
