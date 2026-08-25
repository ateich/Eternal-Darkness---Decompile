extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(int);
typedef struct Object Object;
extern Object* fn_80201C24(void);
extern void fn_80157A28(Object*, unsigned short);
extern const char lbl_8024FF00[];

int fn_801763D8(void* state)
{
    int object_id;
    int value;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    value = (int)fn_8016A694(state, 2);
    if (fn_80201814(object_id) != 0) {
        fn_80157A28(fn_80201C24(), (unsigned short)value);
    }
    return 0;
}
