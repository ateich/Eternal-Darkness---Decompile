typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Entry8009EAB0 {
    u8 field_00;
    u8 field_01;
    u8 field_02;
    u8 field_03;
    u8 pad04[0x28];
} Entry8009EAB0;

typedef struct Work8009EAB0 {
    u8 pad00[7];
    u8 counter;
    u8 pad08[0x18];
    u32 flags;
} Work8009EAB0;

typedef struct State8009EAB0 {
    u8 pad00[0x18];
    u8 text[0x50];
    Entry8009EAB0 entries[1];
    u8 pad94[0x30];
    Work8009EAB0* work;
} State8009EAB0;

typedef struct Context8009EAB0 {
    u8 pad00[8];
    s16 counter;
    u8 pad0A[0xE];
    u32 flags;
} Context8009EAB0;

extern int fn_80201B44();
extern void *fn_80201814();
extern void *fn_80201B8C();
extern Context8009EAB0* fn_8006ED3C(State8009EAB0*, int, int*);
extern void* fn_8007D944(void);
extern int fn_8015E4E8(void);
extern int fn_800460EC(void);
extern int fn_800467F0(void*, int);
extern unsigned long long fn_8020123C();
extern void* lbl_8064D18C;

int fn_8009EAB0(register State8009EAB0* state)
{
    int index;
    register int done = 0;
    Context8009EAB0* context;

    fn_80201B8C(fn_80201814(((void*)fn_80201B44())));
    context = fn_8006ED3C(state, 0x17, &index);
    if (state->work->flags & 0x8000) {
        if (!fn_8007D944() && !fn_8015E4E8() && !fn_800460EC()) {
            state->work->counter++;
            if (state->work->counter >= 2) {
                done = 1;
            }
            if (fn_800467F0(lbl_8064D18C, 0) > 0) {
                done = 1;
            }
        }
        state->work->flags &= ~0x8000U;
    }
    if (!fn_8007D944() && !fn_8015E4E8() && !fn_800460EC()) {
        context->counter++;
        if (context->counter >= 900) {
            done = 1;
        }
    }
    if (!(context->flags & 0x40000) && done) {
        fn_8020123C(8, 0, ((void*)fn_80201B44()), 0);
        context->flags = (context->flags | 0x40000) | 0x100;
        state->entries[index].field_02 = 2;
        state->entries[index].field_03 = 4;
    }
    return 1;
}
