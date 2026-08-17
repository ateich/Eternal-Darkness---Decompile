#pragma use_lmw_stmw on

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Owner { unsigned char pad0[0x20]; void* tree; unsigned char pad24[0x7C]; void* planes; unsigned char padA4[0x40]; unsigned char* entries; } Owner;
typedef struct Hit { Vec3 point; unsigned char padC[4]; unsigned char index; } Hit;

extern float lbl_806503D8;
extern void* fn_80140010(void*, const Vec3*, Vec3*);
extern void* fn_8013DAA8(const Vec3*, const void*, Vec3*);
extern void* fn_8014317C(const Vec3*, Vec3*, void*, int, int);
extern float fn_80211D4C(const Vec3*, const Vec3*);

void* fn_80140258(Owner* owner, const Vec3* value, Vec3* out, unsigned int flags, void* filter)
{
    Vec3 a, b, c;
    void* tree_hit = 0;
    Hit* plane_hit = 0;
    void* other_hit = 0;
    int selected = 0;
    float best = lbl_806503D8;
    if (!(flags & 8)) tree_hit = fn_80140010(&owner->tree, value, &a);
    if (!(flags & 0x10)) plane_hit = fn_8013DAA8(value, owner->planes, &c);
    if (flags & 1) other_hit = fn_8014317C(value, &b, filter, 0, (flags >> 1 & 1) | ((flags & 0x10) ? 0 : 2));
    if (tree_hit) { best = fn_80211D4C(value, &a); selected = 1; }
    if (plane_hit) { float d = fn_80211D4C(value, &c); if (d < best) { best = d; selected = 2; } }
    if (other_hit && fn_80211D4C(value, &b) < best) selected = 3;
    if (selected == 1) { *out = a; return tree_hit; }
    if (selected == 2) { *out = c; return owner->entries + plane_hit->index * 0x38; }
    if (selected == 3) { *out = b; return other_hit; }
    return 0;
}
