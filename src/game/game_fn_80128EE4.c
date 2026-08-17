typedef unsigned char u8;

typedef struct Node {
    u8 pad0[0xD];
    u8 valueD;
} Node;

typedef struct Runtime {
    u8 pad0[0xB8];
    Node* node;
} Runtime;

extern Runtime* fn_80128E30(void*);

u8 fn_80128EE4(void* owner)
{
    Runtime* runtime;
    Node* node;
    u8 result;

    if (owner == 0) {
        return 0;
    }
    runtime = fn_80128E30(owner);
    node = runtime != 0 ? runtime->node : 0;
    result = node != 0 ? node->valueD : 0;
    return result;
}
