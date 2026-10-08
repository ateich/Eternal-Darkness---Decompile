typedef signed short s16;

extern int lbl_8064D18C;
extern int *lbl_8064C5A8;
extern s16 lbl_8023BA30[][5];

extern int fn_80035628(void *);
extern int fn_80048628(void);
extern int fn_801E1ED4(int);
extern int fn_801E2004(int);
extern void *fn_80201814(int);
extern int fn_80201AE4(void);
extern int fn_80201EB8(void *);

int fn_800DE298(void *object)
{
    int owner = fn_80201AE4();
    int index;

    if (lbl_8064D18C == fn_80201EB8(fn_80201814(owner)) &&
        fn_801E1ED4(owner) != 0) {
        int state = fn_801E2004(owner);

        if (object != 0) {
            index = fn_80035628(object);
        } else {
            index = *lbl_8064C5A8;
        }

        if (lbl_8023BA30[state][index] == 1 && fn_80048628() == 0) {
            return 1;
        }
    }
    return 0;
}
