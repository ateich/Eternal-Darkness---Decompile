typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;

typedef struct Context8009E0D4 {
    u8 pad00[8];
    s16 counter;
} Context8009E0D4;

typedef struct Work8009E0D4 {
    u8 pad00[0x20];
    u32 flags;
} Work8009E0D4;

typedef struct State8009E0D4 {
    u8 pad00[0xC4];
    Work8009E0D4* work;
} State8009E0D4;

extern Context8009E0D4* fn_8006ED3C(State8009E0D4*, int, int*);

int fn_8009E0D4(register State8009E0D4* state)
{
    int index;
    Context8009E0D4* context = fn_8006ED3C(state, 0xD, &index);
    Work8009E0D4* work = state->work;
    context->counter = 0;
    work->flags = work->flags | 4;
    work->flags = work->flags & 0xFFFFFFFEU;
    return 1;
}
