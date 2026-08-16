extern int lbl_8064CB00;
extern unsigned short lbl_8064CB04;
extern unsigned char lbl_80325DB8[0xA0];
extern void *memset(void *, int, unsigned int);

void fn_800E790C(void)
{
    if (lbl_8064CB00 == 0) {
        memset(lbl_80325DB8, 0, sizeof(lbl_80325DB8));
        lbl_8064CB04 = 0;
    }
}
