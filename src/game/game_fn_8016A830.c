typedef struct Context {
    void* current;
    int pad04;
    void* end;
} Context;

typedef struct Value {
    int type;
    int pad04;
    double value;
} Value;

extern void fn_8016057C(Context*, int);

void fn_8016A830(Context* context, double value)
{
    ((Value*)context->current)->value = value;
    ((Value*)context->current)->type = 2;
    if (context->current == context->end) {
        fn_8016057C(context, 1);
    }
    context->current = (char*)context->current + 16;
}
