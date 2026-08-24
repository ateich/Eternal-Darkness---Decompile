extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(int);
extern void* fn_80201BC8(void*);
extern void fn_8012B7A0(void*, float);
extern const char lbl_8024FF00[];
extern const float lbl_806506C0;

int fn_8016F4CC(void* state)
{
    int object_id;
    float value;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    value = (float)fn_8016A694(state, 2);
    fn_8012B7A0(fn_80201BC8(fn_80201814(object_id)), lbl_806506C0 * value);
    return 0;
}
