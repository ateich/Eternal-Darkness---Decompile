typedef struct Value {
    int type;
    int pad04;
    union {
        double number;
        void* pointer;
    } value;
} Value;

typedef struct Context {
    Value* stack;
    int pad04;
    Value* end;
} Context;

extern void* fn_80167798(Context*, int);
extern Value* fn_80167B5C(Context*, void*, int);
extern void* fn_801670A8(Context*, void*);
extern void fn_80167BA8(Context*, void*, double, void*);
extern void fn_8016057C(Context*, int);
extern int lbl_8064BBF8;

void fn_80169650(Context* context, Value* source)
{
    Value* current;
    int count;
    void* array;

    array = fn_80167798(context, 0);
    current = source;
    count = 0;
    while (current < context->stack) {
        Value* destination = fn_80167B5C(context, array, count + 1);
        *destination = *current;
        ++current;
        ++count;
    }
    fn_80167BA8(context, array, (double)count,
                fn_801670A8(context, &lbl_8064BBF8));
    context->stack = source;
    context->stack->type = 4;
    context->stack->value.pointer = array;
    if (context->stack == context->end) {
        fn_8016057C(context, 1);
    }
    ++context->stack;
}
