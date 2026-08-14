typedef unsigned char u8;
typedef unsigned short u16;

typedef struct State800A270C {
    u8 pad000[0x194];
    u16 current;
} State800A270C;

typedef struct Context800A270C {
    u8 pad000[0x64];
    State800A270C* state;
} Context800A270C;

extern Context800A270C* fn_80201B8C(void*);
extern int fn_800A30C0(State800A270C*);
extern void fn_800A3C4C(void*, Context800A270C*, int, unsigned char);
extern void fn_800A3104(State800A270C*, int);

int fn_800A270C(void* unused, void* object, int value)
{
    Context800A270C* context = fn_80201B8C(unused);
    State800A270C* state = context->state;

    if (!fn_800A30C0(state)) {
        fn_800A3C4C(object, context, 0, value);
        fn_800A3104(state, 0);
        state->current = 0;
    }
    return 1;
}
