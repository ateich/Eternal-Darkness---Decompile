extern unsigned char lbl_805B6FFC[];
extern unsigned char lbl_805E27DC[];
extern unsigned char lbl_805DB240[];

extern void fn_8020D250(void*, int, int);
extern int fn_8020D318(void*, unsigned int*, int);

void fn_8015CB00(int mode)
{
    int i = 0;

    if (mode == 1) {
        unsigned int message;

        fn_8020D250(lbl_805B6FFC, -1, 1);
        fn_8020D250(lbl_805E27DC, -1, 1);
        do {
            fn_8020D318(lbl_805DB240, &message, 1);
            i++;
        } while (i < 2);
    } else {
        fn_8020D250(lbl_805B6FFC, -2, 1);
        fn_8020D250(lbl_805E27DC, -2, 1);
    }
}
