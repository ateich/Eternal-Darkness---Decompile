typedef unsigned long u32;

typedef struct Node801A8478 Node801A8478;

struct Node801A8478 {
    Node801A8478* next;
    unsigned char pad04[0x10];
    u32 value;
};

extern Node801A8478* lbl_8064D280;
extern u32 lbl_8064D5A8;

extern Node801A8478* fn_801A8408(Node801A8478*);

void fn_801A8478(void)
{
    Node801A8478* node = lbl_8064D280;
    u32 limit = lbl_8064D5A8;

    while (node != 0) {
        if (node->value < limit) {
            node = fn_801A8408(node);
        } else {
            node = node->next;
        }
    }
}
