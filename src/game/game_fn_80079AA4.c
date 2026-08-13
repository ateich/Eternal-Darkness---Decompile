extern float lbl_8064E938;
extern void *fn_80200C38(int value);
extern int fn_80201B54(void *object);
extern void *fn_801A7498(void *object);
extern void *fn_80201814(void *object);
extern int fn_80128EAC(void *object);
extern int fn_80201B5C(void *object);
extern int fn_80204508(void *object, void *other);
extern void fn_80064B38(void *object, int value, void *work);
extern int fn_80079008(void *object, void *resource);
extern int fn_80128F40(void *object);
extern short fn_801A74F8(void *object);
extern float fn_8010181C(float value);
extern void fn_801A7518(void *object, int value);

/* NonMatching: behavior-complete candidate validation, randomized temporary
 * value update, dispatch, and restoration. */
void fn_80079AA4(void *object, void *resource, int value, void *work)
{
    void *wrapper = fn_80200C38(value);
    void *candidate;
    int type;

    fn_80201B54(object);
    candidate = fn_80201814(fn_801A7498(wrapper));
    type = fn_80128EAC(resource);

    if ((candidate != 0 ? fn_80201B5C(candidate) : 0) != 0x19) {
        if (candidate == 0 || !fn_80204508(object, candidate)) {
            fn_80064B38(object, value, work);
        } else {
            int state = fn_80079008(object, resource);
            int field = fn_80128F40(resource) >> 17;

            if ((state == 0 || type == 0x7C || type == 0x81) &&
                ((type != 0x7C && type != 0x81) || field == 10)) {
                short original = fn_801A74F8(wrapper);
                int randomized = (int)fn_8010181C((float)original * lbl_8064E938);
                fn_801A7518(wrapper, randomized);
                fn_80064B38(object, value, work);
                fn_801A7518(wrapper, original);
            }
        }
    }
}
