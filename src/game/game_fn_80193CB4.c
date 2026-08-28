typedef unsigned char u8;
typedef unsigned int u32;

extern void fn_801952E8(void*, int);
extern void fn_801941EC(void*, void*, void*);

void fn_80193CB4(u8* object, void* data)
{
    u8* state;
    u32 flags;

    state = object + 0x8C;
    if (*(void**)(object + 0x148) != 0) {
        flags = *(u32*)(state + 0x7C);
        if ((flags & 0x1000) != 0) {
            fn_801952E8(object, 1);
            flags = *(u32*)(state + 0x7C);
            flags &= ~0x1000;
            *(u32*)(state + 0x7C) = flags;
        } else if (state[9] == 0) {
            if ((flags & 0x40) != 0) {
                fn_801952E8(object, 1);
            } else if ((flags & 0x800) != 0) {
                fn_801952E8(object, 0);
            }
        }
        fn_801941EC(state, *(void**)(object + 0x4C), data);
    }
}
