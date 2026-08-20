extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void* fn_80201814(int);
extern void* fn_80201BC8(void*);
extern void fn_80124664(void*, int, int, float);
extern const char lbl_8024FF00[];

int fn_8016CB24(void* state)
{
    int second;
    int first;
    float third;

    if (fn_8016A598(state) != 3) {
        fn_80163BB4(state, lbl_8024FF00, 3, fn_8016A598(state));
        return 0;
    }
    first = (int)fn_8016A694(state, 1);
    second = (int)fn_8016A694(state, 2);
    third = (float)fn_8016A694(state, 3);
    fn_80124664(fn_80201BC8(fn_80201814(first)), second, 8, third);
    return 0;
}
