typedef unsigned int u32;
typedef struct Node Node;
struct Node { Node* next; unsigned char pad[8]; u32 key; };

extern Node* lbl_8064D398;
extern Node* lbl_8064D39C;
extern void fn_801B3770(u32);

void fn_801B3940(void)
{
    Node* node = lbl_8064D39C;
    while (node != 0) {
        fn_801B3770(node->key);
        node = node->next;
    }
    node = lbl_8064D398;
    while (node != 0) {
        fn_801B3770(node->key);
        node = node->next;
    }
}
