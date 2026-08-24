extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201B94();
extern int fn_80201C48(void);
extern const char lbl_8024FF00[];

int fn_8016BD0C(void* state)
{
    int result = -1;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    if (fn_80201814((int)fn_8016A694(state, 1)) != 0 && fn_80201B94() != 0) {
        result = fn_80201C48();
    }
    fn_8016A830(state, result);
    return 1;
}
