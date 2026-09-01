typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Node Node;
struct Node {
    Node* next;
    Node* prev;
    u8 state;
    u8 type;
    u8 pad0A[2];
    u32 key;
};

typedef struct Entry Entry;
struct Entry { u8 data[0x1868]; };

extern u8 lbl_8060C020[];
extern Node* lbl_8064D398;
extern Node* lbl_8064D39C;
extern void fn_801B8164();

static inline int resolve_handle(u32 value)
{
    u32 key = value & 0x7FFFFFFF;
    Node* node = lbl_8064D39C;

    while (node != 0) {
        if (node->key == key) {
            key = node->type;
            return key | (value & 0x80000000U);
        }
        node = node->next;
    }
    node = lbl_8064D398;
    while (node != 0) {
        if (node->key == key) {
            key = node->type;
            return key | (value & 0x80000000U);
        }
        node = node->next;
    }
    return -1;
}

void fn_801B3CC8(int arg0, int arg1, int handle, int mode)
{
    u8* base = lbl_8060C020;
    int id = resolve_handle(handle);

    if (id == (u32)-1) {
        return;
    }
    if ((id & 0x80000000U) == 0) {
        register u8* entry = base + id * sizeof(Entry);
        register u8* value;
        register u8* loop_base;
        register u32 i;

        fn_801B8164(arg0, arg1, entry[0x22B0], mode, handle);
        loop_base = entry + 0x1400;
        entry = loop_base;
        value = loop_base;
        for (i = 0; i < 0x40; i++) {
            if (entry[0x324] != loop_base[0xEB0]) {
                fn_801B8164(arg0, arg1, value[0x324], 0, -1);
            }
            entry++;
            value++;
        }
    } else {
        u32 index = id & 0x7FFFFFFF;
        switch (mode & 0xF) {
        case 0:
            base[index * sizeof(Entry) + 0x22CC] = arg0;
            break;
        case 1:
        {
            u8* entry = base + index * sizeof(Entry);
            *(u32*)(entry + 0x22DC) = 0;
            break;
        }
        case 2:
            base[index * sizeof(Entry) + 0x22DA] |= 8;
            base[index * sizeof(Entry) + 0x22CC] = arg0;
            break;
        case 3:
            base[index * sizeof(Entry) + 0x22DA] |= 0x80;
            base[index * sizeof(Entry) + 0x22CC] = arg0;
            break;
        }
    }
}
