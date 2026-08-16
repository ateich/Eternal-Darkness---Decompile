extern void *lbl_8064C4E0;

extern void *fn_80201B9C();
extern int fn_80201B5C(void *);
extern void *fn_80201BC0(void *);
extern int fn_801E79FC(void *, int);
extern void fn_801EF38C(int);
extern void fn_800CE3D8(void *);
extern void fn_800CE5A8(void *);

void fn_800CA5C0(void)
{
    void *object;

    object = fn_80201B9C();
    while (object != 0) {
        switch (fn_80201B5C(object)) {
        case 0x16:
            if (fn_801E79FC(lbl_8064C4E0, 0x2ED) != 0) {
                fn_801EF38C(1);
                fn_800CE3D8(object);
            } else {
                fn_801EF38C(0);
            }
            break;
        case 0x17:
            fn_800CE5A8(object);
            break;
        }
        object = fn_80201BC0(object);
    }
}
