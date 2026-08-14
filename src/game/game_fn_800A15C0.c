typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct State800A15C0 {
    u8 pad00[0x38];
    u32 resource;
    u8 pad3C[0x2C];
    u8 index;
} State800A15C0;

typedef struct Context800A15C0 {
    u32 event;
    u8 pad04[4];
    short counter;
} Context800A15C0;

typedef struct Inner800A15C0 {
    u8 pad00[0x44];
    u32 resource;
} Inner800A15C0;

typedef struct Info800A15C0 {
    u8 pad00[0x8C];
    Inner800A15C0* inner;
} Info800A15C0;

extern Context800A15C0* fn_8006ED98(State800A15C0*);
extern u32 fn_8011E190(int);
extern void fn_8006DEF8(State800A15C0*, u32, void*, void*, int);
extern State800A15C0* fn_80201814(u32);
extern Info800A15C0* fn_80201B8C(void*);
extern Inner800A15C0* fn_80036D38(void*);
extern void fn_802020B4(void*, int);
extern void fn_801A5C30(int);
extern u64 fn_8020123C(int, int, u32, int);

int fn_800A15C0(register State800A15C0* state)
{
    int result = 0;
    Context800A15C0* context;
    int i;
    Info800A15C0* info;

    context = fn_8006ED98(state);
    context->counter++;
    if (context->counter >= 10 && fn_8011E190(2) == 0) {
        for (i = 0; i < 3; i++) {
            state->index = i;
            fn_8006DEF8(state, context->event, 0, 0, 0);
        }
        state = fn_80201814(state->resource);
        info = fn_80201B8C(state);
        fn_802020B4(fn_80201814(fn_80036D38(state)->resource), 0);
        fn_801A5C30(0);
        fn_8020123C(0x51, 0, info->inner->resource, 0);
        result = 1;
    }
    return result;
}
