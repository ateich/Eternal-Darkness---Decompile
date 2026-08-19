typedef struct Context {
    void* current;
    char pad04[4];
    void* end;
    char pad0C[0x40];
    int limit;
} Context;

typedef struct Value {
    int type;
    int pad04;
    void* value;
} Value;

extern char lbl_8024FE6C[];
extern void fn_80163BB4(Context*, const char*, ...);
extern void* fn_80167014(Context*, void*, int);
extern void fn_8016057C(Context*, int);

void fn_8016A970(Context* context, void* value, int index)
{
    if ((unsigned)(index + 1) > 1) {
        if (index < 6 || index > context->limit) {
            fn_80163BB4(context, lbl_8024FE6C, index);
        }
    }
    ((Value*)context->current)->value = fn_80167014(context, value, index);
    ((Value*)context->current)->type = 0;
    if (context->current == context->end) {
        fn_8016057C(context, 1);
    }
    context->current = (char*)context->current + 16;
}
