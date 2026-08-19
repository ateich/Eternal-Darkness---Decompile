typedef struct Value {
    int type;
    int pad04;
    union {
        double number;
        void* pointer;
    } value;
} Value;

typedef struct Context {
    int* stack;
} Context;

extern void fn_8016057C(Context*, int);
extern int fn_801692D4(void*, void*);
extern int fn_801691AC(Context*, void*, int);
extern void fn_80160480(Context*, void*);

int fn_8016938C(Context* context, Value* left, Value* right, Value* output)
{
    if (left->type == 2 && right->type == 2) {
        return left->value.number < right->value.number;
    }
    if (left->type == 3 && right->type == 3) {
        return fn_801692D4(left->value.pointer, right->value.pointer) < 0;
    }

    fn_8016057C(context, 2);
    *output++ = *left;
    *output++ = *right;
    if (fn_801691AC(context, output, 11) == 0) {
        fn_80160480(context, output - 2);
    }
    context->stack = (int*)((char*)context->stack - 16);
    return *context->stack != 1;
}
