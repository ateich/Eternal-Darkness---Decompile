typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Context8009EA3C {
    u8 pad00[8];
    s16 counter;
} Context8009EA3C;

typedef struct Work8009EA3C {
    u8 pad00[7];
    u8 field_07;
    u8 pad08[0x18];
    u32 flags;
} Work8009EA3C;

typedef struct State8009EA3C {
    u8 pad00[0xC4];
    Work8009EA3C* work;
} State8009EA3C;

extern void* fn_80201B44(void);
extern void* fn_80201814(void*);
extern void* fn_80201B8C(void*);
extern Context8009EA3C* fn_8006ED3C(State8009EA3C*, int, int*);
extern void fn_800A509C(int);
extern int* lbl_8064C5A8;

int fn_8009EA3C(register State8009EA3C* state)
{
    int index;
    Context8009EA3C* context;

    fn_80201B8C(fn_80201814(fn_80201B44()));
    context = fn_8006ED3C(state, 0x17, &index);
    context->counter = 0;
    state->work->flags &= ~(1U << 15);
    state->work->field_07 = 0;
    fn_800A509C(*lbl_8064C5A8);
    return 1;
}
