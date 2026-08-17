typedef unsigned int u32;

extern u32 lbl_8064CFFC;
extern u32 lbl_8064D000;
extern unsigned char* lbl_8064D004;
extern unsigned char* lbl_8064CFC0;
extern u32 lbl_8064D00C;
extern u32 lbl_8064D010;
extern int lbl_805AE000;
extern int lbl_805ADFE0;

extern int fn_8020D250(void*, int, int);
extern int fn_8020D318(void*, int, int);

void* fn_80138A6C(u32 size, int mode)
{
    u32 aligned = (size + 31) & ~31;
    unsigned char* result;

    if (mode == 1) {
        u32 old = lbl_8064D000;
        lbl_8064D000 = old + aligned;
        result = lbl_8064D004 + old;
        if (lbl_8064D000 > lbl_8064CFFC) {
            lbl_8064D000 -= aligned;
            result = 0;
        }
    } else {
        int retry = 1;
        do {
            u32 old = lbl_8064D010;
            lbl_8064D010 = old + aligned;
            result = lbl_8064CFC0 + old;
            if (lbl_8064D010 > 0x3D3100 - lbl_8064D00C) {
                if (lbl_8064D00C == 0 || !retry) {
                    result = 0;
                    break;
                }
                lbl_8064D010 -= aligned;
                retry = 0;
                fn_8020D250(&lbl_805AE000, 0, 1);
                fn_8020D318(&lbl_805ADFE0, 0, 1);
            } else {
                retry = 1;
            }
        } while (!retry);
    }
    return result;
}
