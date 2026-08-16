typedef unsigned int u32;

typedef struct State8009552C {
    unsigned char pad00[0xCC];
    u32 value;
} State8009552C;

extern void* fn_800935CC(int, int, u32, int);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

int fn_8009552C(register void* object, void* unused,
                register State8009552C* state)
{
    void* found;
    int result;
    found = fn_800935CC(0, 0, state->value, 4);
    result = 0;
    if (found == 0) {
        state->value = 0;
        fn_80201D2C(object, 1);
        fn_80201D14(object, 1);
        result = 1;
    }
    return result;
}
