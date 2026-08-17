typedef unsigned char u8;

typedef struct Node {
    int value;
} Node;

typedef struct Runtime {
    u8 pad0[0xB8];
    Node* node;
} Runtime;

extern Runtime* fn_80128E30(void*);

int fn_80128EAC(void* owner)
{
    Node* node = fn_80128E30(owner)->node;
    if (node != 0) {
        return node->value;
    }
    return -1;
}
