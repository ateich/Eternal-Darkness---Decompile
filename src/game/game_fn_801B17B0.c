typedef unsigned int u32;

typedef struct Entry {
    unsigned char pad000[0x10];
    u32 state;
} Entry;

extern volatile u32 lbl_8064D33C;
extern Entry* lbl_8064D348;
extern u32 lbl_8064D324;
extern unsigned char lbl_8060BFF0[];

extern void fn_801B1028(void);
extern void fn_801B10A4(Entry*, u32);
extern void fn_801B1194(void);
extern void fn_801B11CC(void);
extern void fn_801B1410(void);
extern void fn_80215830(void*, void (*)(void));
extern void fn_8021A1A8(int);
extern void fn_8021A468(int);
extern void fn_8021A494(int);

void fn_801B17B0(int state)
{
    if (lbl_8064D33C == state || lbl_8064D33C == 3) {
        return;
    }

    switch (state) {
    case 0:
        if (lbl_8064D348 != 0) {
            lbl_8064D348->state = 0;
            lbl_8064D33C = 3;
            fn_8021A468(0);
            fn_8021A494(0);
            fn_8021A1A8(0);
            fn_80215830(lbl_8060BFF0, fn_801B1410);
        }
        break;
    case 1:
        if (lbl_8064D33C == 2) {
            fn_801B1028();
            lbl_8064D33C = 1;
            if (lbl_8064D348 != 0) {
                fn_801B10A4(lbl_8064D348, 1);
            }
        } else if (lbl_8064D348 != 0) {
            lbl_8064D33C = 3;
            fn_801B1194();
        } else {
            lbl_8064D33C = 1;
        }
        lbl_8064D324 = 0;
        break;
    case 4:
        if (lbl_8064D33C == 0) {
            if (lbl_8064D348 != 0) {
                lbl_8064D33C = 3;
                fn_801B11CC();
            }
            lbl_8064D324 = 0;
        }
        break;
    case 2:
        fn_8021A1A8(0);
        if (lbl_8064D33C == 1) {
            lbl_8064D33C = 2;
        }
        if (lbl_8064D348 != 0) {
            fn_801B10A4(lbl_8064D348, 4);
        }
        break;
    }
}
