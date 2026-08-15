typedef unsigned char u8;

typedef struct StateSnapshot {
    int value0;
    unsigned int value4;
    int value8;
    unsigned int valueC;
    u8 value10;
    u8 value11;
    u8 value12;
    u8 pad13;
    int value14;
    unsigned int value18;
} StateSnapshot;

extern int lbl_8064CBA0;
extern int lbl_8064CBA4;
extern int lbl_8064D294;
extern unsigned int lbl_803003C8[];
extern void fn_80070EF8(void);
extern unsigned int fn_80144470(int);
extern u8 fn_80045230(void);
extern u8 fn_801A9B30(void);
extern u8 fn_801A9B28(void);

void fn_800AFBA8(StateSnapshot* snapshot)
{
    fn_80070EF8();
    snapshot->value0 = lbl_8064CBA0;
    snapshot->value4 = fn_80144470(1);
    snapshot->value8 = lbl_8064CBA4;
    snapshot->valueC = lbl_803003C8[4];
    snapshot->value10 = fn_80045230();
    snapshot->value14 = lbl_8064D294;
    snapshot->value11 = fn_801A9B30();
    snapshot->value12 = fn_801A9B28();
    snapshot->value18 = lbl_803003C8[0x647];
}
