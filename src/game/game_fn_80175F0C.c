typedef signed short s16;
typedef unsigned int u32;

extern int fn_8016A598(void*);
extern void* fn_8016A784(void*, int);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern u32 fn_80178F14(int, int, int, int, int, int);
extern const char lbl_8024FF00[];

int fn_80175F0C(void* state)
{
    s16* first;
    s16* second;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    first = (s16*)fn_8016A784(state, 1);
    second = (s16*)fn_8016A784(state, 2);
    fn_8016A830(state, (double)fn_80178F14(first[0], first[1], first[2],
                                           second[0], second[1], second[2]));
    return 1;
}
