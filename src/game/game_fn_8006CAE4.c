typedef unsigned int u32;
typedef unsigned short u16;

typedef struct Node {
    unsigned char pad[0xC];
    u16 state;
    unsigned char pad_e[2];
    u32 fixed_value;
    u32 work;
    u32 flags;
} Node;

extern void fn_8006C9D4(Node *node, u16 state);

void fn_8006CAE4(Node *node, u32 value, u32 flags)
{
    if (node != 0) {
        node->work = 0;
        node->fixed_value = value << 16;
        node->flags |= flags;
        node->state = 0;
        fn_8006C9D4(node, 2);
    }
}
