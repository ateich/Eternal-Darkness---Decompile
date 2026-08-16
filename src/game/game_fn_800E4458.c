extern int fn_80201B54();
extern int fn_80201910(int);
extern int fn_801E79FC(void *, int);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_801E79A0(void *, int);
extern void *lbl_8064C4E0;

void fn_800E4458(int id)
{
    int value;

    value = fn_80201910(fn_80201B54(id));
    if (fn_801E79FC(lbl_8064C4E0, value) == 0) {
        fn_80201D2C((void *)id, 1);
        fn_80201D14((void *)id, 1);
    } else {
        fn_80201D2C((void *)id, 14);
        fn_80201D14((void *)id, 1);
        fn_801E79A0(lbl_8064C4E0, 226);
    }
}
