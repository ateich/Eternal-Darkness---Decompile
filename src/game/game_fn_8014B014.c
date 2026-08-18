typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Set {
    u8 count;
    u8 pad1[7];
    u32 id;
    u8 padC[0x3C];
    u32 value48;
    u8 pad4C[0x3C];
    void* objects[16];
} Set;

typedef struct Value {
    float pad0, pad4;
    float x, y, z;
    u8 trailing[0x10];
} Value;

extern Set* fn_80156938(void*);
extern void *fn_80201BC8();
extern void fn_8011F6A4(void*, u32, u32, int, Value*, int);
extern short* fn_801938A8(void*);

void fn_8014B014(void* left, void* right)
{
    Set* entry;
    int count;
    int i;
    Set* right_set;
    Value value;

    right_set = fn_80156938(right);
    entry = fn_80156938(left);
    count = entry->count;
    for (i = 0; i < count; i++) {
        short* rotation;
        fn_8011F6A4(fn_80201BC8(right_set), entry->id, entry->value48,
                    -1, &value, 1);
        rotation = fn_801938A8(entry->objects[0]);
        rotation[0] = (short)value.x;
        rotation[1] = (short)value.y;
        rotation[2] = (short)value.z;
        entry = (Set*)((char*)entry + 4);
    }
}
