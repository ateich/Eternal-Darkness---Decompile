/*
 * Honest-C recovery of the large effect/state initializer. The first-pass
 * state reset is recovered here; the retail routine continues with indexed
 * resource validation and effect dispatch and intentionally stays
 * NonMatching while those aggregate layouts are identified.
 */
typedef struct Runtime Runtime;

extern char lbl_8030F540[];
extern int lbl_8064CF6C;
extern int lbl_8064CF40;
extern int lbl_80651BA0;
extern Runtime* fn_8015E4A4(void);
extern void fn_801313D8(void);
extern void fn_801F348C(int*, int);
extern void fn_801FA410(int);

void fn_80131460(void)
{
    Runtime* runtime = fn_8015E4A4();
    int state = *(int*)(lbl_8030F540 + 0x1C8);

    lbl_8064CF6C = 0;
    if (state == 0) {
        int timer;

        fn_801313D8();
        *(int*)(lbl_8030F540 + 0x1CC) = 0;
        timer = lbl_80651BA0;
        fn_801F348C(&timer, 100);
        lbl_8064CF40 = 0;
        fn_801FA410(9);
    }

    /* Retain the runtime acquisition: later recovered phases consume it. */
    (void)runtime;
}
