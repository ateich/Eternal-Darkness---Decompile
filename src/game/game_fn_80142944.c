typedef unsigned char u8;
typedef struct Pools {
    u8 slots[0xF0];
    u8 work[0x24C0];
    u8 quads[0x7E0];
} Pools;
extern Pools lbl_805B1310;
extern u8 lbl_8064D038;
extern void* memset(void*, int, unsigned int);

void fn_80142944(void)
{
    Pools* pools = &lbl_805B1310;
    memset(pools->slots, 0, 0xF0);
    memset(pools->work, 0, 0x24C0);
    memset(pools->quads, 0, 0x7E0);
    lbl_8064D038 = 0;
}
