extern void *lbl_8064C4E0;
extern int fn_80201B54();
extern int fn_80201910(int);
extern int fn_801E79FC(void *, int);
extern int fn_80201B64(void *);
extern unsigned long long fn_8020123C();

void fn_800E7FA4(void *object)
{
    int handle = fn_80201B54(object);
    int id = fn_80201910(handle);

    if (fn_801E79FC(lbl_8064C4E0, id) != 0 && fn_80201B64(object) == 1) {
        fn_8020123C(18, handle, handle, 0);
    }
}
