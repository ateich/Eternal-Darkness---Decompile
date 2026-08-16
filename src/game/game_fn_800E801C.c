typedef struct Vec3i {
    int x;
    int y;
    int z;
} Vec3i;

extern int lbl_8064D18C;
extern float lbl_8064F7EC;
extern volatile float lbl_8064F7F0;
extern int fn_80200C38();
extern void *fn_8004910C(int);
extern int fn_80201B54();
extern void *fn_80201BC8();
extern int fn_8011EB04(void *);
extern int fn_80047CB4(void);
extern Vec3i fn_80201E78(void *);
extern void fn_80154340(int, int, int, int, float, int, int, int);
extern void fn_801AAE68(float, int, int, int, Vec3i *, int, int, int, unsigned short, int);

int fn_800E801C(void *object, void *source)
{
    void *candidate;
    int handle;
    int result;

    result = 0;
    candidate = fn_8004910C(fn_80200C38(source));
    handle = fn_80201B54(object);

    if (candidate != 0) {
        void *state = fn_80201BC8(candidate);
        if (state != 0) {
            int kind = fn_8011EB04(state);
            int current = fn_80047CB4();
            if (current == kind) {
                Vec3i position = fn_80201E78(object);
                fn_80154340(handle, 0, 1, 10, lbl_8064F7EC, 120, 1, 64);
                fn_801AAE68(lbl_8064F7F0, 466, 125, 0, &position, 2, 1, 0,
                            (unsigned short)lbl_8064D18C, 0);
                result = 1;
            }
        }
    }
    return result;
}
