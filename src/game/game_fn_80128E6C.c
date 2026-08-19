typedef unsigned char u8;

typedef struct Node {
    int value;
    void* pointer;
} Node;

typedef struct Runtime {
    u8 pad0[0xB8];
    Node* node;
} Runtime;

#define FN_80128E30_RETURN Runtime*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);

void* fn_80128E6C(void* owner)
{
    void* result = 0;
    Node* node = fn_80128E30(owner)->node;
    if (node != 0) {
        result = node->pointer;
    }
    return result;
}
