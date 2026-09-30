typedef unsigned int u32;

typedef struct SIControl {
    int chan;
    u32 poll;
    u32 inputBytes;
    void *input;
    void (*callback)(int, u32, void *);
} SIControl;

extern SIControl Si_802FCA20;
extern volatile u32 __SIRegs[] : 0xCC006400;
extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32 enabled);

u32 SISetXY(u32 x, u32 y)
{
    u32 enabled;
    u32 poll;

    x <<= 16;
    x |= y << 8;
    poll = x;
    enabled = OSDisableInterrupts();
    Si_802FCA20.poll &= 0xFC0000FF;
    Si_802FCA20.poll |= poll;
    poll = Si_802FCA20.poll;
    __SIRegs[12] = poll;
    OSRestoreInterrupts(enabled);
    return poll;
}
