typedef unsigned char u8;
typedef unsigned int u32;

#pragma use_lmw_stmw on

typedef struct StateRecord {
    u32 words[8];
} StateRecord;

extern const StateRecord lbl_80238B74;
extern const StateRecord lbl_80238B94;
extern u8 lbl_8023D77C[];
extern u32 lbl_8030241C[];

extern void fn_800B18F8(void);
extern void fn_800B7D20(void);
extern void fn_8001DE84(int, int);
extern int fn_801A98F4(int, int);

void fn_80023710(void)
{
    StateRecord* records;

    fn_800B18F8();
    fn_800B7D20();
    records = (StateRecord*)(lbl_8023D77C + 0x60);
    records[0] = lbl_80238B74;
    records[1] = lbl_80238B94;
    fn_8001DE84(7, 1);
    lbl_8030241C[14] = fn_801A98F4(0x276, 100);
    lbl_8030241C[10] = 5;
}
