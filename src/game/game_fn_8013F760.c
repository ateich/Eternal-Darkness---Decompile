typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Params {
    unsigned char pad[0x14];
    Vec3 position;
    float scale;
    unsigned char type;
} Params;

extern float lbl_806503A8;
extern void fn_80179C10(Vec3*, float, float, const Vec3*, float, unsigned char);
extern void fn_80211A48(const Vec3*, const Vec3*, Vec3*);
extern void fn_80211A6C();

void fn_8013F760(const Vec3* origin, Params* params, float extent,
                 Vec3* out)
{
    Vec3 center;
    Vec3 offset;
    float negative = -extent;

    fn_80179C10(out, lbl_806503A8, negative, &params->position,
                params->scale, params->type);
    fn_80179C10(out + 1, negative, extent, &params->position,
                params->scale, params->type);
    fn_80179C10(out + 2, extent, extent, &params->position,
                params->scale, params->type);
    fn_80179C10(&center, lbl_806503A8, lbl_806503A8, &params->position,
                params->scale, params->type);
    fn_80211A6C(origin, &center, &offset);
    fn_80211A48(out, &offset, out);
    fn_80211A48(out + 1, &offset, out + 1);
    fn_80211A48(out + 2, &offset, out + 2);
}
