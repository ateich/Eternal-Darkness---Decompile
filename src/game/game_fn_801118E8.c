extern int lbl_803003C8[];
extern unsigned int* lbl_8064C4E0;
extern void fn_80201B44(void);
extern void* fn_80201814(void);
extern unsigned int fn_8020216C(void);
extern void* fn_80201C2C(void*);
extern void* fn_802051A4(void*);
extern void* fn_80205134(void*);
extern void fn_80201C24(void*);
extern int fn_8015821C(void);
extern int fn_801E79FC(unsigned int*, int);

int fn_801118E8(void)
{
    void* item;

    fn_80201B44();
    item = fn_80201814();
    fn_80201B44();
    fn_80201814();
    if ((fn_8020216C() & 0x4000) != 0) {
        return 1;
    }
    if (lbl_803003C8[2] == 2) {
        return 0;
    }
    if (lbl_803003C8[2] == 0 && fn_801E79FC(lbl_8064C4E0, 0x133) == 0) {
        return 0;
    }
    item = fn_802051A4(fn_80201C2C(item));
    while (item != 0) {
        fn_80205134(item);
        {
            void* object = fn_80201814();
            if (object != 0) {
              fn_80201C24(object);
              switch (fn_8015821C()) {
              case 30:
              case 120:
                return 1;
              }
            }
        }
        item = fn_802051A4(item);
    }
    return 0;
}
