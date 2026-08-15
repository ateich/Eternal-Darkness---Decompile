typedef unsigned char u8;
typedef unsigned short u16;

#pragma use_lmw_stmw on

extern char lbl_80320738[];
extern int lbl_8064CDC8;
extern int lbl_8064CA64;
extern int lbl_8064CA60;
extern u8 lbl_8064CA31;
extern u8 lbl_8064CA30;
extern int lbl_8064CA6C;
extern char lbl_80247434[];

extern void fn_800B25AC(void);
extern int fn_8017B7DC(void);
extern int fn_8017BA24(void);
extern int fn_800BBF2C(void*);
extern u16 fn_800B09D0(int, int, int);
extern void fn_8017B864(int);
extern void fn_8017B914(int);
extern void fn_800B261C(int);
extern void fn_800B5438(void);
extern void fn_800B2624(int, int, void*, int, void (*)(void));
extern void fn_800B2548(int, int);

void fn_800B35AC(int value, int mode, int enabled)
{
    int first;
    int second;
    int code;

    fn_800B25AC();
    switch (mode) {
    case 0:
        first = fn_8017B7DC();
        second = fn_8017BA24();
        code = fn_800BBF2C(lbl_80320738);
        lbl_8064CA64 = 1;
        if (fn_800B09D0(second, first, lbl_8064CDC8 == 3) <= 0x4000) {
            lbl_8064CA60 = 0;
            fn_8017B864(0x4000);
            fn_8017B914(((code & 0xFF) << 14) + 0x2000);
            fn_800B261C(0);
            lbl_8064CA30 = 2;
            lbl_8064CA31++;
            if (enabled != 0) {
                fn_800B2624(6, value, lbl_80247434, 1, fn_800B5438);
            } else {
                fn_800B2624(6, value, lbl_80247434, 0, fn_800B5438);
            }
        }
        break;
    case 1:
        if (lbl_8064CA6C != 0) {
            fn_800B2548(3, value);
        } else {
            fn_800B2548(1, value);
        }
        break;
    }
}
