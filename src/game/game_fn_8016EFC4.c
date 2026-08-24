extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void* fn_8016A784(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801287C4(void*, void*, unsigned int, unsigned int);
extern void fn_8016FFA8(void);
extern const char lbl_8024FF00[];

int fn_8016EFC4(void* state)
{
    void* queue;
    int first;
    int second;

    if (fn_8016A598(state) != 3) {
        fn_80163BB4(state, lbl_8024FF00, 3, fn_8016A598(state));
        return 0;
    }

    queue = fn_8016A784(state, 1);
    first = (int)fn_8016A694(state, 2);
    second = (int)fn_8016A694(state, 3);
    fn_801287C4(queue, fn_8016FFA8, first, second);
    return 0;
}
