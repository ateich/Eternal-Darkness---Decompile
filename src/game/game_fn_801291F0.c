typedef unsigned char u8;

typedef struct Node {
    u8 pad0[0xC];
    u8 valueC;
} Node;

extern Node* fn_8012A13C(void*, void*);

void fn_801291F0(void* owner, void* key, u8 value)
{
    Node* node = fn_8012A13C(owner, key);
    if (node != 0) {
        node->valueC = value;
    }
}
