typedef signed int s32;

extern s32 lbl_8064D18C;
extern char lbl_80243EDC[];

extern void *fn_801E741C(char *name);
extern int fn_80201B44();
extern s32 fn_802066E0(void *object, void *value);
extern void fn_8011E26C(s32 value);

void fn_8006B1C0(void)
{
    void *value;

    if (lbl_8064D18C == 0xB6) {
        value = fn_801E741C(lbl_80243EDC);
        if (fn_802066E0((void *)fn_80201B44(), value)) {
            fn_8011E26C(1);
        }
    }
}
