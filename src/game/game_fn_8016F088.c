extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void* fn_8016A784(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80128C28(void*, void*, unsigned int);
extern void fn_8016FFA8(void);
extern const char lbl_8024FF00[];

int fn_8016F088(void* state)
{
    void* queue;
    int value;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    queue = fn_8016A784(state, 1);
    value = (int)fn_8016A694(state, 2);
    fn_80128C28(queue, fn_8016FFA8, value);
    return 0;
}
