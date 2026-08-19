typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Item {
    int id;
    u8 pad4[8];
    u16 status;
    u8 rest[0x82];
} Item;

typedef struct Object {
    u8 pad[0x23C];
    Item* items;
} Object;

#pragma pack(1)
typedef struct SerializedItem {
    int index;
    u16 flags;
    u32 valueC;
    u32 value10;
    u32 value2C;
    u32 value30;
    u32 value34;
    u32 value38;
    u8 pad[2];
} SerializedItem;
#pragma pack()

#pragma use_lmw_stmw on

extern u32 lbl_80651B98;
extern void* memcpy(void*, const void*, unsigned long);
extern void fn_80125ECC(void *);
extern int fn_801261F4(void*);
extern void fn_8012C478(void*, int, int);
extern void fn_8012C62C(void*, int, u32*, u32*, u32*, u16);

int fn_8012F8CC(const u8* input, Object* object)
{
    u8 count;
    int offset = 1;
    int i;

    memcpy(&count, input, 1);
    fn_80125ECC(object);
    for (i = 0; i < count; i++) {
        SerializedItem serialized;
        Item* item;
        memcpy(&serialized, input + offset, 0x20);
        offset += 0x20;
        if (object->items == 0) {
            continue;
        }
        item = &object->items[serialized.index];
        if (item == 0 || item->id == -1) {
            continue;
        }
        fn_8012C478(object, item->id, serialized.flags & 1);
        if ((serialized.flags & 1) && (serialized.flags & ~1)) {
            fn_801261F4(object);
            if (serialized.value2C != serialized.value38) {
                fn_8012C62C(object, item->id, &serialized.value2C,
                            &serialized.value34, &serialized.value38,
                            serialized.flags & ~1);
            } else {
                fn_8012C62C(object, item->id, &serialized.value2C,
                            &lbl_80651B98, &serialized.value2C,
                            serialized.flags & ~1);
                item->status = 1;
            }
        }
    }
    return (offset + 0x1F) & ~0x1F;
}
