typedef signed int s32;
typedef unsigned int u32;

extern void *fn_80201BC8();
extern u32 fn_8011F950(void *object);
extern void *fn_801294DC(void *, int, int, int);
extern void fn_801E7974(void *manager, s32 kind);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

extern void *lbl_8064C4E0;
extern u32 lbl_8064C8A8;

void fn_8006AA88(s32 object)
{
    void *actor;

    actor = fn_80201BC8();
    lbl_8064C8A8 = 0;
    fn_801E7974(lbl_8064C4E0, 0x54);
    if (actor != 0 && fn_8011F950(actor) != 0) {
        fn_801294DC(actor, 15, 1, 1);
    }
    fn_80201D2C((void *)object, 1);
    fn_80201D14((void *)object, 1);
}
