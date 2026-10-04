typedef unsigned char u8;
typedef unsigned long u32;

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Color { u8 r, g, b, a; } Color;
typedef struct BoundsCamera {
    float min_x, min_y, unused_8;
    float max_x, max_y, unused_14;
    Vec3 eye;
    float unused_24[3];
    float projection;
} BoundsCamera;

extern float lbl_8023B78C[3];
extern int lbl_8064D738, lbl_8064CBA4, lbl_8064D6F8;
extern int lbl_8064CB50, lbl_8064CBA0, lbl_8064D638;
extern float lbl_8064D6C8, lbl_8064D6CC;
extern const float lbl_80651348, lbl_8065134C, lbl_80651368, lbl_8065136C;
extern const float lbl_80651370, lbl_80651374, lbl_80651378, lbl_8065137C;
extern const float lbl_80651380, lbl_80651384, lbl_80651388, lbl_8065138C;
extern const float lbl_80651390;
extern u8 lbl_802FC5BC[];

extern void fn_802118E0(void*, float, float, float, float);
extern void fn_8022B94C(float, float, float, float, float, float);
extern void fn_8022B970(int, int, int, int);
extern void fn_8022B4B8(void*, int);
extern void fn_8017AD7C(void*, void*);
extern void fn_80211584(void*, void*, void*, void*);
extern void fn_802110A8(void*, void*);
extern void fn_80212154(void*, void*);
extern float fn_80211B08(void*);
extern void fn_8022B690(void*, int);
extern void fn_8022B6CC(void*, int);
extern void fn_80227290(Color*, int);
extern void fn_8022A5D8(int, int, int, int);
extern void fn_80226D28(int);
extern void fn_801F10BC(int, int, int);
extern void fn_801ECF50(int);
extern void fn_801F0044(void);
extern void fn_801ECC4C(void);
extern void fn_801ECEC8(int, int, int);
extern void fn_80225F4C(int, void*, int);
extern void fn_801ECD74(void*);
extern Vec3* fn_8015AB00(int);
extern void fn_80211484(void*, float, float, float);
extern void fn_80210FDC(void*, void*, void*);
extern void DCFlushRange(void*, u32);
extern void fn_8022A6DC(int);
extern void fn_8022A71C(int);
extern void fn_80228020(int);
extern void fn_8022806C(int, int, int, int, int, int, int);
extern void fn_80229FA4(int, int, int, int, int);
extern void fn_801ECD48(int);
extern void fn_801ECD50(float);

static u8 effect_8063BEA0[0x20] = {0};
static u8 effect_8063BEC0[0x5C] = {0};
static float effect_8063BF1C[3] = {0};
static float effect_8063BF28[16] = {0};
static u8 effect_8063BF68[0xC0] = {0};
static u8 effect_8063C028[0x40] = {0};
static u8 effect_matrix[0x30] = {0};
static u8 effect_8063C098[0x30] = {0};
static u8 effect_8063C0C8[0x30] = {0};
static u8 effect_emitters[0x400] = {0};

