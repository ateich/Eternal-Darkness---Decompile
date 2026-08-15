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
extern unsigned int lbl_803003C8[];
extern void fn_801ECB40(u8);
extern void fn_80144430(int, int);
extern void fn_80045220(u8);
extern void fn_801A96A8(int, int, int);
extern void fn_801A9A40(int, u8, u8);

void fn_800AFC30(StateSnapshot* snapshot)
{
    int value = snapshot->value0;

    lbl_8064CBA0 = value;
    fn_801ECB40((u8)value);
    fn_80144430(-1, 0);
    fn_80144430(snapshot->value4, 1);
    lbl_8064CBA4 = snapshot->value8;
    lbl_803003C8[4] = snapshot->valueC;
    fn_80045220(snapshot->value10);
    fn_801A96A8(snapshot->value14, 0, 1);
    fn_801A9A40(2, snapshot->value12, snapshot->value11);
    lbl_803003C8[0x647] = snapshot->value18;
}
