typedef signed short s16;
typedef unsigned short u16;

typedef struct Entry {
    s16 id;
    u16 value2;
    u16 value4;
    u16 value6;
} Entry;

extern Entry lbl_805FAA60[10];
extern char lbl_8024FEA8[];
extern char lbl_8024FECC[];
extern int fn_80048610(s16);
extern void fn_801E7DCC(char*, ...);
extern void fn_801E807C(int, int, char*, ...);
extern void fn_801E8170(int, int, int);

void fn_8016AD28(void)
{
    int i;
    int count;

    i = 0;
    count = 0;

    do {
        if (fn_80048610(lbl_805FAA60[i].id) == 0 && lbl_805FAA60[i].id > 0 &&
            lbl_805FAA60[i].value6 != 0) {
            count++;
        }
        i++;
    } while (i < 10);

    if ((u16)count != 0) {
        u16 value = count;
        fn_801E7DCC(lbl_8024FEA8, value);
        fn_801E807C(0x50, 0x2D, lbl_8024FECC, value);
        fn_801E8170(0x50, 0x2D, 1);
    }
}
