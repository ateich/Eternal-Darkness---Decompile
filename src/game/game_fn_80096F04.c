typedef unsigned char u8;
typedef unsigned int u32;

typedef struct State80096F04 {
    u8 pad00[0x2C];
    u32 flags;
} State80096F04;

extern int fn_80062ED0(void*, void*, void*, void*);
extern u32 fn_80036D5C(void*);
extern void fn_80036DA4(void*, u32);
extern int fn_80200C20(void*);
extern int fn_80201B44(int);
extern void fn_80096E24(void*);

int fn_80096F04(void* unused, register void* object, void* value,
                register void* random, register State80096F04* state,
                void* unused8, void* final_value)
{
    register int result;
    register u32 flags;
    register int filtered;

    result = 0;
    if ((state->flags & 4) == 0 &&
        fn_80062ED0(object, value, random, final_value) != 0) {
        flags = fn_80036D5C(object);
        filtered = fn_80036D5C(object) & 0x80;
        random = (void*)fn_80200C20(random);
        if (fn_80201B44((int)random) == (int)random) {
            if (flags & 0x8000) {
                fn_80096E24(object);
                fn_80036DA4(object, (flags & ~0x8000) | 0x80);
            }
        }
        if ((state->flags & 0x100) == 0 &&
            (state->flags & 0x20) == 0 && filtered == 0) {
            state->flags |= 0x200;
        }
        result = 1;
    }
    return result;
}
