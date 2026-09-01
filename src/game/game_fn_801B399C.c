typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Node Node;
struct Node {
    Node* next;
    unsigned char pad[5];
    unsigned char index;
    u16 key;
    u32 value;
};

extern Node* lbl_8064D398;
extern Node* lbl_8064D39C;
extern void fn_801B3770(u32);

void fn_801B399C(u32 key)
{
    Node* node;

    node = lbl_8064D39C;
    while (node != 0) {
        if (node->key == (u16)key) {
            fn_801B3770(node->value);
        }
        node = node->next;
    }

    node = lbl_8064D398;
    while (node != 0) {
        if (node->key == (u16)key) {
            fn_801B3770(node->value);
        }
        node = node->next;
    }
}
