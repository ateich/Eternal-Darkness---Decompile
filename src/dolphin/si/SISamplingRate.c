typedef int BOOL;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct XY {
    u16 line;
    u8 count;
} XY;

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL enabled);
extern void OSReport(const char* format, ...);
extern u32 VIGetTvFormat(void);
extern u32 SISetXY(u32 x, u32 y);

#define __VIRegs ((volatile u16*)0xCC002000)

#pragma dont_inline on
static u32 SamplingRate;

static XY XYNTSC[12] = {
    {246, 2}, {15, 18}, {30, 9}, {44, 6}, {52, 5}, {65, 4},
    {87, 3}, {87, 3}, {87, 3}, {131, 2}, {131, 2}, {131, 2},
};

static XY XYPAL[12] = {
    {296, 2}, {15, 21}, {29, 11}, {45, 7}, {52, 6}, {63, 5},
    {78, 4}, {104, 3}, {104, 3}, {104, 3}, {104, 3}, {156, 2},
};

void SISetSamplingRate(u32 msec)
{
    XY* xy;
    BOOL enabled;

    if (msec > 11) {
        msec = 11;
    }

    enabled = OSDisableInterrupts();
    SamplingRate = msec;

    switch (VIGetTvFormat()) {
    case 0:
    case 2:
    case 5:
        xy = XYNTSC;
        break;
    case 1:
        xy = XYPAL;
        break;
    default:
        OSReport("SISetSamplingRate: unknown TV format. Use default.\0");
        msec = 0;
        xy = XYNTSC;
        break;
    }

    SISetXY((__VIRegs[54] & 1 ? 2u : 1u) * xy[msec].line, xy[msec].count);
    OSRestoreInterrupts(enabled);
}

void SIRefreshSamplingRate(void)
{
    SISetSamplingRate(SamplingRate);
}
#pragma dont_inline reset
