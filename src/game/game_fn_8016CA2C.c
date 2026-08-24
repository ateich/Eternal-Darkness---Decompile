extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void fn_801247F8(void*, int, int, float);
extern const char lbl_8024FF00[];

int fn_8016CA2C(void* state)
{
    int second;
    int fourth;
    int first;
    float third;

    if (fn_8016A598(state) != 4) {
        fn_80163BB4(state, lbl_8024FF00, 4, fn_8016A598(state));
        return 0;
    }
    first = (int)fn_8016A694(state, 1);
    second = (int)fn_8016A694(state, 2);
    third = (float)fn_8016A694(state, 3);
    fourth = (int)fn_8016A694(state, 4);
    fn_801247F8(fn_80201BC8(fn_80201814(first)), second, fourth, third);
    return 0;
}
