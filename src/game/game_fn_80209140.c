typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct SIWork {
    u8 pad[0x1B0];
    u32 inputBufferValid[4];
    u32 inputBuffer[4][2];
} SIWork;

extern SIWork Packet_80640B68;
extern volatile u32 __SIRegs[64] : 0xCC006400;

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32 enabled);
extern u32 fn_80208E58(s32 chan);

s32 fn_80209140(s32 chan, void *data)
{
    register SIWork *work = &Packet_80640B68;
    register s32 channel = chan;
    register void *output = data;
    u32 enabled = OSDisableInterrupts();
    s32 valid;

    if (fn_80208E58(channel) & 0x20) {
        work->inputBuffer[channel][0] = __SIRegs[channel * 3 + 1];
        work->inputBuffer[channel][1] = __SIRegs[channel * 3 + 2];
        work->inputBufferValid[channel] = 1;
    }

    valid = work->inputBufferValid[channel];
    work->inputBufferValid[channel] = 0;
    if (valid) {
        ((u32 *)output)[0] = work->inputBuffer[channel][0];
        ((u32 *)output)[1] = work->inputBuffer[channel][1];
    }
    OSRestoreInterrupts(enabled);
    return valid;
}
