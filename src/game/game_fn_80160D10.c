typedef struct Object {
    char* current;
} Object;

typedef struct Args {
    char* entry;
    void* value;
} Args;

extern void fn_80160CE4(void*, Args*);
extern int fn_80161044(Object*, void (*)(void*, Args*), Args*, int);

void fn_80160D10(Object* object, int count, void* value)
{
    Args args;
    int size;
    char* saved;

    size = (count + 1) * 16;
    saved = object->current - size;
    args.entry = saved;
    args.value = value;
    if (fn_80161044(object, fn_80160CE4, &args, size) != 0) {
        object->current = saved;
    }
}
