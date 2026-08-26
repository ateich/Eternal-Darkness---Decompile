extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201C24();
typedef struct Object Object;
extern unsigned short fn_80158234(Object*);
extern const char lbl_8024FF00[];

int fn_80176098(void* state)
{
    int object_id;
    int value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    if (fn_80201814(object_id) != 0) {
        value = fn_80158234(fn_80201C24());
        fn_8016A830(state, (double)value);
    } else {
        fn_8016A830(state, -1.0);
    }
    return 1;
}
