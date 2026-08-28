typedef signed int s32;
typedef unsigned char u8;

extern void fn_801AC980(void*, s32);

void fn_80191E84(u8* state, u8 count, s32 reason)
{
    u8* entry;
    s32 limit;
    s32 i;

    if (state[0] & 8) {
        entry = state;
        limit = count;
        for (i = 0; i < limit; entry += 4, i++) {
            if (*(void**)(entry + 0x10) != 0) {
                fn_801AC980(*(void**)(entry + 0x10), reason);
                *(void**)(entry + 0x10) = 0;
            }
        }
        state[0] &= ~0x10;
    }
}
