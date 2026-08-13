typedef unsigned char u8;
typedef unsigned int u32;

typedef struct State80096FDC {
    u8 pad00[0x2C];
    u32 flags;
} State80096FDC;

extern void fn_80066A0C(void*, void*);

int fn_80096FDC(void* first, void* second, State80096FDC* state)
{
    register int result;

    result = 0;
    if ((state->flags & 4) == 0) {
        fn_80066A0C(first, second);
        result = 1;
    }
    return result;
}
