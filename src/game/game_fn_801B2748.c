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
    unsigned int list_index;
    unsigned int list_offset = 0;
    Node* node;
    Node* next;

    for (list_index = 0; list_index < 2; list_index++, list_offset += 4) {
        node = *(Node**)((unsigned char*)lbl_8064D380 + 0xE64 + list_offset);
        while (node != 0) {
            next = node->next;
            fn_801B80D8(node->object);
            *(Node**)((unsigned char*)lbl_8064D380 + 0xE64 + list_offset) = node->next;
            if (*(Node**)((unsigned char*)lbl_8064D380 + 0xE64 + list_offset) != 0) {
                (*(Node**)((unsigned char*)lbl_8064D380 + 0xE64 + list_offset))->prev = 0;
            }
            node->next = lbl_8064D380->lists[2];
            if (lbl_8064D380->lists[2] != 0) {
                lbl_8064D380->lists[2]->prev = node;
            }
            lbl_8064D380->lists[2] = node;
            node = next;
        }
    }
}
