typedef unsigned int u32;

typedef struct Header {
    int value;
    short id;
    unsigned char pad[14];
} Header;

extern unsigned char lbl_805AE380[0x400];
extern Header lbl_805AE780;
extern unsigned char* lbl_8064CFDC;

extern void* memset(void*, int, u32);
extern void fn_80138E9C(void);

void fn_80138F78(int reset)
{
    lbl_8064CFDC = lbl_805AE380;
    if (reset != 0) {
        memset(&lbl_805AE780, 0, sizeof(Header));
        memset(lbl_8064CFDC, 0, 0x400);
        lbl_805AE780.id = -1;
        lbl_805AE780.value = -1;
    }
    fn_80138E9C();
}
