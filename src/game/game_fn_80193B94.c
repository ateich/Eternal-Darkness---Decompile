typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_801945D4(u8, u8, void*, void*, void*, void*);
extern void fn_801957EC(u8, u8, void*);
extern void fn_801944C0(u8, void*, void*, void*);
extern void fn_80194998(u8, u16, void*, void*);

void fn_80193B94(u8* object, void* first, void* second)
{
    u8* state;
    u8 current;
    u8 limit;
    u32 flags;

    state = object + 0x8C;
    current = object[0x96];
    limit = object[0x97];
    if (current < limit && (*(u32*)(state + 0x7C) & 0x20) != 0) {
        fn_801945D4(limit, current, first, state + 0x94, state + 0x90, state + 0x8C);
        fn_801945D4(state[0xB], current, second, state + 0x94, state + 0x90, state + 0x8C);
    } else {
        flags = *(u32*)(state + 0x7C);
        if ((flags & 0x40000) != 0 || (flags & 0x10) != 0) {
            flags = *(volatile u32*)(state + 0x7C);
            flags |= 0x40000;
            *(u32*)(state + 0x7C) = flags;
            fn_801957EC(state[0xB], state[2], first);
            fn_801957EC(state[0xB], state[2], second);
        } else if ((flags & 0x80) != 0) {
            fn_801944C0(limit, first, state + 0x90, state + 0x8C);
            fn_801944C0(state[0xB], second, state + 0x90, state + 0x8C);
            fn_80194998(state[0xB], *(u16*)(object + 0xA), first, state);
            fn_80194998(state[0xB], *(u16*)(object + 0xA), second, state);
        }
    }
}
