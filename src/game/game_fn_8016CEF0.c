extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void *fn_80201814();
extern void* fn_80204A8C(void);
extern void fn_80204CE4(int, void*);
extern int fn_80201C2C(int);
extern int fn_80204C2C(int);
extern int fn_80155DB4(int);
extern void fn_801568B8(int, int);
extern const char lbl_8024FF00[];

int fn_8016CEF0(void* state)
{
    int third;
    int second;
    int first;

    if (fn_8016A598(state) != 3) {
        fn_80163BB4(state, lbl_8024FF00, 3, fn_8016A598(state));
        return 0;
    }

    first = (int)fn_8016A694(state, 1);
    second = (int)fn_8016A694(state, 2);
    third = (int)fn_8016A694(state, 3);

    if (first == -2) {
        second = (int)fn_80201814(second);
        if (second != 0) {
            fn_80204CE4(second, fn_80204A8C());
        }
    } else {
        first = (int)fn_80201814(first);
        if (first != 0) {
            second = (int)fn_80201814(second);
            if (second != 0) {
                int value = fn_80201C2C(first);
                if (value == 0) {
                    value = fn_80204C2C(first);
                }
                fn_80204CE4(second, (void*)value);
                if (third == 0) {
                    second = fn_80155DB4(second);
                    if (second != 0) {
                        fn_801568B8(second, 0);
                    }
                }
            }
        }
    }
    return 0;
}
