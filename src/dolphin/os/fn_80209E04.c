typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct OSBootInfo {
    u8 _00[0x28];
    u32 memorySize;
    u32 consoleType;
    void* arenaLo;
    void* arenaHi;
} OSBootInfo;

typedef struct DVDDriveInfo {
    u8 data[0x20];
} DVDDriveInfo;

extern int AreWeInitialized_8064D8FC;
extern OSBootInfo* BootInfo_8064D8F0;
extern u32* BI2DebugFlag_8064D8F4;
extern u32 BI2DebugFlagHolder_8064D8F8;
extern int __OSInIPL;
extern u64 __OSStartTime;
extern u32 __DVDLongFileNameFlag;
extern u32 __PADSpec;
extern DVDDriveInfo DriveInfo_80640D80;

extern u64 __OSGetSystemTime(void);
extern u32 OSDisableInterrupts(void);
extern void PPCDisableSpeculation(void);
extern void PPCSetFpNonIEEEMode(void);
extern void OSSetArenaLo(void*);
extern void OSSetArenaHi(void*);
extern void OSExceptionInit_8020A19C(void);
extern void __OSInitSystemCall(void);
extern void OSInitAlarm(void);
extern void __OSModuleInit(void);
extern void __OSInterruptInit(void);
extern void* __OSSetInterruptHandler(u32, void*);
extern void __OSResetSWInterruptHandler(void);
extern void __OSContextInit(void);
extern void __OSCacheInit(void);
extern void EXIInit(void);
extern void SIInit(void);
extern void __OSInitSram(void);
extern void __OSThreadInit(void);
extern void __OSInitAudioSystem(void);
extern u32 PPCMfhid2(void);
extern void PPCMthid2(u32);
extern void __OSInitMemoryProtection(void);
extern void OSReport(const char*, ...);
extern void* OSGetArenaLo(void);
extern void* OSGetArenaHi(void);
extern void EnableMetroTRKInterrupts(void);
extern void ClearArena_80209CA0(void);
extern void OSEnableInterrupts(void);
extern void DVDInit(void);
extern void DCInvalidateRange(void*, u32);
extern void DVDInquiryAsync(void*, DVDDriveInfo*, void*);
extern void InquiryCallback_80209DC8(void);

static const char OSVersion[] = "\nDolphin OS $Revision: 52 $.\n";
static const char KernelBuilt[] = "Kernel built : %s %s\n";
static const char BuildDate[] = "Apr 16 2002";
static const char BuildTime[] = "02:09:06";
static const char ConsoleType[] = "Console Type : ";
static const char Retail[] = "Retail %d\n";
static const char Mac[] = "Mac Emulator\n";
static const char PC[] = "PC Emulator\n";
static const char Arthur[] = "EPPC Arthur\n";
static const char Minnow[] = "EPPC Minnow\n";
static const char Development[] = "Development HW%d\n";
static const char Memory[] = "Memory %d MB\n";
static const char Arena[] = "Arena : 0x%x - 0x%x\n";
extern char __ArenaLo[];
extern char __ArenaHi[];
extern char _stack_addr[];

void OSInit(void)
{
    OSBootInfo* bootInfo;
    u32 consoleType;

    if (AreWeInitialized_8064D8FC) {
        return;
    }
    AreWeInitialized_8064D8FC = 1;
    __OSStartTime = __OSGetSystemTime();
    OSDisableInterrupts();
    PPCDisableSpeculation();
    PPCSetFpNonIEEEMode();

    BootInfo_8064D8F0 = (OSBootInfo*)0x80000000;
    BI2DebugFlag_8064D8F4 = 0;
    __DVDLongFileNameFlag = 0;
    bootInfo = *(OSBootInfo**)0x800000F4;
    if (bootInfo != 0) {
        BI2DebugFlag_8064D8F4 = (u32*)((u8*)bootInfo + 0xC);
        __PADSpec = *(u32*)((u8*)bootInfo + 0x24);
        *(u8*)0x800030E8 = (u8)*BI2DebugFlag_8064D8F4;
        *(u8*)0x800030E9 = (u8)__PADSpec;
    } else if (*(u32*)0x80000034 != 0) {
        BI2DebugFlagHolder_8064D8F8 = *(u8*)0x800030E8;
        BI2DebugFlag_8064D8F4 = &BI2DebugFlagHolder_8064D8F8;
        __PADSpec = *(u8*)0x800030E9;
    }

    __DVDLongFileNameFlag = 1;
    bootInfo = BootInfo_8064D8F0;
    OSSetArenaLo(bootInfo->arenaLo ? bootInfo->arenaLo : __ArenaLo);
    if (BootInfo_8064D8F0->arenaLo == 0 && BI2DebugFlag_8064D8F4 != 0 &&
        *BI2DebugFlag_8064D8F4 < 2) {
        OSSetArenaLo((void*)(((u32)_stack_addr + 31) & ~31));
    }
    OSSetArenaHi(BootInfo_8064D8F0->arenaHi ? BootInfo_8064D8F0->arenaHi : __ArenaHi);

    OSExceptionInit_8020A19C();
    __OSInitSystemCall();
    OSInitAlarm();
    __OSModuleInit();
    __OSInterruptInit();
    __OSSetInterruptHandler(0x16, __OSResetSWInterruptHandler);
    __OSContextInit();
    __OSCacheInit();
    EXIInit();
    SIInit();
    __OSInitSram();
    __OSThreadInit();
    __OSInitAudioSystem();
    PPCMthid2(PPCMfhid2() & 0xBFFFFFFF);

    if (BootInfo_8064D8F0->consoleType & 0x10000000) {
        BootInfo_8064D8F0->consoleType = 0x10000004;
    } else {
        BootInfo_8064D8F0->consoleType = 1;
    }
    BootInfo_8064D8F0->consoleType += (*(volatile u32*)0xCC00302C >> 28);
    if (!__OSInIPL) {
        __OSInitMemoryProtection();
    }

    OSReport(OSVersion);
    OSReport(KernelBuilt, BuildDate, BuildTime);
    OSReport(ConsoleType);
    bootInfo = BootInfo_8064D8F0;
    if (bootInfo == 0 || (consoleType = bootInfo->consoleType) == 0) {
        consoleType = 0x10000002;
    }
    if (!(consoleType & 0x10000000)) {
        OSReport(Retail, consoleType);
    } else {
        switch (consoleType) {
        case 0x10000000: OSReport(Mac); break;
        case 0x10000001: OSReport(PC); break;
        case 0x10000002: OSReport(Arthur); break;
        case 0x10000003: OSReport(Minnow); break;
        default: OSReport(Development, consoleType - 0x10000003); break;
        }
    }
    OSReport(Memory, BootInfo_8064D8F0->memorySize >> 20);
    OSReport(Arena, OSGetArenaLo(), OSGetArenaHi());
    if (BI2DebugFlag_8064D8F4 != 0 && *BI2DebugFlag_8064D8F4 >= 2) {
        EnableMetroTRKInterrupts();
    }
    ClearArena_80209CA0();
    OSEnableInterrupts();
    if (!__OSInIPL) {
        DVDInit();
        DCInvalidateRange(&DriveInfo_80640D80, 0x20);
        DVDInquiryAsync((u8*)&DriveInfo_80640D80 + 0x20, &DriveInfo_80640D80,
                        InquiryCallback_80209DC8);
    }
}
