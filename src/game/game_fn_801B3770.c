typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Link Link;
struct Link { Link* next; Link* prev; void* object; };

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

extern Entry lbl_8060C020[];
extern Node* lbl_8064D394;
extern Node* lbl_8064D398;
extern Node* lbl_8064D39C;
extern void fn_801B244C(void*);
extern void fn_801C21E8(void*);

static inline int resolve_handle(u32 value)
{
    u32 key = value & 0x7FFFFFFF;
    Node* node = lbl_8064D39C;
    while (node != 0) {
        if (node->key == key) return node->type | (value & 0x80000000U);
        node = node->next;
    }
    node = lbl_8064D398;
    while (node != 0) {
        if (node->key == key) return node->type | (value & 0x80000000U);
        node = node->next;
    }
    return -1;
}

void fn_801B3770(u32 handle)
{
    int id = resolve_handle(handle);
    Node* node;
    Link* link;
    u32 i;
    if (id == -1) return;
    if ((id & 0x80000000U) == 0) {
        node = (Node*)&lbl_8060C020[id].data[0x1400];
        if (node->state == 1) {
            if (node->prev) node->prev->next = node->next;
            else lbl_8064D39C = node->next;
            for (i = 0; i < 2; i++) {
                link = *(Link**)((u8*)node + 0xE64 + i * 4);
                while (link) { fn_801C21E8(link->object); link = link->next; }
            }
            link = *(Link**)((u8*)node + 0xE6C);
            while (link) { fn_801C21E8(link->object); link = link->next; }
            fn_801B244C(node);
        } else if (node->state == 2) {
            if (node->prev) node->prev->next = node->next;
            else lbl_8064D398 = node->next;
        }
        if (node->next) node->next->prev = node->prev;
        node->state = 0;
        node->next = lbl_8064D394;
        node->prev = 0;
        if (lbl_8064D394) lbl_8064D394->prev = node;
        lbl_8064D394 = node;
    } else {
        node = (Node*)&lbl_8060C020[id & 0x7FFFFFFF].data[0x1400];
        if (node->state != 0) *(u32*)((u8*)node + 0xEDC) = 0;
    }
}
