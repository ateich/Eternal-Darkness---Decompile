typedef struct ObjectData {
    char pad0[0x18];
    unsigned int* entries;
} ObjectData;

typedef struct Object {
    ObjectData* data;
    char pad4[0xC];
    int count;
} Object;

typedef struct OuterObject {
    char pad0[0x28];
    Object* object;
} OuterObject;

typedef struct Command {
    int type;
    int first;
    int second;
} Command;

extern void fn_8015F4D0(OuterObject*, Command*, int);
extern void fn_8015F988(Object*, int);
extern void fn_8015EFEC(Object*, Command*);
extern int fn_8015F0C0(int);

void fn_8015F694(OuterObject* outer, int alternate, Command* command)
{
    Object* object = outer->object;

    if (alternate == 0) {
        fn_8015F4D0(outer, command, 1);
        fn_8015F988(object, 30);
    } else {
        unsigned int* entries;
        unsigned int offset;
        int type;
        int temp;

        fn_8015EFEC(object, command);
        entries = object->data->entries;
        offset = (object->count - 1) * 4;
        type = entries[offset / 4] & 0x3F;
        if (type >= 32 && type <= 42) {
            entries[offset / 4] = (entries[offset / 4] & ~0x3F) |
                                  fn_8015F0C0(type);
        } else {
            fn_8015F988(object, 31);
        }

        temp = command->second;
        command->second = command->first;
        command->first = temp;
    }
}
