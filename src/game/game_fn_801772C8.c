typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801F6FD8(Vec3);
extern const char lbl_8024FF00[];

int fn_801772C8(void* state)
{
    Vec3 value;

    if (fn_8016A598(state) != 3) {
        fn_80163BB4(state, lbl_8024FF00, 3, fn_8016A598(state));
        return 0;
    }

    value.x = (float)fn_8016A694(state, 1);
    value.y = (float)fn_8016A694(state, 2);
    value.z = (float)fn_8016A694(state, 3);
    fn_801F6FD8(value);
    return 1;
}
