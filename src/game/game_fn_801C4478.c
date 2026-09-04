typedef unsigned int u32;

extern void* lbl_8064D4A0;
extern void* memset(void*, int, u32);
extern void DCFlushRangeNoSync(void*, u32);

void fn_801C4478(void)
{
    memset(lbl_8064D4A0, 0, 0x100);
    DCFlushRangeNoSync(lbl_8064D4A0, 0x100);
}
