typedef unsigned int u32;

extern char fn_8004998C[];

#define CASE(offset) (u32)(fn_8004998C + (offset))

#pragma force_active on
u32 jumptable_8023EF34[20] = {
    CASE(0x110), CASE(0xB8),  CASE(0xB8),  CASE(0xB8),  CASE(0xB8),
    CASE(0xB8),  CASE(0xB8),  CASE(0xB8),  CASE(0xB8),  CASE(0xB8),
    CASE(0xF8),  CASE(0xF8),  CASE(0xD0),  CASE(0xE4),  CASE(0xD0),
    CASE(0x110), CASE(0x110), CASE(0x110), CASE(0x110), CASE(0x110),
};
#pragma force_active reset
