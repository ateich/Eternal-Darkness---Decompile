typedef unsigned int u32;

extern char fn_80046430[];

#define CASE_CHECK (u32)(fn_80046430 + 0x214)
#define CASE_DONE (u32)(fn_80046430 + 0x244)

#pragma force_active on
u32 jumptable_8023EC18[14] = {
    CASE_CHECK, CASE_DONE,  CASE_CHECK, CASE_CHECK, CASE_DONE,
    CASE_CHECK, CASE_DONE,  CASE_DONE,  CASE_DONE,  CASE_DONE,
    CASE_DONE,  CASE_DONE,  CASE_DONE,  CASE_CHECK,
};
#pragma force_active reset
