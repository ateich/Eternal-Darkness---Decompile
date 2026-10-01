typedef unsigned int u32;

extern u32 OSGetResetCode(void);
extern void* OSGetArenaHi(void);
extern void* OSGetArenaLo(void);
extern void* memset(void* dst, int value, unsigned long size);

extern void* __OSSavedRegionStart;
extern void* __OSSavedRegionEnd;

static void ClearArena_80209CA0(void)
{
    if (OSGetResetCode() != 0x80000000) {
        __OSSavedRegionStart = 0;
        __OSSavedRegionEnd = 0;
        memset(OSGetArenaLo(), 0, (u32)OSGetArenaHi() - (u32)OSGetArenaLo());
    } else {
        void* end = (void*)*(u32*)0x812FDFEC;
        void* start = (void*)*(u32*)0x812FDFF0;

        __OSSavedRegionStart = start;
        __OSSavedRegionEnd = end;
        if (start == 0) {
            memset(OSGetArenaLo(), 0, (u32)OSGetArenaHi() - (u32)OSGetArenaLo());
        } else if ((u32)OSGetArenaLo() < (u32)__OSSavedRegionStart) {
            if ((u32)OSGetArenaHi() <= (u32)__OSSavedRegionStart) {
                memset(OSGetArenaLo(), 0, (u32)OSGetArenaHi() - (u32)OSGetArenaLo());
            } else {
                memset(OSGetArenaLo(), 0,
                       (u32)__OSSavedRegionStart - (u32)OSGetArenaLo());
                if ((u32)OSGetArenaHi() > (u32)__OSSavedRegionEnd) {
                    memset(__OSSavedRegionEnd, 0,
                           (u32)OSGetArenaHi() - (u32)__OSSavedRegionEnd);
                }
            }
        }
    }
}
