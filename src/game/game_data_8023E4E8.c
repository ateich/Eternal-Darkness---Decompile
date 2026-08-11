typedef unsigned int u32;

extern char fn_800361F8[];

#pragma force_active on
u32 jumptable_8023E4E8[10] = {
    (u32)(fn_800361F8 + 0x78),  (u32)(fn_800361F8 + 0xD4),
    (u32)(fn_800361F8 + 0x120), (u32)(fn_800361F8 + 0x16C),
    (u32)(fn_800361F8 + 0x174), (u32)(fn_800361F8 + 0x174),
    (u32)(fn_800361F8 + 0x174), (u32)(fn_800361F8 + 0x174),
    (u32)(fn_800361F8 + 0x174), (u32)(fn_800361F8 + 0x2C),
};
#pragma force_active reset
