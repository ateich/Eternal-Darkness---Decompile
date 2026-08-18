typedef struct Node Node;

struct Node {
    Node* next;
    Node* prev;
};

extern Node* fn_80155E68(void);

void fn_80156080(Node* previous)
{
    Node* node = fn_80155E68();

    if (node != 0) {
        node->next = 0;
        node->prev = previous;
        if (previous != 0)
            previous->next = node;
    }
}
