typedef unsigned char u8;

static u8 slots[0xF0];
static u8 work[0x24C0];
static u8 quads[0x7E0];
extern u8 lbl_8064D038;
extern void* memset(void*, int, unsigned int);

void fn_80142944(void)
{
    memset(slots, 0, sizeof(slots));
    memset(work, 0, sizeof(work));
    memset(quads, 0, sizeof(quads));
    lbl_8064D038 = 0;
}
