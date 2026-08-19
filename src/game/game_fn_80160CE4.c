typedef struct Args {
    void* entry;
    int amount;
} Args;

extern void fn_80160B18(void*, void*, int);

void fn_80160CE4(void* object, Args* args)
{
    fn_80160B18(object, args->entry, args->amount);
}
