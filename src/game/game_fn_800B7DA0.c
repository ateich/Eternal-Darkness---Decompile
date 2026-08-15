extern void *lbl_8064CA10[2];
extern unsigned int *fn_801E5D20(void *);
extern void fn_801E6328(void *, int, int);
extern int fn_801E6420(void *);

void fn_800B7DA0(int x, int y)
{
    int i;

    for (i = 0; i < 2; i++) {
        unsigned int *flags = fn_801E5D20(lbl_8064CA10[i]);
        *flags |= 2;
    }
    fn_801E6328(lbl_8064CA10[0], x, y);
    fn_801E6328(lbl_8064CA10[1], x,
                (short)(y + fn_801E6420(lbl_8064CA10[0]) + 10));
}
