typedef struct ObjectData {
    char pad0[0x18];
    unsigned int* entries;
} ObjectData;

typedef struct Object {
    ObjectData* data;
    char pad4[0xC];
    int count;
} Object;

typedef struct Command {
    int type;
    int first;
    int second;
} Command;

extern void fn_8015EFEC(Object*, Command*);
extern int fn_8015F9B0(Object*, int, int);
extern int fn_8015F0C0(int);
extern void fn_8015F2B0(Object*, int*, int);
extern int fn_8015EC10(Object*);
extern void fn_8015F1F8(Object*, int, int);

#pragma use_lmw_stmw on

void fn_8015F334(Object* object, Command* command, int use_second, int type)
{
    int index;
    int* output;
    int* input;
    unsigned int* entries;
    unsigned int offset;
    int entry_type;

    if (use_second == 0) {
        output = &command->second;
        input = &command->first;
    } else {
        output = &command->first;
        input = &command->second;
    }

    fn_8015EFEC(object, command);
    index = object->count - 1;
    entries = object->data->entries;
    offset = (unsigned int)index * 4;
    entry_type = entries[index] & 0x3F;
    if (entry_type < 32 || entry_type > 42) {
        index = fn_8015F9B0(object, type, -1);
    } else if (use_second != 0) {
        entries[index] = (entries[index] & ~0x3F) | fn_8015F0C0(entry_type);
    }

    fn_8015F2B0(object, input, index);
    fn_8015F1F8(object, *output, fn_8015EC10(object));
    *output = -1;
}
