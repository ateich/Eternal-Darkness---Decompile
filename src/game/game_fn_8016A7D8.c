typedef struct Context {
    void* current;
    int pad04;
    void* end;
} Context;

typedef struct Value {
    int type;
    int pad04;
    void* value;
} Value;

extern void fn_8016057C(Context*, int);

void fn_8016A7D8(Context* context)
{
    ((Value*)context->current)->type = 1;
    if (context->current == context->end) {
        fn_8016057C(context, 1);
    }
    context->current = (char*)context->current + 16;
}
