extern void *lbl_8064C4E0;
extern int lbl_8064D18C;

extern int fn_80201910(int);
extern void fn_801E7974(void *, int);
extern int fn_80201B44(void);
extern int fn_802066E0(int, unsigned int);
extern void fn_8011E26C(int);

void fn_800E4010(int id)
{
    int value = fn_80201910(id);

    fn_801E7974(lbl_8064C4E0, value);
    if (lbl_8064D18C == 213) {
        if (fn_802066E0(fn_80201B44(), 0xE98A39BB) != 0)
            fn_8011E26C(1);
    }
}
