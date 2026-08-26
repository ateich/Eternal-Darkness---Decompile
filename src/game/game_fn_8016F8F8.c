typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void* fn_8016A784(void*, int);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80179DB0(Vec3*, void*);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern float fn_8012B7D0(void*, Vec3*);
extern const char lbl_8024FF00[];
extern const float lbl_806506C4;

int fn_8016F8F8(void* state)
{
    int object_id;
    void* source;
    void* object;
    Vec3 position;
    Vec3 copy;
    float value;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    source = fn_8016A784(state, 2);
    if (source != 0) {
        fn_80179DB0(&position, source);
    } else {
        return 0;
    }

    object = fn_80201814(object_id);
    if (object != 0 && fn_80201BC8(object) != 0) {
        object = fn_80201BC8(object);
        copy = position;
        value = fn_8012B7D0(object, &copy);
        fn_8016A830(state, lbl_806506C4 * value);
    } else {
        return 0;
    }
    return 1;
}
