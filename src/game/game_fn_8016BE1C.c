extern void* fn_8016A784(void*, int);
extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern int fn_80201B54();
extern void fn_8016A830(void*, double);
extern const char lbl_8024FF00[];

int fn_8016BE1C(void* state)
{
    void* object = fn_8016A784(state, 1);
    int result;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    result = fn_80201B54(object);
    fn_8016A830(state, result);
    return 1;
}
