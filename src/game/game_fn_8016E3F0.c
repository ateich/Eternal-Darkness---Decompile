extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern unsigned int fn_800F5C54(double);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801FA198(unsigned int, void*, int, int, int, int, int, int, int);
extern const char lbl_8024FF00[];
extern char lbl_8063CD18[];

int fn_8016E3F0(void* state)
{
    int second;
    int fourth;
    int third;
    unsigned int first;
    int fifth;

    if (fn_8016A598(state) != 5) {
        fn_80163BB4(state, lbl_8024FF00, 5, fn_8016A598(state));
        return 0;
    }
    first = fn_800F5C54(fn_8016A694(state, 1));
    second = (int)fn_8016A694(state, 2);
    third = (int)fn_8016A694(state, 3);
    fourth = (int)fn_8016A694(state, 4);
    fifth = (int)fn_8016A694(state, 5);
    fn_801FA198(first, lbl_8063CD18 + 0x110, second, third, fourth, 0, 0, fifth, 0);
    return 0;
}
