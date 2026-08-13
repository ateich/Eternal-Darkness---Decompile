typedef unsigned char u8;
typedef signed short s16;

typedef struct Entry8009F258 {
    u8 field_00;
    u8 pad01;
    u8 field_02;
    u8 field_03;
    u8 pad04[0x28];
} Entry8009F258;

typedef struct State8009F258 {
    u8 pad00[0x68];
    Entry8009F258 entries[1];
} State8009F258;

typedef struct Context8009F258 {
    u8 pad00[8];
    s16 counter;
} Context8009F258;

typedef struct Inner8009F258 {
    u8 pad00[0x44];
    void* object;
} Inner8009F258;

typedef struct Global8009F258 {
    u8 pad00[0x8C];
    Inner8009F258* inner;
} Global8009F258;

extern Context8009F258* fn_8006ED3C(State8009F258*, int, int*);
extern void fn_8006DEF8(State8009F258*, int, void*, void*, int);
extern void* fn_80201814(void*);
extern Global8009F258* fn_80201B8C(void);
extern void fn_8020104C(int, int, void*, int, float);
extern void (*lbl_8064C8C4)(void);
extern void fn_80144430(int, int);
extern const float lbl_8064EDD8;

int fn_8009F258(register State8009F258* state)
{
    int index;
    register int result = 0;
    Context8009F258* context;
    int i;

    context = fn_8006ED3C(state, 0x1D, &index);
    if (context->counter > 400) {
        state->entries[index].field_02 = 0;
        state->entries[index].field_03 = 4;
        for (i = 0; i < 4; i++) {
            state->entries[index].field_00 = i;
            fn_8006DEF8(state, 0x1D, 0, 0, 0);
        }
        fn_80201814(*(void**)((u8*)state + 0x38));
        fn_8020104C(0x51, 0, fn_80201B8C()->inner->object, 0, lbl_8064EDD8);
        lbl_8064C8C4 = 0;
        fn_80144430(4, 0);
        result = 1;
    }
    context->counter++;
    return result;
}
