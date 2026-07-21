typedef unsigned int u32;
typedef unsigned long long u64;
typedef u64 OSTime;

asm OSTime OSGetTime(void)
{
    nofralloc
retry:
    mftb r3, 269
    mftb r4, 268
    mftb r5, 269
    cmpw r3, r5
    bne retry
    blr
}

asm u32 OSGetTick(void)
{
    nofralloc
    mftb r3, 268
    blr
}
