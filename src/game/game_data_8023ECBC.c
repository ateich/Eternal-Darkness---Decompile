typedef unsigned int u32;

extern char fn_800473AC[];

#pragma force_active on
u32 jumptable_8023ECBC[11] = {
    (u32)(fn_800473AC + 0x40), (u32)(fn_800473AC + 0x6C),
    (u32)(fn_800473AC + 0x6C), (u32)(fn_800473AC + 0x6C),
    (u32)(fn_800473AC + 0x6C), (u32)(fn_800473AC + 0x5C),
    (u32)(fn_800473AC + 0x6C), (u32)(fn_800473AC + 0x6C),
    (u32)(fn_800473AC + 0x54), (u32)(fn_800473AC + 0x6C),
    (u32)(fn_800473AC + 0x5C),
};
#pragma force_active reset
