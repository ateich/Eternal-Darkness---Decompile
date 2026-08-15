typedef unsigned char u8;

extern u8 lbl_80320738[];

extern int fn_800B6908(void);
extern void fn_800B25AC(void);
extern int fn_800B6A24(void);
extern void fn_800B2548(int, int);
extern void fn_800B6840(int);

void fn_800B40FC(int value, int mode)
{
    u8* entry;

    fn_800B6908();
    fn_800B25AC();
    switch (mode) {
    case 0:
        entry = lbl_80320738 + lbl_80320738[fn_800B6A24() + 0x1B0] * 0x38 + 0x28;
        switch (*(int*)entry) {
        case 0:
            fn_800B2548(5, value);
            break;
        case 1:
            if (*(int*)(entry + 0x2C) == 0x6C) {
                fn_800B2548(4, value);
            } else {
                fn_800B2548(5, value);
            }
            break;
        }
        break;
    case 1:
    case 2:
        fn_800B6840(value);
        break;
    }
}
