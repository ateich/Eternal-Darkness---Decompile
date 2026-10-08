typedef unsigned char u8;

typedef struct CardInfo {
    u8 pad_00[0x20];
    int size;
} CardInfo;

typedef struct SaveCard SaveCard;

extern int lbl_8064CA60;
extern int lbl_8064CA64;
extern char lbl_80247434[];

extern int fn_8017B1AC(int, void*);
extern CardInfo* fn_8017B9C4(int);
extern void fn_8017B8BC(int);
extern void fn_8017B96C(int);
extern void fn_800B261C(int);
extern void fn_800B4D5C(SaveCard*);
extern void fn_800B2624(int, int, void*, int, void (*)(SaveCard*));
extern void fn_800B5D94(int);

void fn_800B5DDC(int value)
{
    if (fn_8017B1AC(value, lbl_80247434) == 0) {
        if (fn_8017B9C4(value)->size == 0x1E000) {
            fn_8017B8BC(0x2000);
            fn_8017B96C(0);
            fn_800B261C(1);
            lbl_8064CA64 = 1;
            lbl_8064CA60 = 0;
            fn_800B2624(7, value, lbl_80247434, 0, fn_800B4D5C);
            return;
        }
        fn_800B5D94(value);
        return;
    }
    fn_800B5D94(value);
}
