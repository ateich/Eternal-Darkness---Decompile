typedef struct ObjectData {
    char pad0[0x18];
    int* entries;
} ObjectData;

typedef struct Object {
    ObjectData* data;
} Object;

extern int fn_8015EBDC(Object*, int);

int fn_8015F23C(Object* object, int index, int type)
{
    while (index != -1) {
        if ((object->data->entries[index] & 0x3F) != type) {
            return 1;
        }
        index = fn_8015EBDC(object, index);
    }
    return 0;
}
