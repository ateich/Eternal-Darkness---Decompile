typedef unsigned char u8;

typedef struct Node Node;
struct Node {
    Node* next;
    Node* prev;
    void* object;
    int value;
    u8 type;
    u8 list;
};

typedef struct TypeInfo {
    unsigned char pad[0x150C];
    int limits[2];
} TypeInfo;

typedef struct State {
    unsigned char pad[0xE64];
    Node* lists[3];
} State;

extern State* lbl_8064D380;
extern void fn_801B80D8(void*);

int fn_801B261C(void)
{
    unsigned int list_index;
    unsigned int list_offset = 0;
    unsigned int limit_offset = 0;
    Node* node;

    for (list_index = 0; list_index < 2; list_index++, list_offset += 4, limit_offset += 8) {
        node = *(Node**)((unsigned char*)lbl_8064D380 + 0xE64 + list_offset);
        if (node != 0) {
            while (node->value <= *(int*)((unsigned char*)lbl_8064D380 +
                                          node->type * 0x38 + 0x150C + limit_offset)) {
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

                node = *(Node**)((unsigned char*)lbl_8064D380 + 0xE64 + list_offset);
                if (node == 0) {
                    break;
                }
            }
        }
    }

    if (lbl_8064D380->lists[0] == 0 && lbl_8064D380->lists[1] == 0) {
        return 0;
    }
    return 1;
}