void fn_801F03F0(BoundsCamera in, int alternate)
{
    Vec3 target;
    float* matrix;
    float* normalized;
    Vec3* motion;
    Color constructedColor;
    float projection = lbl_80651368;

    target = *(Vec3*)lbl_8023B78C;
    matrix = (float*)(effect_8063BF68);
    matrix += lbl_8064D738 * 24;
    if (lbl_8064CBA4 == 1)
        projection = lbl_8065136C;
    lbl_8064D6F8 = 0;
    target = in.eye;
    if (alternate)
        fn_802118E0(effect_8063BF28, in.projection, projection,
                    lbl_8065134C, lbl_80651370);
    else
        fn_802118E0(effect_8063BF28, in.projection, projection,
                    lbl_8065134C, lbl_80651374);
    fn_8022B94C(lbl_80651348, lbl_80651348, lbl_80651378,
                lbl_8065137C, lbl_80651348, lbl_8065134C);
    fn_8022B970(0, 0, 0x280, 0x1E0);
    fn_8022B4B8(effect_8063BF28, 0);
    fn_8017AD7C(effect_8063BF28, effect_8063C028);

    if (in.min_x == in.max_x && in.min_y == in.max_y &&
        lbl_8065134C == target.z) {
        in.min_x += lbl_80651380;
        in.min_y += lbl_80651380;
    }
    fn_80211584(effect_matrix, &in, &target, &in.max_x);
    fn_802110A8(effect_matrix, effect_8063C098);
    fn_80212154(effect_matrix, effect_8063C0C8);

    {
        float delta_x = in.max_x - in.min_x;
        float delta_y = in.max_y - in.min_y;
        normalized = effect_8063BF1C;
        normalized[1] = delta_y;
        effect_8063BF1C[0] = delta_x;
        normalized[2] = lbl_80651348;
    }
    projection = fn_80211B08(normalized);
    effect_8063BF1C[0] /= projection;
    normalized[1] /= projection;
    fn_8022B690(effect_matrix, 0x1B);
    fn_8022B6CC(effect_matrix, 0x1B);

    if (lbl_8064CB50) {
        Color enabledColor = *(Color*)(lbl_802FC5BC + 0x28);
        fn_80227290(&enabledColor, 0xFFFFFF);
    } else {
        Color fallbackColor;
        constructedColor.r = lbl_8064CBA0;
        constructedColor.g = lbl_8064CBA0;
        constructedColor.b = lbl_8064CBA0;
        constructedColor.a = 0xFF;
        fallbackColor = constructedColor;
        fn_80227290(&fallbackColor, 0xFFFFFF);
    }
    fn_8022A5D8(1, 4, 5, 0);
    fn_80226D28(1);
    fn_801F10BC(0, 0, 0);
    fn_801ECF50(2);
    fn_801F0044();
    fn_801ECC4C();
    fn_801ECEC8(1, 3, 1);
    {
        u8* command = effect_emitters;
        int command_offset = lbl_8064D738 * 0x200;
        fn_80225F4C(0x18, command + command_offset, 0x40);
    }
    {
        Color color = *(Color*)(lbl_802FC5BC + 0xC);
        fn_801ECD74(&color);
    }

    motion = fn_8015AB00(2);
    if (motion != 0) {
        float rotation[12];
        float z, y, x, w, divisor;
        float* matrix2;
        fn_80211484(rotation, lbl_80651348, lbl_80651348,
                    lbl_80651384 - motion->x);
        divisor = lbl_80651388;
        x = -((float*)effect_matrix)[8];
        y = -((float*)effect_matrix)[9];
        z = -((float*)effect_matrix)[10];
        w = -((float*)effect_matrix)[11];
        x /= divisor;
        y /= divisor;
        z /= divisor;
        w /= divisor;
        matrix[0] = x;
        matrix[1] = y;
        matrix[2] = z;
        matrix[3] = w;
        matrix[4] = lbl_80651348;
        matrix[5] = lbl_80651348;
        matrix[6] = lbl_8065138C;
        matrix[7] = lbl_80651348;
        matrix[8] = lbl_80651348;
        matrix[9] = lbl_80651348;
        matrix[10] = lbl_80651348;
        matrix[11] = lbl_80651348;
        fn_80210FDC(matrix, rotation, matrix);

        matrix2 = (float*)(effect_8063BF68 + 0x30 + lbl_8064D738 * 0x60);
        matrix2[0] = lbl_80651390;
        matrix2[1] = lbl_80651348;
        matrix2[2] = lbl_80651348;
        matrix2[3] = lbl_80651348;
        matrix2[4] = lbl_80651348;
        matrix2[5] = lbl_80651390;
        matrix2[6] = lbl_80651348;
        matrix2[7] = lbl_80651348;
        matrix2[8] = lbl_80651348;
        matrix2[9] = lbl_80651348;
        matrix2[10] = lbl_80651348;
        matrix2[11] = lbl_80651348;
        fn_80211484(rotation, lbl_8064D6C8, lbl_8064D6CC, lbl_80651348);
        fn_80210FDC(matrix2, rotation, matrix2);
        {
            u8* base = effect_8063BF68;
            int offset = lbl_8064D738 * 0x60;
            DCFlushRange(base + offset, 0x60);
        }
        fn_80225F4C(0x17, effect_8063BF68 + lbl_8064D738 * 0x60, 0x30);
    }
    fn_8022A6DC(1);
    fn_8022A71C(0);
    fn_80228020(1);
    lbl_8064D638 = 1;
    fn_8022806C(4, 0, 0, 0, 0, 0, 2);
    fn_8022806C(5, 0, 0, 0, 0, 0, 2);
    fn_80229FA4(0, 0, 1, 2, 3);
    fn_80229FA4(1, 0, 0, 0, 0);
    fn_801ECD48(0);
    fn_801ECD50(lbl_8065134C);
}
