typedef struct Context {
    void* current;
} Context;

extern void* fn_801670A8(Context*, const char*);
extern void fn_80169068(Context*, void*);

void fn_8016AB20(Context* context, const char* name)
{
    void* current = context->current;
    fn_80169068(context, fn_801670A8(context, name));
    context->current = (char*)current - 16;
}
