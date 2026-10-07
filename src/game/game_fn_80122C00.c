typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

#define NULL ((void*)0)

typedef float Matrix34[3][4];

typedef struct Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

typedef struct FogSetting {
    u8 pad0[0x8];
    u16 flags;
    u8 pad0A[0x2C - 0xA];
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} FogSetting;

typedef struct FogSlot {
    FogSetting* setting;
    u32 unk4;
} FogSlot;

typedef struct Actor {
    u8 pad0[0x8];
    float unk8;
    u8 pad0C[0x17C - 0xC];
    FogSlot slots[(0x244 - 0x17C) / 8];
    int unk244;
    int unk248;
    u8 pad24C[0x254 - 0x24C];
    u32 unk254;
    u8 pad258[0x2B0 - 0x258];
    float unk2B0[3];
    float unk2BC;
    u8 pad2C0[0x2D0 - 0x2C0];
    u16 unk2D0;
    u16 unk2D2;
    s16 unk2D4;
} Actor;

typedef struct Model {
    u8 pad0[0x1C];
    Color color;
} Model;

extern int lbl_8064D18C;
extern int lbl_8064D790;
extern float lbl_806500A0;
extern float lbl_806500A4;
extern float lbl_806500F4;
extern float lbl_806500F8;

extern u32 fn_8011FAF4(void*);
extern void* fn_8015AB00(int);
extern void fn_801ECD74(Color*);
extern void fn_801ECE7C(u32);
extern void fn_801ED5F4(int, int, s16, float*, Matrix34, float);
extern void fn_801EDA7C(void*, int, int, int);

int fn_80122C00(Actor* actor, Model* model, int slot, int useZ, int alpha,
                Matrix34 mtx, float dist, float scale)
{
    FogSetting* setting;
    int mode;
    int inside;
    int zflag;
    float* ref;
    int flags;
    s16 value;
    float f;
    int level;
    Color tmp;
    Color tmp2;
    Color c;
    Color c2;

    inside = actor->unk254 & 0x400000;
    zflag = actor->unk2D0 & 0x100;
    mode = 0x2BF;
    ref = fn_8015AB00(2);
    if (ref != NULL) {
        if (lbl_8064D18C == 0x53 || lbl_8064D18C == 0x63 || lbl_8064D18C == 0xD5) {
            if (*ref < actor->unk8) {
                mode &= ~0x200;
            }
        }
    }
    setting = actor->slots[slot].setting;
    if (alpha != 0) {
        mode |= 0x800;
    }
    if (setting != NULL && (setting->flags & 4) && setting->a == 0) {
        return 0;
    }
    if (useZ == 0) {
        mode &= ~4;
    }
    if (setting != NULL && (setting->flags & 6)) {
        mode |= 0x800;
    }
    if (setting != NULL && (setting->flags & 0x10)) {
        mode |= 0x8000;
    }
    if (setting != NULL && (setting->flags & 0x400)) {
        mode &= ~0x10;
    }
    if (actor->unk2D2 != 0) {
        fn_801ED5F4(1, actor->unk2D2, actor->unk2D4, actor->unk2B0, mtx, actor->unk2BC);
    } else if (setting != NULL && (setting->flags & 0x20) && !(actor->unk2D2 & 1)) {
        flags = 2;
        value = 100;
        if (setting->flags & 0x80) {
            flags |= 0x20;
        } else if (setting->flags & 0x200) {
            flags |= 8;
        } else {
            flags |= 0x10;
        }
        if (actor->unk244 == 0x52 || actor->unk244 == 0x53 || actor->unk244 == 0x54) {
            value = 1000;
        }
        fn_801ED5F4(1, flags, value, NULL, NULL, lbl_806500A4);
    } else if (setting != NULL && (setting->flags & 0x40) && !(actor->unk2D2 & 1)) {
        f = lbl_806500F4;
        if (setting->flags & 0x800) {
            float fade = lbl_806500A4 - (float)setting->a;
            f = fade * f;
        }
        fn_801ED5F4(1, 0x806, 100, NULL, NULL, f);
    } else {
        fn_801ED5F4(0, 0, 0, NULL, NULL, lbl_806500A0);
    }
    if ((lbl_8064D18C == 0x91 || lbl_8064D18C == 0x137 || lbl_8064D18C == 0x14E) &&
        actor->unk248 == 3 && inside != 0) {
        fn_801ECE7C(0xFF);
    } else if (fn_8011FAF4(actor) & 0x1000) {
        fn_801ECE7C(0xFF);
    } else if (dist > lbl_806500F8 || inside == 0) {
        mode &= ~0x80;
    } else {
        f = lbl_806500F8 - dist;
        level = f * scale;
        if (level > 0x80) {
            level = 0x80;
        }
        if (level < 0) {
            level = 0;
        }
        fn_801ECE7C((u8)level);
    }
    if (zflag == 0) {
        mode &= ~4;
    }
    fn_801EDA7C(model, lbl_8064D790, mode, 0);
    if (setting != NULL && (setting->flags & 6)) {
        tmp = model->color;
        if (setting->flags & 2) {
            tmp.r = setting->r;
            tmp.g = setting->g;
            tmp.b = setting->b;
        }
        if (setting->flags & 4) {
            tmp.a = setting->a;
        }
        c = tmp;
        fn_801ECD74(&c);
    }
    if (alpha != 0) {
        tmp2.a = alpha;
        tmp2.r = 0xFF;
        tmp2.g = 0xFF;
        tmp2.b = 0xFF;
        c2 = tmp2;
        fn_801ECD74(&c2);
    }
    return 1;
}
