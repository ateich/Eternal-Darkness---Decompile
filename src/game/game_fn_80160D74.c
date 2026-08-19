typedef struct Args {
    void* value;
    int flag;
} Args;

extern void* fn_801688F8(void*, void*);
extern void* fn_80164BE4(void*, void*);
extern void fn_80168CB0(void*, void*, int);

void fn_80160D74(void* object, Args* args)
{
    void* value;

    if (args->flag != 0) {
        value = fn_801688F8(object, args->value);
    } else {
        value = fn_80164BE4(object, args->value);
    }
    fn_80168CB0(object, value, 0);
}
