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
} Context;

extern void fn_80160628(Context*, Value*, int);
extern void fn_80169650(Context*, Value*);

void fn_80169740(Context* context, Value* source, int count)
{
    if (context->stack - source - count < 0) {
        fn_80160628(context, source, count);
    }
    fn_80169650(context, source + count);
}
