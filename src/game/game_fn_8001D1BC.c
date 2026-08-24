typedef int s32;
typedef float f32;

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80211A90(Vec3*, Vec3*, f32);
extern void fn_80211A48(Vec3*, Vec3*, Vec3*);
extern s32 fn_801D3A24(s32, s32);
extern void fn_80152A88(Vec3*, Vec3*, void*, s32);
extern Vec3 lbl_80237F38;
extern char lbl_8023BEF8[];

s32 fn_8001D1BC(void* script)
{
    Vec3 input;
    Vec3 basis;
    s32 value;
    void* object;

    basis = lbl_80237F38;
    if (fn_8016A598(script) != 5) {
        fn_80163BB4(script, lbl_8023BEF8, 5, fn_8016A598(script));
        return 0;
    }

    value = (s32)fn_8016A694(script, 1);
    input.x = (f32)fn_8016A694(script, 2);
    input.y = (f32)fn_8016A694(script, 3);
    input.z = (f32)fn_8016A694(script, 4);
    fn_80211A90(&basis, &basis, (f32)fn_8016A694(script, 5));
    fn_80211A48(&basis, &input, &basis);
    object = (void*)fn_801D3A24(value, 0x31);
    fn_80152A88(&input, &basis, object, 4);
    return 1;
}
