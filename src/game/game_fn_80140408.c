typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Pair { Vec3 a, b; } Pair;
typedef struct DebugState { int active; int enabled; int unused; } DebugState;
typedef struct RingState { unsigned char count, head; unsigned char pad[2]; } RingState;

extern DebugState lbl_8064D20C;
extern RingState lbl_8064D698;
extern Pair lbl_805B0EA8[40];
extern float lbl_806503E0;
extern float lbl_806503E4;

void fn_80140408(const Vec3* a, const Vec3* b, const Vec3* extent)
{
    unsigned char i;
    if (!lbl_8064D20C.enabled) return;
    if (a->x >= -extent->x - lbl_806503E0 && a->x <= lbl_806503E0 - extent->x &&
        a->y >= -extent->y - lbl_806503E0 && a->y <= lbl_806503E0 - extent->y &&
        a->z >= -extent->z - lbl_806503E0 && a->z <= lbl_806503E0 - extent->z) return;
    for (i = 0; i < lbl_8064D698.count; i++) {
        Pair* p = &lbl_805B0EA8[i];
        if (a->x >= p->a.x - lbl_806503E4 && a->x <= p->a.x + lbl_806503E4 &&
            a->y >= p->a.y - lbl_806503E4 && a->y <= p->a.y + lbl_806503E4 &&
            a->z >= p->a.z - lbl_806503E4 && a->z <= p->a.z + lbl_806503E4 &&
            b->x >= p->b.x - lbl_806503E4 && b->x <= p->b.x + lbl_806503E4 &&
            b->y >= p->b.y - lbl_806503E4 && b->y <= p->b.y + lbl_806503E4 &&
            b->z >= p->b.z - lbl_806503E4 && b->z <= p->b.z + lbl_806503E4) return;
    }
    lbl_805B0EA8[lbl_8064D698.head].a = *a;
    lbl_805B0EA8[lbl_8064D698.head].b = *b;
    lbl_8064D698.head = (lbl_8064D698.head + 1) % 40;
    if (++lbl_8064D698.count > 40) lbl_8064D698.count = 40;
}
