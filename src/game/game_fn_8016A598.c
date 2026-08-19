typedef struct Context {
    char* top;
    char pad04[12];
    char* stack;
} Context;

int fn_8016A598(Context* context)
{
    return (context->top - context->stack) / 16;
}
