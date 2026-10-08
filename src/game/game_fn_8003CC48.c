typedef signed int s32;
typedef signed short s16;
typedef unsigned char u8;
typedef float f32;

typedef struct ValueTable {
    u8 pad0[0x70];
    f32 values[5];
} ValueTable;

typedef struct Object {
    u8 pad0[0x8C];
    ValueTable *table;
} Object;

extern s32 fn_800C1AB8(s32 kind);
extern const f32 lbl_8064E26C;
extern const f32 lbl_8064E294;

s32 fn_8003CC48(s32 unused, Object *object, s32 kind, s16 amount)
{
    s32 index;
    ValueTable *table;
    f32 value;

    index = fn_800C1AB8(kind);
    table = object->table;
    value = table->values[index];
    if (lbl_8064E294 == value || lbl_8064E26C == value) {
        index = fn_800C1AB8(15);
        table = object->table;
        value = table->values[index];
    }

    return (s32)((f32)amount *
                 (lbl_8064E294 == value ? lbl_8064E26C : value));
}
