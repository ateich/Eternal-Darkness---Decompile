extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(int);
extern void fn_80201138(int, void*, int, int, int, float);
extern const char lbl_8024FF00[];

int fn_8016D680(void* state)
{
    int a;
    int b;
    int x;
    int y;
    float z;
    int c;

    if (fn_8016A598(state) != 6) {
        fn_80163BB4(state, lbl_8024FF00, 6, fn_8016A598(state));
        return 0;
    }
    x = (int)fn_8016A694(state, 1);
    y = (int)fn_8016A694(state, 2);
    z = (float)fn_8016A694(state, 3);
    a = (int)fn_8016A694(state, 4);
    b = (int)fn_8016A694(state, 5);
    c = (int)fn_8016A694(state, 6);
    if (x != 0) {
        void* object = fn_80201814(x);
        if (object != 0) {
            fn_80201138(y, object, a, b, c, z);
        }
    }
    return 0;
}
