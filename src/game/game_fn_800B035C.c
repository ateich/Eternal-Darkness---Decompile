extern unsigned char lbl_8031F7C0[];
extern int lbl_8064D18C;
extern int lbl_8064CDC4;
extern void* fn_80201B3C(void);
extern void *fn_80201BC8();
extern void* memcpy(void*, const void*, unsigned int);
extern void fn_800B01D8(void);
extern void fn_8015C948(void*, int, int, int, int, int, int, int,
                       void (*)(void), void*, int);

int fn_800B035C(void)
{
    unsigned char* buffer = lbl_8031F7C0;
    void* current;
    int value;

    current = fn_80201B3C();
    if (buffer != 0 && current != 0) {
        fn_80201BC8(current);
        memcpy(&value, buffer + 16, 4);
        if (value != lbl_8064D18C) {
            lbl_8064CDC4 = 0;
        }
        fn_8015C948((void*)value, 0, 0, 0, 68, 1, 1, 17,
                    fn_800B01D8, 0, 1);
        return 1;
    }
    return 0;
}
