typedef struct Context {
    void* current;
    int pad04;
    void* end;
} Context;

typedef struct Value {
    double first;
    double second;
} Value;

extern void* fn_801670A8(Context*, const char*);
extern Value* fn_80168F84(Context*, void*);
extern void fn_8016057C(Context*, int);

void fn_8016AA34(Context* context, const char* name)
{
    Value* current = (Value*)context->current;
    *current = *fn_80168F84(context, fn_801670A8(context, name));
    context->current = current;
    if (context->current == context->end) {
        fn_8016057C(context, 1);
    }
    context->current = (char*)context->current + 16;
}
