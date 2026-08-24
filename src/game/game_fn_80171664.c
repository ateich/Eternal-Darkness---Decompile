extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_801A98F4(unsigned short, unsigned char);
extern void fn_8016A830(void*, double);
extern const char lbl_8024FF00[];
extern const char lbl_80250284[];

int fn_80171664(void* state)
{
    int id;
    int value;
    unsigned char clamped;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    id = (int)fn_8016A694(state, 1);
    value = (int)fn_8016A694(state, 2);
    clamped = (value > 0 ? value : 0) > 0x7F
                  ? 0x7F
                  : (value > 0 ? value : 0);
    if (value != clamped) {
        fn_80163BB4(state, lbl_80250284, value, 0x7F);
    }
    fn_8016A830(state, fn_801A98F4((unsigned short)id, clamped));
    return 1;
}
