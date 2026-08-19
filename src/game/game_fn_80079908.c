extern int lbl_8064D18C;
extern void *fn_80201BC8();
extern int fn_80201B54();
extern int fn_80201EB8();
extern int fn_80079008(void *object, void *resource);
extern void fn_800CA2C8(void *object);
extern int fn_801E8328();
extern void *fn_801294DC(void *, int, int, int);
extern int fn_8012A1FC(void *resource, int type);
extern int fn_8012A1BC(void *resource, int type);
extern void fn_80129FD0(void *resource, int value, int flags);
extern void fn_800798C4(void *object);
extern void fn_801287C4(void *action, void (*callback)(void *), void *arg, int value);
extern int fn_800389E0(void *object, int, int, int);
extern void fn_80204810(void *object);
extern void fn_80128A84(void *action, int, int);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_80201138(int, void *, int, int, int, float);

/* NonMatching: instruction-identical; the split TU gives MWCC's generated
 * signed-int conversion bias the local name @18 instead of lbl_8064E930. */
void fn_80079908(void *object, int unused, int requested)
{
    void *action;
    void *resource = fn_80201BC8(object);
    int owner = fn_80201B54(object);
    int context = fn_80201EB8(object);
    int state = fn_80079008(object, resource);

    if (context != lbl_8064D18C) {
        fn_800CA2C8(object);
        fn_801E8328(2, object);
    } else {
        action = fn_801294DC(resource, 0x18, 0x20, 10);
        if (action != 0) {
            int high = fn_8012A1FC(resource, 0x18);
            int low = fn_8012A1BC(resource, 0x18);
            int distance;

            if (requested == -1) {
                distance = low - high;
                if (distance < 0) {
                    distance = -distance;
                }
            } else {
                distance = requested;
            }
            if (state == 0) {
                fn_80129FD0(resource, 0x320000, 1);
                fn_801287C4(action, fn_800798C4, resource, 0x32003C);
            }
            fn_800389E0(object, 0, 0, 1);
            fn_801287C4(action, fn_80204810, (void *)((owner << 8) | 0xF9), low - 1);
            fn_80128A84(action, 0, low);
            fn_80201D2C(object, 8);
            fn_80201D14(object, 1);
            fn_80201138(0x11, object, 8, -1, 0, (float)distance);
        }
    }
}
