typedef unsigned char u8;

typedef struct Values {
    u8 pad0[0x110];
    int first;
    int second;
} Values;

typedef struct Node {
    u8 pad0[4];
    Values* values;
} Node;

typedef struct Runtime {
    u8 pad0[0xB8];
    Node* node;
} Runtime;

#define FN_80128E30_RETURN Runtime*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);

void fn_801292E0(void* owner, int* first, int* second)
{
    Node* node = fn_80128E30(owner)->node;
    *first = node->values->first;
    *second = node->values->second;
}
