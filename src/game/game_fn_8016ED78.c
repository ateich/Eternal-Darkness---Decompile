extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void* fn_80129AF4(void*, int, unsigned short, float, float);
extern void fn_8016A970(void*, void*, int);
extern const char lbl_8024FF00[];
extern const char lbl_80250040[];
extern const float lbl_806506C0;

int fn_8016ED78(void* state)
{
    int value;
    unsigned short kind;
    void* result;
    int object_id;
    float first;
    float second;

    if (fn_8016A598(state) != 5) {
        fn_80163BB4(state, lbl_8024FF00, 5, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    value = (int)fn_8016A694(state, 2);
    kind = (unsigned short)(int)fn_8016A694(state, 3);
    first = (float)fn_8016A694(state, 4);
    second = (float)fn_8016A694(state, 5);
    first *= lbl_806506C0;
    second *= lbl_806506C0;
    result = fn_80129AF4(fn_80201BC8(fn_80201814(object_id)), value, kind, first, second);
    fn_8016A970(state, result, 0);
    if (result == 0) {
        fn_80163BB4(state, lbl_80250040, 0);
    }
    return 1;
}
