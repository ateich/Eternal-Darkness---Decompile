extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801F348C(void*, int);
extern const char lbl_8024FF00[];

int fn_80174DB8(void* state)
{
    struct Bytes {
        unsigned char data[4];
    } converted, value;
    int parameter;

    if (fn_8016A598(state) != 5) {
        fn_80163BB4(state, lbl_8024FF00, 5, fn_8016A598(state));
        return 0;
    }

    converted.data[0] = fn_8016A694(state, 1);
    converted.data[1] = fn_8016A694(state, 2);
    converted.data[2] = fn_8016A694(state, 3);
    converted.data[3] = fn_8016A694(state, 4);
    parameter = fn_8016A694(state, 5);
    value = converted;
    fn_801F348C(&value, parameter);
    return 0;
}
