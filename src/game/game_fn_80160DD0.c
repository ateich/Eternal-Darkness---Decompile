typedef struct Object {
    char _pad00[0x5C];
    char* current;
    char* mark;
} Object;

typedef struct Args {
    void* value;
    int flag;
} Args;

extern void fn_80161FA0(void);
extern void fn_80160D74(Object*, Args*);
extern int fn_80161044(Object*, void (*)(Object*, Args*), Args*);

int fn_80160DD0(Object* object, void* value, int flag)
{
    Args args;
    char* saved;
    int result;

    args.value = value;
    args.flag = flag;
    fn_80161FA0();
    saved = object->mark;
    result = fn_80161044(object, fn_80160D74, &args);
    if (result == 0) {
        object->current += object->mark - saved;
    } else if (result == 1) {
        result = 3;
    }
    return result;
}
