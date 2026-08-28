typedef signed int s32;
typedef unsigned char u8;

extern void fn_801AC980(void*, s32);

void fn_80191F04(u8* state, u8 index, s32 reason)
{
    u8* entry;

    if (state[0] & 8) {
        entry = state + index * 4;
        if (*(void**)(entry + 0x10) != 0) {
            fn_801AC980(*(void**)(entry + 0x10), reason);
            *(void**)(entry + 0x10) = 0;
        }
    }
}
