typedef unsigned char u8;

typedef struct StateBlock {
    u8 data[0x1B8];
} StateBlock;

extern StateBlock lbl_80320738;
extern StateBlock lbl_80320978;
extern int lbl_8064CA64;
extern int lbl_8064CA60;
extern int lbl_8064CA6C;
extern char lbl_80247434[];

extern void fn_800B25AC(void);
extern int fn_800B6A24(void);
extern int fn_800BBE18(void*);
extern void fn_800BBF6C(int);
extern void fn_8017B864(int);
extern void fn_8017B914(int);
extern void fn_800B261C(int);
extern void fn_800B5BD0(void);
extern void fn_800B2624(int, int, void*, int, void (*)(void));
extern void fn_800B2548(int, int);

void fn_800B3C78(int value, int mode)
{
    int offset;

    fn_800B25AC();
    switch (mode) {
    case 0:
        offset = fn_800B6A24();
        lbl_80320978 = lbl_80320738;
        *(int*)(lbl_80320978.data + lbl_80320978.data[offset + 0x1B0] * 0x38 + 0x28) = 0;
        *(int*)(lbl_80320978.data + 0x20) = fn_800BBE18(&lbl_80320978);
        fn_800BBF6C(value);
        fn_8017B864(0x2000);
        fn_8017B914(0);
        fn_800B261C(0);
        lbl_8064CA64 = 1;
        lbl_8064CA60 = 0;
        fn_800B2624(6, value, lbl_80247434, 1, fn_800B5BD0);
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
