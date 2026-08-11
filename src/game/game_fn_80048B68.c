typedef int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern float lbl_8064B4C0;
extern float lbl_8064C82C;
extern void* lbl_8064C4E4;
extern const float lbl_8064E3AC;
extern const float lbl_8064E3B0;

extern float fn_80048C2C(float value);
extern float fn_80048C50(float value);
extern void fn_8012B690(void* object, Vec3* input, Vec3* output);
extern s32 fn_8012FF34(void* object, Vec3* value, s32 type, s32 index);
extern void fn_801302BC(void* object, s32 value);

void fn_80048B68(void)
{
    Vec3 value;
    Vec3 transformed;
    value.x = lbl_8064E3AC * fn_80048C50(lbl_8064C82C) *
              fn_80048C2C(lbl_8064B4C0);
    value.y = lbl_8064E3AC * fn_80048C2C(lbl_8064C82C) *
              fn_80048C2C(lbl_8064B4C0);
    value.z = lbl_8064E3AC * fn_80048C50(lbl_8064B4C0) + lbl_8064E3B0;

    fn_8012B690(lbl_8064C4E4, &value, &transformed);
    if (fn_8012FF34(lbl_8064C4E4, &transformed, 4, 10) != 0) {
        fn_801302BC(lbl_8064C4E4, 60);
    }
}
