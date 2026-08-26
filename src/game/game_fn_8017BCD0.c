typedef unsigned short u16;

extern unsigned char lbl_8064A7C8[];
extern int fn_8017BB24(void);
extern void* fn_8017BB44(void);
extern void* memset(void*, int, unsigned int);

int fn_8017BCD0(void)
{
    if (fn_8017BB24() == 0) {
        memset(fn_8017BB44(), 0, 0x48);
        {
            u16* queue = (u16*)lbl_8064A7C8;
            if (++queue[1] >= 6) {
                queue[1] = 0;
            }
        }
        return 1;
    }
    return 0;
}
