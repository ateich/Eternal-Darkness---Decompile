typedef unsigned char u8;
typedef unsigned int u32;

typedef struct State800955A4 {
    u8 pad00[0xCC];
    u32 value;
    u8 padD0[8];
    u32 result;
} State800955A4;

typedef struct Found800955A4 {
    u8 pad00[0x10];
    short kind;
    u8 pad12[2];
    int value;
} Found800955A4;

extern Found800955A4* fn_800935CC(int, int, u32, int);
extern void *fn_80201BC8();
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_8016B400(int, void*, int);

int fn_800955A4(register void* object, register void* arg,
                register State800955A4* state)
{
    register Found800955A4* found;
    register int result;

    found = fn_800935CC(0, 0, state->value, 4);
    fn_80201BC8(object);
    result = 0;
    if (found == 0) {
        state->value = 0;
        fn_80201D2C(object, 1);
        fn_80201D14(object, 1);
        result = 1;
    } else if (found->kind != 0) {
        fn_8016B400(found->kind, arg, 0);
    } else {
        state->result = found->value + 2;
    }
    return result;
}
