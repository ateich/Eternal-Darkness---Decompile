extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern const char lbl_8024FF00[];
extern char lbl_8063D378[];
extern char lbl_8063D400[];

int fn_80177388(void* state)
{
    if (fn_8016A598(state) != 0) {
        fn_80163BB4(state, lbl_8024FF00, 0, fn_8016A598(state));
        return 0;
    }

    *(int*)(lbl_8063D378 + 0x40) = 1;
    *(int*)(lbl_8063D400 + 0x40) = 1;
    return 1;
}
