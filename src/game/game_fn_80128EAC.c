typedef unsigned char u8;

typedef struct Node {
    int value;
} Node;

typedef struct Runtime {
    u8 pad0[0xB8];
    Node* node;
} Runtime;

#define FN_80128E30_RETURN Runtime*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);

int fn_80128EAC(void* owner)
{
    Node* node = fn_80128E30(owner)->node;
    if (node != 0) {
        return node->value;
    }
    return -1;
}
