typedef unsigned char u8;
typedef unsigned short u16;

typedef struct State8009C424 {
    u8 pad00[0x100];
    u16 flags;
    u8 limit;
    u8 count;
} State8009C424;

extern void fn_80066754(void*, void*, void*);
extern int fn_80200C38();
extern int fn_801A7498(int);
extern void *fn_80201814();
extern int fn_80201B5C(void*);
extern int fn_80036E14(void*);
extern void fn_80038308(void*, int, short*);
extern void fn_80038464(void*, int, short*);
extern const double lbl_8064ED80;
extern const float lbl_8064ED88;

void fn_8009C424(register void* object, register State8009C424* state,
                 register void* random, void* arg3)
{
    short numerator;
    short denominator;
    register void* actor;
    register int special;

    fn_80066754(object, random, arg3);
    actor = fn_80201814(fn_801A7498(fn_80200C38(random)));
    if (actor != 0) {
        special = fn_80201B5C(actor) == 25;
        if (fn_80036E14(actor) == 1 || special) {
            state->count++;
            fn_80038308(object, 0, &numerator);
            fn_80038464(object, 0, &denominator);
            if (((float)numerator / (float)denominator > lbl_8064ED88 &&
                 state->count >= state->limit) || special) {
                state->flags |= 1;
                state->count = 0;
            }
        }
    }
}
