typedef unsigned short u16;
typedef struct Object {
    char pad_0[0x1E];
    u16 count;
    char pad_20[0x8C];
    u16* links;
} Object;

extern u16 lbl_805AAE40[];

void fn_8013133C(Object* object, int limit)
{
    int i;
    for (i = 0; i < object->count; i++) {
        u16 value = i;
        while (value >= limit) {
            value = object->links[value];
        }
        lbl_805AAE40[i] = value;
    }
}
