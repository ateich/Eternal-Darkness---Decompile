extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void* fn_80201814(int);
extern void* fn_80201BC8(void*);
extern void fn_80124750(void*, int, int, int, float, float, float, float, int);
extern const char lbl_8024FF00[];

int fn_8016CBFC(void* state)
{
    int second;
    int ninth;
    int seventh;
    int eighth;
    int first;
    float third;
    float fourth;
    float fifth;
    float sixth;

    if (fn_8016A598(state) != 9) {
        fn_80163BB4(state, lbl_8024FF00, 9, fn_8016A598(state));
        return 0;
    }
    first = (int)fn_8016A694(state, 1);
    second = (int)fn_8016A694(state, 2);
    third = (float)fn_8016A694(state, 3);
    fourth = (float)fn_8016A694(state, 4);
    fifth = (float)fn_8016A694(state, 5);
    sixth = (float)fn_8016A694(state, 6);
    seventh = (int)fn_8016A694(state, 7);
    eighth = (int)fn_8016A694(state, 8);
    ninth = (int)fn_8016A694(state, 9);
    fn_80124750(fn_80201BC8(fn_80201814(first)), second, seventh, eighth,
                third, fourth, fifth, sixth, ninth | 8);
    return 0;
}
