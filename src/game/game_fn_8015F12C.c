typedef struct ObjectData {
    char pad0[0x18];
    unsigned int* entries;
} ObjectData;

typedef struct Object {
    ObjectData* data;
} Object;

extern int fn_8015EBDC(Object*, int);
extern void fn_8015EB30(Object*, int, int);

#pragma use_lmw_stmw on

void fn_8015F12C(Object* object, int index, int value, int match, int replacement)
{
    unsigned int* entries = object->data->entries;

    while (index != -1) {
        int next = fn_8015EBDC(object, index);
        int type = entries[index] & 0x3F;

        if (type == match) {
            fn_8015EB30(object, index, replacement);
        } else {
            fn_8015EB30(object, index, value);
            if (type == 40) {
                entries[index] = (entries[index] & ~0x3F) | 38;
            } else if (type == 41) {
                entries[index] = (entries[index] & ~0x3F) | 39;
            }
        }
        index = next;
    }
}
