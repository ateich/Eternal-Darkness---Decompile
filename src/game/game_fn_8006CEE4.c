typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct Node {
    unsigned char pad[0xA];
    u16 state;
    u16 value;
    unsigned char pad_e[2];
    u32 fixed_value;
    u32 work;
    unsigned char pad_18[0xC];
} Node;

void fn_8006CEE4(Node *nodes)
{
    s32 i;

    for (i = 0; i < 44; i++) {
        if (nodes[i].state == 1) {
            nodes[i].work = 0;
            nodes[i].fixed_value = 0;
            nodes[i].value = 0;
            nodes[i].state = 0;
        }
    }
}
