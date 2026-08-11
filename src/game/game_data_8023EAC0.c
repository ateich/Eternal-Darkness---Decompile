typedef unsigned int u32;

extern char fn_800433FC[];

#pragma force_active on
u32 jumptable_8023EAC0[10] = {
    (u32)(fn_800433FC + 0x20C), (u32)(fn_800433FC + 0x64),
    (u32)(fn_800433FC + 0x20C), (u32)(fn_800433FC + 0x88),
    (u32)(fn_800433FC + 0x20C), (u32)(fn_800433FC + 0xAC),
    (u32)(fn_800433FC + 0x20C), (u32)(fn_800433FC + 0xFC),
    (u32)(fn_800433FC + 0x20C), (u32)(fn_800433FC + 0x1BC),
};
#pragma force_active reset
