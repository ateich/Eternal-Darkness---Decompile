typedef struct Context {
    char pad00[0x5C];
    int limit;
} Context;

extern void fn_80161FA0(Context*, int);

void fn_8016AC68(Context* context, int value)
{
    if (value > 0x3FFFFF) {
        context->limit = -1;
    } else {
        context->limit = value << 10;
    }
    fn_80161FA0(context, value);
}
