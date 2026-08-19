typedef struct Command {
    int type;
    int value;
} Command;

typedef struct Object {
    unsigned char pad0[0x28];
    void* field28;
} Object;

extern void fn_8015F9B0(void*, int, int);
extern void fn_8015F9D4(void*, int, int, int);

void fn_8015F048(Object* object, Command* command)
{
    void* child = object->field28;

    switch (command->type) {
    case 1:
        fn_8015F9B0(child, 18, command->value);
        break;
    case 0:
        fn_8015F9B0(child, 19, command->value);
        break;
    case 2:
        fn_8015F9D4(child, 20, 3, 3);
        break;
    }
}
