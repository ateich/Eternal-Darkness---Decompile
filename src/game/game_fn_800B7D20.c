extern void *lbl_8064CA10[2];
extern void fn_801E5FB0(void *);
extern void fn_800B7C6C(void);

void fn_800B7D20(void)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (lbl_8064CA10[i] != 0) {
            fn_801E5FB0(lbl_8064CA10[i]);
        }
    }
    fn_800B7C6C();
}
