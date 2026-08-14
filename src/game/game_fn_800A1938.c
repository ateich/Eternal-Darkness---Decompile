typedef unsigned char u8;

typedef struct Context800A1938 {
    u8 pad00[8];
    short counter;
} Context800A1938;

extern Context800A1938* fn_8006ED98(void*);

int fn_800A1938(void* state)
{
    Context800A1938* context = fn_8006ED98(state);

    if (context->counter < 0) {
        context->counter = 0;
    }
    context->counter++;
    return 1;
}
