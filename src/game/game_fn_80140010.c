#pragma use_lmw_stmw on

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Iterator { unsigned char data[12]; } Iterator;
typedef struct Link {
    unsigned char count;
    unsigned char pad1[3];
    unsigned short* indices;
    short primary;
    short secondary;
} Link;
typedef struct Owner {
    unsigned char pad0[0xC]; void* context;
    unsigned char pad10[0x30]; Link* links;
    unsigned char pad44[4]; unsigned char* entries;
} Owner;

extern float lbl_806503D8;
extern void fn_801E8E54(Iterator*, int, void*);
extern void fn_801E8E68(Iterator*, int);
extern int fn_801E8E94(Iterator*);
extern int fn_8013C7BC(const Vec3*, const Vec3*, float, const Vec3*);
extern int fn_8013D998(const Vec3*, const void*, void*, Vec3*);
extern float fn_80211D4C(const Vec3*, const Vec3*);
extern void fn_80140AEC(void*, Owner*);

void* fn_80140010(Owner* owner, const Vec3* value, Vec3* out)
{
    Iterator outer, inner;
    unsigned char outer_store[240], inner_store[240];
    void* result = 0;
    unsigned char* entries = owner->entries;
    fn_801E8E54(&outer, 60, outer_store);
    fn_801E8E54(&inner, 60, inner_store);
    fn_801E8E68(&outer, 0);
    fn_801E8E68(&inner, 0);
    do {
        int a = fn_801E8E94(&outer);
        int b = fn_801E8E94(&inner);
        if ((b != 0 && (b != 1 || result != 0)) || a == -1) break;
        {
            Link* link = &owner->links[a];
            unsigned char* first = entries + *(unsigned short*)link->indices * 0x38;
            int side = fn_8013C7BC(value, value + 1, *(float*)(first + 0x20), (Vec3*)(first + 0x14));
            if (side == 2) {
                float best = lbl_806503D8;
                int i;
                for (i = 0; i < link->count; i++) {
                    unsigned char* entry = entries + link->indices[i] * 0x38;
                    Vec3 candidate;
                    if (fn_8013D998(value, entry, owner->context, &candidate)) {
                        float distance = fn_80211D4C(&candidate, value);
                        if (distance < best) {
                            best = distance;
                            result = entry;
                            *out = candidate;
                            fn_80140AEC(entry, owner);
                        }
                    }
                }
                if (result == 0) { fn_801E8E68(&outer, link->secondary); fn_801E8E68(&inner, 1); }
                fn_801E8E68(&outer, link->primary); fn_801E8E68(&inner, 0);
            } else if (side == 3) {
                fn_801E8E68(&outer, link->primary); fn_801E8E68(&inner, 1);
                fn_801E8E68(&outer, link->secondary); fn_801E8E68(&inner, 0);
            } else if (side == 0) {
                fn_801E8E68(&outer, link->secondary); fn_801E8E68(&inner, 0);
            } else {
                fn_801E8E68(&outer, link->primary); fn_801E8E68(&inner, 0);
            }
        }
    } while (*(void**)((unsigned char*)&outer + 4) != 0);
    return result;
}
