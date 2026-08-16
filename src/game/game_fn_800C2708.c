typedef unsigned char u8;

extern int lbl_8064D18C;
extern int lbl_8064C4E0;
extern u8 lbl_803003C8[];
extern u8 lbl_80248724[];
extern u8 lbl_80248718[];

extern int fn_801E79FC(int, int);
extern void fn_8014C23C(int, int, int);
extern void *fn_801E741C();
extern void fn_8015C948(int, void *, void *, int, int, int, int, int, int, int,
                        int);
extern void *fn_80201814();
extern void **fn_80201B8C();
extern unsigned long long fn_8020123C();

int fn_800C2708(int unused, void *object)
{
    if (lbl_8064D18C == 255 && *(int *)(lbl_803003C8 + 8) == 5 &&
        fn_801E79FC(lbl_8064C4E0, 883) != 0) {
        fn_8014C23C(20, 0, 0);
        fn_8015C948(252, fn_801E741C(lbl_80248718),
                    fn_801E741C(lbl_80248724), 2779,
                    0, 0, 0, 0, 0, 0, 1);
    } else {
        void **state;
        void *entry;

        state = fn_80201B8C(fn_80201814(object));
        entry = state != 0 ? state[35] : 0;
        if (entry != 0) {
            fn_8020123C(81, object, *(int *)((u8 *)entry + 0x44), 0);
        }
    }
    return 1;
}
