extern void fn_801FD240(void);
extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern const char lbl_8024FF00[];

int fn_80175164(void* state)
{
    fn_801FD240();
    if (fn_8016A598(state) != 0) {
        fn_80163BB4(state, lbl_8024FF00, 0, fn_8016A598(state));
        return 0;
    }

    asm {
        li r0, 12
        mtctr r0
    delay_loop:
        bdnz delay_loop
    }
    return 0;
}
