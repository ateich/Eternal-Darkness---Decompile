typedef struct Vec3s {
    short x;
    short y;
    short z;
} Vec3s;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

extern int fn_8016A598(void*);
extern float fn_8016A694(void*, int);
extern Vec3s* fn_8016A784(void*, int);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern int fn_801AC9F4(unsigned short, unsigned char, Vec3f*, signed char);
extern const char lbl_8024FF00[];
extern const char lbl_8025038C[];

int fn_801726EC(void* state)
{
    int first;
    int second;
    Vec3s* position;
    int fourth;
    unsigned short arg1;
    unsigned char clamped;
    Vec3f converted;
    int result;

    if (fn_8016A598(state) != 4) {
        fn_80163BB4(state, lbl_8024FF00, 4, fn_8016A598(state));
        return 0;
    }

    first = (int)fn_8016A694(state, 1);
    second = (int)fn_8016A694(state, 2);
    position = fn_8016A784(state, 3);
    fourth = (int)fn_8016A694(state, 4);

    arg1 = (unsigned short)first;
    clamped = (second > 0 ? second : 0) > 0x7F
                  ? 0x7F
                  : (second > 0 ? second : 0);
    if (second != clamped) {
        fn_80163BB4(state, lbl_8025038C, second);
    }

    converted.x = position->x;
    converted.y = position->y;
    converted.z = position->z;
    result = fn_801AC9F4(arg1, clamped, &converted, (signed char)fourth);
    fn_8016A830(state, result);
    return 1;
}
