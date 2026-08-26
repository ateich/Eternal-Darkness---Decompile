extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void fn_8012C478(void*, int, int);
extern const char lbl_8024FF00[];

int fn_80174C34(void* state)
{
    void* object;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    object = fn_80201814((int)fn_8016A694(state, 1));
    if (object != 0) {
        object = fn_80201BC8(object);
        if (object != 0) {
            fn_8012C478(object, 15, 1);
        }
    }
    return 0;
}
