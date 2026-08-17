extern void* memset(void*, int, unsigned int);
extern int lbl_8064D080;
extern unsigned char lbl_805B4400[];

void fn_8014939C(void)
{
    memset(lbl_805B4400, 0, 0x620);
    lbl_8064D080 = 0;
}
