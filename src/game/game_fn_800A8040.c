extern void* lbl_8064C98C;
extern void* lbl_8064D18C;
extern float lbl_8064EF30;

extern void* fn_80201814();
extern void* fn_80201BC8();
extern int fn_800A8034(void*);
extern void* fn_8011F130(void*);
extern void fn_801DC2B8(void*, void*, void*, void*, int);
extern void fn_8020104C(int, void*, void*, int, float);

int fn_800A8040(void)
{
    void* object = fn_80201814(lbl_8064C98C);
    void* owner = fn_80201BC8();
    void* kind = (void*)fn_800A8034(object);
    void* position = fn_8011F130(owner);

    fn_801DC2B8(lbl_8064D18C, kind, lbl_8064C98C, position, 0);
    fn_8020104C(0xFA, lbl_8064C98C, lbl_8064C98C, 10, lbl_8064EF30);
    return 1;
}
