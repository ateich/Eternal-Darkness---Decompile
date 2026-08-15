typedef unsigned char u8;
typedef unsigned long long u64;

extern u8 lbl_80320738[];
extern unsigned int lbl_8064CA50;
extern unsigned int lbl_8064CA54;

extern void fn_800B25AC(void);
extern void fn_800B6840(int);
extern int fn_800B6A24(void);
extern int fn_800B6908(void);
extern u64 fn_8017B440(int);
extern void fn_800B2548(int, int);

#define GLOBAL_ID (((u64)lbl_8064CA50 << 32) | lbl_8064CA54)

void fn_800B3304(int value, int mode)
{
    u8* entry;
    int state;

    fn_800B25AC();
    switch (mode) {
    case 0:
        fn_800B6840(value);
        break;
    case 1:
        entry = lbl_80320738 + lbl_80320738[fn_800B6A24() + 0x1B0] * 0x38 + 0x28;
        state = fn_800B6908();
        switch (*(int*)entry) {
        case 0:
            if (state == 0) {
                if (GLOBAL_ID != 0 && GLOBAL_ID != fn_8017B440(value)) {
                    fn_800B2548(0x25, value);
                } else {
                    fn_800B2548(5, value);
                }
            } else {
                fn_800B2548(0x61, value);
            }
            break;
        case 1:
            if (state == 1) {
                if (*(int*)(entry + 0x2C) == 0x6C) {
                    fn_800B2548(6, value);
                } else {
                    fn_800B2548(0x61, value);
                }
            } else if (GLOBAL_ID != 0 && GLOBAL_ID != fn_8017B440(value)) {
                fn_800B2548(0x25, value);
            } else if (*(int*)(entry + 0x2C) == 0x6C) {
                fn_800B2548(4, value);
            } else {
                fn_800B2548(5, value);
            }
            break;
        default:
            fn_800B2548(0x61, value);
            break;
        }
        break;
    }
}
