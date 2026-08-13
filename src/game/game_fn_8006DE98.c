typedef signed int s32;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Node {
    unsigned char pad_0[0xC];
    u16 threshold;
    unsigned char pad_E[6];
    u32 accumulator;
} Node;

typedef struct Owner {
    unsigned char pad_0[4];
    Node *node;
} Owner;

extern void fn_8006C9C0(Node *node);

s32 fn_8006DE98(Owner *owner)
{
    Node *node = owner->node;
    s32 result = 0;
    s32 previous = node->accumulator >> 16;

    fn_8006C9C0(node);
    if (previous >= node->threshold) {
        result = 1;
    }
    return result;
}
