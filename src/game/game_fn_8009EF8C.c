typedef unsigned char u8;
typedef signed short s16;

typedef struct Entry8009EF8C {
    u8 field_00;
    u8 pad01[0x2B];
} Entry8009EF8C;

typedef struct State8009EF8C {
    u8 pad00[4];
    void* context;
    u8 pad08[0x10];
    u8 text[0x50];
    Entry8009EF8C entries[1];
} State8009EF8C;

typedef struct Context8009EF8C {
    void* event;
    u8 pad04[4];
    s16 counter;
} Context8009EF8C;

typedef struct Inner8009EF8C {
    u8 pad00[0x44];
    void* object;
} Inner8009EF8C;

typedef struct Global8009EF8C {
    u8 pad00[0x8C];
    Inner8009EF8C* inner;
} Global8009EF8C;

extern Context8009EF8C* fn_8006ED98(State8009EF8C*);
extern int fn_800467F0(void*, int);
extern void fn_8006DEF8(State8009EF8C*, void*, void*, void*, int);
extern void *fn_80201814();
extern void *fn_80201B8C();
extern void fn_8020104C(int, void*, void*, int, float);
#define fn_8020104C(a,b,c,d,e) fn_8020104C((int)(a),(void*)(b),(void*)(c),(int)(d),(float)(e))
extern void* fn_80036D38(void*);
extern void fn_802020B4(void*, int);
extern void fn_801A5C30(int);
extern void* lbl_8064D18C;
extern const float lbl_8064EDD8;

int fn_8009EF8C(register State8009EF8C* state)
{
    register int result = 0;
    Context8009EF8C* context;
    int i;

    context = fn_8006ED98(state);
    context->counter++;
    if (!fn_800467F0(lbl_8064D18C, 0) || context->counter >= 10) {
        for (i = 0; i < 3; i++) {
            state->entries[0].field_00 = i;
            fn_8006DEF8(state, context->event, 0, 0, 0);
        }
        state = fn_80201814(*(void**)((u8*)state + 0x38));
        fn_8020104C(0x51, 0, ((Global8009EF8C*)fn_80201B8C())->inner->object, 0, lbl_8064EDD8);
        fn_802020B4(fn_80201814(*(void**)((u8*)fn_80036D38(state) + 0x44)), 0);
        fn_801A5C30(0);
        result = 1;
    }
    return result;
}
