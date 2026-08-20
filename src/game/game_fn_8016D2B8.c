extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void* fn_8016A784(void*, int);
extern int fn_80201B44(void);
extern int fn_802019EC(int, int);
extern void* fn_80201814(int);
extern int fn_80201C2C(void*);
extern int fn_80201948(int, int);
extern void* fn_80201B9C(void);
extern int fn_80201B5C(void*);
extern int fn_80201B54(void*);
extern void* fn_80201BC0(void*);
extern void fn_8016A7D8(void*);
extern void fn_8016A830(void*, double);
extern const char lbl_8024FF00[];
extern int lbl_8064D18C;

int fn_8016D2B8(void* state)
{
    int mode;
    int argument;
    int result = 0;
    int resolved;
    void* node;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }
    mode = (int)fn_8016A694(state, 1);
    if (mode == 6) {
        node = fn_8016A784(state, 2);
    }
    if (mode != 6) {
        argument = (int)fn_8016A694(state, 2);
    }
    switch (mode) {
    case 1:
        result = fn_80201B44();
        break;
    case 2:
        result = fn_802019EC(argument, lbl_8064D18C);
        break;
    case 4:
        result = fn_802019EC(argument, -1);
        break;
    case 5:
        resolved = fn_80201C2C(fn_80201814(fn_80201B44()));
        result = fn_80201948(argument, resolved);
        break;
    case 3:
        node = fn_80201B9C();
        while (node != 0) {
            if (argument == fn_80201B5C(node)) {
                result = fn_80201B54(node);
            }
            node = fn_80201BC0(node);
        }
        break;
    case 6:
        result = fn_80201B54(node);
        break;
    }
    if (result <= 0) {
        fn_8016A7D8(state);
    } else {
        fn_8016A830(state, (double)result);
    }
    return 1;
}
