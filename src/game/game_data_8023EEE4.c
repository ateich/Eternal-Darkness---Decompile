typedef unsigned int u32;

extern char fn_8004998C[];

#define CASE(offset) (u32)(fn_8004998C + (offset))

#pragma force_active on
u32 jumptable_8023EEE4[20] = {
    CASE(0x334), CASE(0x334), CASE(0x334), CASE(0x334), CASE(0x334),
    CASE(0x334), CASE(0x334), CASE(0x334), CASE(0x334), CASE(0x334),
    CASE(0x320), CASE(0x320), CASE(0x2F4), CASE(0x30C), CASE(0x2F4),
    CASE(0x334), CASE(0x2E0), CASE(0x2E0), CASE(0x334), CASE(0x320),
};
#pragma force_active reset
