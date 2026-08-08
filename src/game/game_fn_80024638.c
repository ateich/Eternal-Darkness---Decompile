typedef unsigned char u8;
typedef unsigned int u32;

extern int fn_80213394(void*, void*);
extern int fn_802137F4(void*, void*, u32, int, int);
extern void fn_8021345C(void*);

void* fn_80024638(void* object, void* destination, u32* size)
{
    u8 state[0x40];

    if (fn_80213394(object, state) != 0) {
        *size = *(u32*)&state[0x34];
        while (fn_802137F4(state, destination, (*size + 31) & ~31, 0, 2) < 0) {
        }
        fn_8021345C(state);
    }
    return destination;
}
