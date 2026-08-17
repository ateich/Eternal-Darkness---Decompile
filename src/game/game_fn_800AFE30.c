typedef unsigned short u16;

extern unsigned char lbl_8031F7C0[];
extern int lbl_8064C5BC;
extern void* fn_80201B3C();
extern void fn_800BA6D4(void*, int, u16*, int, int);

int fn_800AFE30(void)
{
    unsigned char* buffer = lbl_8031F7C0;
    void* current;
    u16 value;

    current = fn_80201B3C();
    if (buffer != 0 && current != 0) {
        value = 0;
        fn_800BA6D4(buffer, 0, &value, 0, 0);
        if (value > 0xF00) {
            return 0;
        }
        lbl_8064C5BC = 0;
        return 1;
    }
    return 0;
}
