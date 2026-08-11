typedef unsigned int u32;

extern char fn_8004998C[];

#define CASE(offset) (u32)(fn_8004998C + (offset))

#pragma force_active on
u32 jumptable_8023EE94[20] = {
    CASE(0x40C), CASE(0x40C), CASE(0x40C), CASE(0x40C), CASE(0x40C),
    CASE(0x40C), CASE(0x40C), CASE(0x40C), CASE(0x40C), CASE(0x40C),
    CASE(0x3F8), CASE(0x3F8), CASE(0x3D0), CASE(0x3E4), CASE(0x3D0),
    CASE(0x40C), CASE(0x3BC), CASE(0x3BC), CASE(0x40C), CASE(0x3F8),
};
#pragma force_active reset
