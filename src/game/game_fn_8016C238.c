typedef signed short s16;

extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern s16* fn_8016A784(void*, int);
extern void fn_801B05E8(int, int, int, int, void*, int, int, int);
extern const char lbl_8024FF00[];

int fn_8016C238(void* state)
{
    int first;
    int second;
    int third;
    int fourth;
    s16* source;
    float vector[3];
    void* position;

    if (fn_8016A598(state) != 5) {
        fn_80163BB4(state, lbl_8024FF00, 5, fn_8016A598(state));
        return 0;
    }

    first = (int)fn_8016A694(state, 1);
    second = (int)fn_8016A694(state, 2);
    third = (int)fn_8016A694(state, 3);
    fourth = (int)fn_8016A694(state, 4);
    source = fn_8016A784(state, 5);
    if (source != 0) {
        vector[0] = source[0];
        vector[1] = source[1];
        vector[2] = source[2];
        position = vector;
    } else {
        position = 0;
        third = 5;
    }

    fn_801B05E8(first, second, fourth, 1, position, third, 0, 0);
    return 0;
}
