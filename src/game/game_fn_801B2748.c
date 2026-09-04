typedef struct Node Node;
struct Node {
    Node* next;
    Node* prev;
    void* object;
};

typedef struct State {
    unsigned char pad[0xE64];
    Node* lists[3];
} State;

extern State* lbl_8064D380;
extern void fn_801B80D8(void*);

void fn_801B2748(void)
{
    Node* node;
    Node* next;
    unsigned int i;

    for (i = 0; i < 2; i++) {
        node = lbl_8064D380->lists[i];
        while (node != 0) {
            next = node->next;
            fn_801B80D8(node->object);
            if ((lbl_8064D380->lists[i] = node->next) != 0) {
                lbl_8064D380->lists[i]->prev = 0;
            }
            if ((node->next = lbl_8064D380->lists[2]) != 0) {
                lbl_8064D380->lists[2]->prev = node;
            }
            lbl_8064D380->lists[2] = node;
            node = next;
        }
    }
}
