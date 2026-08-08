typedef unsigned char u8;
typedef unsigned int u32;

extern int fn_80213394(void*, void*);
extern int fn_802137F4(void*, u32, u32, int, int);
extern void fn_8021345C(void*);

void fn_800244F4(void* object, u32* result, u32 value, u32 unused)
{
    u8 state[0x40];

    if (fn_80213394(object, state) != 0) {
        *result = *(u32*)&state[0x34];
        while (fn_802137F4(state, value, (*result + 31) & ~31, 0, 2) < 0) {
        }
        fn_8021345C(state);
    }
}
