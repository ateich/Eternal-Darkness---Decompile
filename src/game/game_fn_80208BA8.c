typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct SIPacket {
    s32 chan;
    u8 data[0x1C];
} SIPacket;

typedef struct SIControl {
    u32 chan;
    u32 poll;
    u32 inputBytes;
    u32 outputBytes;
    void *callback;
} SIControl;

static SIPacket Packet[4];
extern SIControl Si_802FCA20;
extern u32 __SIRegs[64] : 0xCC006400;

extern void SISetSamplingRate(u32 msec);
extern void SIInterruptHandler_8020860C(s32 interrupt, void *context);
extern void __OSSetInterruptHandler(s32 interrupt, void (*handler)(s32, void *));
extern void __OSUnmaskInterrupts(u32 interrupts);
extern u32 SIGetType(s32 chan);

void SIInit(void)
{
    Packet[0].chan = Packet[1].chan = Packet[2].chan = Packet[3].chan = -1;
    Si_802FCA20.poll = 0;
    SISetSamplingRate(0);

    while (__SIRegs[13] & 1) {
    }
    __SIRegs[13] = 0x80000000;

    __OSSetInterruptHandler(20, SIInterruptHandler_8020860C);
    __OSUnmaskInterrupts(0x800);

    SIGetType(0);
    SIGetType(1);
    SIGetType(2);
    SIGetType(3);
}
