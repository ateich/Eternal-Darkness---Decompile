extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
typedef struct Object Object;
extern void *fn_80201C24();
extern unsigned short fn_80157948(Object*);
extern unsigned short fn_80157994(Object*);
extern const char lbl_8024FF00[];

int fn_801762E8(void* state)
{
    Object* object;
    unsigned short first;
    int object_id;
    int value;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    if (fn_80201814(object_id) != 0) {
        object = fn_80201C24();
        first = fn_80157948(object);
        value = first - fn_80157994(object);
        fn_8016A830(state, (double)value);
    } else {
        fn_8016A830(state, -1.0);
    }
    return 1;
}
