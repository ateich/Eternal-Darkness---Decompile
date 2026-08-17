extern int fn_8020D318(void*, void*, int);
extern void fn_8020D250(void*, void*, int);
typedef struct Queue { unsigned char data[0x20]; } Queue;
extern Queue lbl_805ADFE0;
extern Queue lbl_805AE000;

void fn_8013824C(void)
{
    while (fn_8020D318(&lbl_805AE000, 0, 0) != 0) {
        fn_8020D250(&lbl_805ADFE0, 0, 0);
    }
}
