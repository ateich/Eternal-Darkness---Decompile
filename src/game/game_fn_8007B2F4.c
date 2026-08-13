typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct EffectParams {
    unsigned char pad0[6];
    unsigned short type;
    unsigned char pad8[12];
    float scale;
    unsigned char pad18[0x84];
} EffectParams;

extern const float lbl_8064E980;

extern void fn_801A19BC(EffectParams *params);
extern void fn_801A1BD0(void);
extern void fn_80148008(Vec3 *position, void *descriptor,
                       EffectParams *params, void (*callback)(void));

void fn_8007B2F4(const Vec3 *source)
{
    unsigned char descriptor[6] = { 0, 0, 0, 0, 0, 1 };
    Vec3 position;
    EffectParams params;

    fn_801A19BC(&params);
    params.type = 0x5A;
    params.scale = lbl_8064E980;
    position = *source;
    fn_80148008(&position, &descriptor, &params, fn_801A1BD0);
}
