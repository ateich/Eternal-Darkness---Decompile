typedef struct Command {
    int type;
    int value;
    int field8;
} Command;

extern void fn_8015F9B0(void*, int, int);
extern void fn_8015F988(void*, int);

int fn_8015EF4C(void* object, Command* command)
{
    switch (command->type) {
    case 1:
        fn_8015F9B0(object, 11, command->value);
        break;
    case 0:
        fn_8015F9B0(object, 12, command->value);
        break;
    case 2:
        fn_8015F988(object, 13);
        break;
    case 3:
        return 0;
    }

    command->type = 3;
    command->field8 = -1;
    command->value = -1;
    return 1;
}
