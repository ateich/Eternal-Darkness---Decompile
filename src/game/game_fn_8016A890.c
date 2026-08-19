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

extern void* fn_80166E3C(Context*, const char*, int);
extern void fn_8016057C(Context*, int);

void fn_8016A890(Context* context, const char* string, int length)
{
    ((Value*)context->current)->value = fn_80166E3C(context, string, length);
    ((Value*)context->current)->type = 3;
    if (context->current == context->end) {
        fn_8016057C(context, 1);
    }
    context->current = (char*)context->current + 16;
}
