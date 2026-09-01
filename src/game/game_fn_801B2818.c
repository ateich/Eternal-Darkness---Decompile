typedef struct Node Node;
struct Node {
    Node* next;
    Node* prev;
};

typedef struct State {
    unsigned char pad[0xE64];
    Node* lists[3];
} State;

extern State* lbl_8064D380;
extern Node* lbl_8064D384;

void fn_801B2818(Node* node)
{
    Node* head;
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    if (node->prev != 0) {
        node->prev->next = node->next;
    } else {
        lbl_8064D380->lists[2] = node->next;
    }

    if ((head = node->next = lbl_8064D384) != 0) {
        lbl_8064D384->prev = node;
    }
    node->prev = 0;
    lbl_8064D384 = node;
}
