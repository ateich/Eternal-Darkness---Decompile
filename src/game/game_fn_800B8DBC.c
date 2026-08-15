extern void *lbl_8064CA0C;
extern void *lbl_80320B48[3];
extern void fn_801E5FB0(void *);
extern void fn_800B84A8(void);

void fn_800B8DBC(void)
{
    int i;

    if (lbl_8064CA0C != 0) {
        fn_801E5FB0(lbl_8064CA0C);
    }
    for (i = 0; i < 3; i++) {
        if (lbl_80320B48[i] != 0) {
            fn_801E5FB0(lbl_80320B48[i]);
        }
    }
    fn_800B84A8();
}
