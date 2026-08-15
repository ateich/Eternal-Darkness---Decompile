typedef unsigned short u16;

extern unsigned char lbl_8031F7C0[];
extern int lbl_8064C5BC;
extern void* fn_80201B3C(void);
extern u16 fn_800B9578(void*, void*, unsigned int*, int);

int fn_800AFDA4(void)
{
    unsigned char* buffer = lbl_8031F7C0;
    void* current;
    unsigned int value;

    current = fn_80201B3C();
    if (buffer != 0 && current != 0) {
        value = 0;
        if (fn_800B9578(buffer, current, &value, 0) > 0xF00) {
            return 0;
        }
        lbl_8064C5BC = 1;
        return 1;
    }
    return 0;
}
