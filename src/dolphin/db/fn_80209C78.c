typedef unsigned int u32;

typedef struct OSBootInfo {
    unsigned char pad[0x2C];
    u32 console_type;
} OSBootInfo;

extern OSBootInfo* BootInfo_8064D8F0;

u32 OSGetConsoleType(void)
{
    volatile OSBootInfo* boot_info = BootInfo_8064D8F0;
    u32 console_type;

    if (boot_info == 0 || (console_type = boot_info->console_type) == 0) {
        console_type = 0x10000002;
    }
    return console_type;
}
