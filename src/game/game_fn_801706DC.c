extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern unsigned int fn_800F5C54(double);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern int fn_801F8748(int, void*, int, int, int);
extern void fn_8016A830(void*, double);
extern const char lbl_8024FF00[];

int fn_801706DC(void* state)
{
    int first;
    int second;
    int third;
    int fourth;
    int result;
    int fifth;
    void* object;

    result = 0;
    if (fn_8016A598(state) != 5) {
        fn_80163BB4(state, lbl_8024FF00, 5, fn_8016A598(state));
        return 0;
    }

    first = fn_800F5C54(fn_8016A694(state, 1));
    second = (int)fn_8016A694(state, 2);
    third = (int)fn_8016A694(state, 3);
    fourth = (int)fn_8016A694(state, 4);
    fifth = (int)fn_8016A694(state, 5);

    object = fn_80201814(second);
    if (object != 0) {
        object = fn_80201BC8(object);
        if (object != 0) {
            result = fn_801F8748(first, object, third, fourth, fifth);
        }
    }

    fn_8016A830(state, result);
    return 1;
}
