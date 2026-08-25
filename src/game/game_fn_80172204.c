extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801AD404(unsigned char, unsigned char, int);
extern const char lbl_8024FF00[];
extern const char lbl_8025038C[];

int fn_80172204(void* state)
{
    int value;
    unsigned char clamped;
    int other;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    value = (int)fn_8016A694(state, 1);
    other = (int)fn_8016A694(state, 2);
    clamped = (value > 0 ? value : 0) > 0x7F
                  ? 0x7F
                  : (value > 0 ? value : 0);
    if (value != clamped) {
        fn_80163BB4(state, lbl_8025038C, value);
    }
    fn_801AD404(clamped, clamped, other);
    return 0;
}
