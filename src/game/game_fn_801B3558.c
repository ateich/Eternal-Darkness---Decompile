typedef struct Node Node;
struct Node {
    Node* next;
    Node* prev;
    unsigned char state;
};

extern Node* lbl_8064D398;
extern Node* lbl_8064D39C;

void fn_801B3558(Node* node)
{
    if (node->prev != 0) {
        node->prev->next = node->next;
    } else {
        lbl_8064D39C = node->next;
    }

    if (node->next != 0) {
        node->next->prev = node->prev;
    }

    if ((node->next = lbl_8064D398) != 0) {
        lbl_8064D398->prev = node;
    }
    node->prev = 0;
    lbl_8064D398 = node;
    node->state = 2;
}
