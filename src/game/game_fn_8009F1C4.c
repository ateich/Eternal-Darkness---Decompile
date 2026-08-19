typedef unsigned char u8;
typedef signed short s16;

typedef struct Context8009F1C4 {
    u8 pad00[8];
    s16 counter;
} Context8009F1C4;

extern void *fn_8006ED3C();
extern void* fn_8006D488(void*);
extern void fn_802020B4(void*, int);
extern void fn_801A5C30(int);
extern void fn_8015C8A4(int, int);
extern void fn_8009F360(void);
extern void (*lbl_8064C8C4)(void);
extern void fn_80144430(int, int);

int fn_8009F1C4(register void* state)
{
    int index;
    Context8009F1C4* context;

    context = fn_8006ED3C(state, 0x1D, &index);
    context->counter = 0;
    fn_802020B4(fn_8006D488(state), 0);
    fn_801A5C30(0);
    fn_8015C8A4(2, 0);
    lbl_8064C8C4 = fn_8009F360;
    context->counter++;
    fn_80144430(4, 1);
    return 0;
}
