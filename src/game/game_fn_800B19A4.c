typedef unsigned int u32;
typedef unsigned char u8;

extern u32 lbl_8064CA6C;
extern u8 lbl_8064CA31;
extern u8 lbl_8064CA30;
extern u32 lbl_8064C9E8;
extern int lbl_8064CE44;

extern int fn_800B194C(void);
extern int fn_800B193C(void);
extern int fn_800B25F4(void);
extern void fn_800B25AC(void);
extern void fn_800B6840(void*);
extern void fn_8001DE68(void);
extern void fn_8017B31C(void (*)(void*));
void fn_800B19A4(void*);

void fn_800B19A4(void* arg)
{
    int state = fn_800B194C();

    lbl_8064CA6C = 0;
    lbl_8064CA31 = 0;
    lbl_8064CA30 = 1;

    if ((unsigned int)(state - 3) <= 3 || state == 0x1A ||
        (unsigned int)(state - 0x24) <= 1 || state == 0xA) {
        if (state == 0xA) {
            lbl_8064C9E8 = 1;
            lbl_8064CE44 = 0;
        }
        while (fn_800B25F4() == 0) {
            fn_800B25AC();
        }
        fn_800B6840(arg);
    }

    if (state == 0x60) {
        lbl_8064C9E8 = 0;
        lbl_8064CE44 = 0;
    }
    fn_8001DE68();
    if (fn_800B193C() != 0) {
        fn_8017B31C(fn_800B19A4);
    }
    if (lbl_8064CE44 != 0) {
        if ((lbl_8064CE44 & 8) != 0) {
            lbl_8064C9E8 = 1;
        }
        lbl_8064CE44 = 0;
    }
}
