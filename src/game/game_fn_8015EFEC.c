typedef struct Command {
    int type;
    int value;
    int field8;
} Command;

extern int fn_8015EF4C(void*, Command*);
extern void fn_8015EED8(void*, int);

void fn_8015EFEC(void* object, Command* command)
{
    fn_8015EF4C(object, command);
    if (command->value == -1 && command->field8 == -1) {
        fn_8015EED8(object, 1);
    }
}
