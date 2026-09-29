typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Value {
    u8 byte0;
    u8 byte1;
    u8 byte2;
    u8 byte3;
} Value;

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
    Value valueC;
    Value value10;
    Value value2C;
    Value value30;
    Value value34;
    Value value38;
    u8 pad[2];
} SerializedItem;
#pragma pack()

#pragma use_lmw_stmw on

extern Value lbl_80651B98;
extern void* memcpy(void*, const void*, unsigned long);
extern void fn_80125ECC(void *);
extern int fn_801261F4(void*);
extern void fn_8012C478(void*, int, int);
extern void* fn_8012C62C(void*, int, Value*, Value*, Value*, u16);

int fn_8012F8CC(const u8* input, Object* object)
{
    u8 count;
    int offset;
    int i;

    memcpy(&count, input, 1);
    offset = 1;
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
            if (serialized.value2C.byte0 != serialized.value38.byte0 ||
                serialized.value2C.byte1 != serialized.value38.byte1 ||
                serialized.value2C.byte2 != serialized.value38.byte2 ||
                serialized.value2C.byte3 != serialized.value38.byte3) {
                Value value2C;
                Value value34;
                Value value38;
                value38 = serialized.value38;
                value34 = serialized.value34;
                value2C = serialized.value2C;
                fn_8012C62C(object, item->id, &value2C, &value34, &value38,
                            serialized.flags & ~1);
            } else {
                Value value2C;
                Value defaultValue;
                Value value38;
                value38 = serialized.value2C;
                defaultValue = lbl_80651B98;
                value2C = serialized.value2C;
                fn_8012C62C(object, item->id, &value2C, &defaultValue, &value38,
                            serialized.flags & ~1);
                item->status = 1;
            }
        }
    }
    return (offset + 0x1F) & ~0x1F;
}
