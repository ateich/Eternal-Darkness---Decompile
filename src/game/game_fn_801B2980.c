typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct ResourceNode ResourceNode;
struct ResourceNode {
    ResourceNode* next;
    ResourceNode* prev;
    u8 state;
    u8 index;
    u16 tag;
    u32 pad0C;
    void* primary;
    u8 data[0x1860];
};

typedef struct InitOptions {
    u32 flags;
    u32 first;
    u32 second;
    u16 scale;
    u16 command;
    u8 channel;
    u8 count;
    u8 pad13;
    u8* map;
    u8 map_count;
    u8 pad19[3];
    u8* values;
} InitOptions;

extern ResourceNode* lbl_8064CA14;
extern ResourceNode* lbl_8064CA1C;

int fn_801B2980(void* primary, void* secondary, void* table, void* descriptor,
                void* presets, void* options_ptr, u8 mode, u16 tag)
{
    ResourceNode* node = lbl_8064CA14;
    InitOptions* options = (InitOptions*)options_ptr;
    u8 i;

    if (node == 0) {
        return -1;
    }

    lbl_8064CA14 = node->next;
    if (lbl_8064CA14 != 0) {
        lbl_8064CA14->prev = 0;
    }
    node->next = lbl_8064CA1C;
    if (lbl_8064CA1C != 0) {
        lbl_8064CA1C->prev = node;
    }
    node->prev = 0;
    lbl_8064CA1C = node;
    node->state = 1;
    node->primary = primary;
    *(void**)(node->data + 0x84) = secondary;
    *(void**)(node->data + 0x108) = descriptor;
    node->tag = tag;

    for (i = 0; i < 128; i++) {
        node->data[4 + i] = 0xFF;
        node->data[0x88 + i] = 0xFF;
    }
    node->data[0xEA0] = (u8)(node->index + 23);
    node->data[0xED0] = 0;
    node->data[0xED1] = mode;

    if (options == 0) {
        *(u32*)(node->data + 0x10C) = -1;
        *(u32*)(node->data + 0x110) = -1;
    } else {
        if (options->flags & 1) {
            *(u32*)(node->data + 0x10C) = options->first;
            *(u32*)(node->data + 0x110) = options->second;
        } else {
            *(u32*)(node->data + 0x10C) = -1;
            *(u32*)(node->data + 0x110) = -1;
        }
        if (options->flags & 8) {
            for (i = 0; i < options->map_count; i++) {
                node->data[0x314 + options->map[i * 2]] = options->map[i * 2 + 1];
            }
        }
    }

    return node->index;
}
