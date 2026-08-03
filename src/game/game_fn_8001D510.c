typedef unsigned int u32;

extern void* fn_8012070C(void);
extern void* fn_801EF7F4(void);
extern void* memcpy(void*, const void*, u32);
extern void fn_8015DAB0(void*);
extern void DCFlushRange(void*, u32);

void fn_8001D510(void)
{
    void* destination = fn_8012070C();

    memcpy(destination, fn_801EF7F4(), 0x4B080);
    fn_8015DAB0(destination);
    DCFlushRange(destination, 0x4B080);
}
