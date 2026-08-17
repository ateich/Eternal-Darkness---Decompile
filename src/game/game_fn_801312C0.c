typedef unsigned short u16;
typedef struct Object {
    char pad_0[0x1E];
    u16 count;
    char pad_20[0x90];
    u16* values;
} Object;

extern u16 lbl_805AAE40[];
extern int fn_80130998(int, float);

void fn_801312C0(Object* object, float scale)
{
    int i;

    fn_80130998(object->count, scale);
    for (i = 0; i < object->count; i++) {
        lbl_805AAE40[object->values[i] / 6] = i;
    }
}
