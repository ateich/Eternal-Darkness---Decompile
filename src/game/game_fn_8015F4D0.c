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

extern int fn_8015EF4C(Object*);
extern void fn_8015EED8(Object*, int);
extern int fn_8015F23C(Object*, int, int);
extern void fn_8015F2B0(Object*, int*, int);
extern int fn_8015F47C(Object*, int, int);
extern void fn_8015EE54(Object*, int);
extern int fn_8015EC10(Object*);
extern void fn_8015F1F8(Object*, int, int);
extern void fn_8015F12C(Object*, int, int, int, int);

#pragma use_lmw_stmw on

void fn_8015F4D0(OuterObject* outer, Command* command, int finish)
{
    Object* object = outer->object;
    int type;
    int position;
    int extra_index;
    int second_index;
    int first_index;

    if (fn_8015EF4C(object) != 0) {
        return;
    }

    type = object->data->entries[object->count - 1] & 0x3F;
    if ((type < 32 || type > 42) && command->second == -1 &&
        command->first == -1) {
        if (finish != 0) {
            fn_8015EED8(object, 1);
        }
        return;
    }

    extra_index = -1;
    second_index = -1;
    first_index = -1;
    if (type < 32 || type > 42) {
        if (fn_8015F23C(object, command->second, 41) == 0 &&
            fn_8015F23C(object, command->first, 40) == 0) {
            goto emit;
        }
    }

    if (type >= 32 && type <= 42) {
        fn_8015F2B0(object, &command->first, object->count - 1);
    } else {
        extra_index = fn_8015F47C(object, 42, -1);
        fn_8015EE54(object, 1);
    }

    second_index = fn_8015F47C(object, 43, 0);
    first_index = fn_8015F47C(object, 6, 1);
    fn_8015F1F8(object, extra_index, fn_8015EC10(object));

emit:
    position = fn_8015EC10(object);
    fn_8015F12C(object, command->second, second_index, 41, position);
    fn_8015F12C(object, command->first, first_index, 40, position);
    command->first = -1;
    command->second = -1;
}
