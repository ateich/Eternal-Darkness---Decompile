typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Block {
    u32 words[8];
} Block;

extern Block lbl_80238BB4;
extern Block lbl_80238BD4;
extern u8 lbl_8023D77C[];
extern u8 lbl_8030241C[];
extern u32 lbl_8064CA68;

extern void fn_800B18F8(void);
extern void fn_8001DA7C(void);

void fn_80023B40(void)
{
    lbl_8064CA68 = 0;
    fn_800B18F8();
    fn_8001DA7C();
    *(u32*)(lbl_8030241C + 0x14) = 0xFF;
    lbl_8030241C[0x3E] = 10;
    *(Block*)(lbl_8023D77C + 0x60) = lbl_80238BB4;
    *(Block*)(lbl_8023D77C + 0x80) = lbl_80238BD4;
}
