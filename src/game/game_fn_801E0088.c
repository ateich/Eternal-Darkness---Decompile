typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Vec3 { float x, y, z; } Vec3;
typedef float Matrix34[3][4];

extern int lbl_8064D18C;
extern int lbl_8064C544;
extern u8 lbl_8023B5C0[];
extern float lbl_806511B8, lbl_806511CC;
extern void* fn_80201814(int);
extern int fn_80036D5C(void);
extern void fn_80036DA4(void*, unsigned int);
extern int fn_80201B5C(void*);
extern void fn_80201D44(void*, int);
extern void fn_80201D24(void*, int);
extern void fn_802015A4(void*);
extern void fn_801D7E70(int, int);
extern void fn_801FE22C(int);
extern void fn_8020123C(int, int, int, int);
extern void fn_801B05B0(int, int);
extern void fn_801E1920(void*);
extern void fn_801FE934(int, int);
extern int fn_801D3A34(int, int);
extern u8 fn_801CEB2C(int);
extern void fn_8014EAA4();
extern void fn_801D0C94(void);
extern void fn_801D0C9C(void);
extern void fn_801D70B0();
extern int fn_800A4F98(int);
extern void* fn_80201BC8(void*);
extern int fn_801D38E8(int);
extern void fn_801D62D0();
extern void* fn_8011FE34(void*);
extern void fn_802114E0(Matrix34, void*);
extern void fn_8011F114(Vec3*, void*);
extern void fn_80211710(Matrix34, Vec3*, Vec3*);
extern void fn_80211A6C(Vec3*, Vec3*, Vec3*);
extern void fn_80211A48(Vec3*, Vec3*, Vec3*);
extern float fn_80211B44(Vec3*, Vec3*);
extern u32 fn_8006749C(int);
extern void fn_80120AD0(void*, Vec3*, int, u16, float, float);
extern int fn_8012A100(void*, int);
extern void* fn_801294DC(void*, int, int, int);
extern void fn_80128C44(void*, void*, int);
extern void fn_801DE7A0(int);
extern void fn_801DE8AC(void);

/* NonMatching: honest-C reconstruction of the complete common teardown path
 * and selected event arms. The remaining large event dispatcher is not yet
 * reconstructed. */
void fn_801E0088(void* object)
{
    u8* info = object;
    u8* constants = lbl_8023B5C0;
    void* handle;
    int result;
    int a, b, c, d;
    void* target;
    void* effect;
    float distance;
    u32 flags;
    Matrix34 transform;
    Vec3 position, from, to;
    (void)constants;

    if (*(int*)(info + 8) != lbl_8064D18C || (info[0xff0] & 1)) {
        handle = fn_80201814(*(int*)(info + 0xe0));
        if (handle) {
            fn_80036DA4(handle, fn_80036D5C() | 0x08000000);
            result = fn_80201B5C(handle);
            if (result == 0 || result == 40) {
                fn_80201D44(handle, *(int*)(info + 0x13c));
                fn_80201D24(handle, 1);
                fn_802015A4(handle);
            }
            if (!(info[0xff0] & 0x10) && !(info[0xff0] & 1) &&
                *(void (**)(void*, int))(info + 0x28))
                (*(void (**)(void*, int))(info + 0x28))(info, *(int*)(info + 0x2c));
        }
        if (*(u16*)(info + 0xff4) && (info[0xff0] & 0x10))
            fn_801D7E70(*(int*)(info + 0xc), 1);
        fn_801FE22C(*(int*)(info + 0x44));
        if (info[0xff0] & 0x10) {
            if (fn_80201814(lbl_8064C544))
                fn_8020123C(8, lbl_8064C544, lbl_8064C544, 0);
            lbl_8064C544 = *(int*)(info + 0xe0);
            fn_8020123C(195, *(int*)(info + 0xc), *(int*)(info + 0xc), 0);
        }
        if (*(int*)(info + 0x10) != -1)
            fn_801B05B0(*(int*)(info + 0x10), 10);
        fn_801E1920(info);
        return;
    }

    switch (*(u16*)(info + 0xff4)) {
    case 0:
        if (info[0xff0] & 0x10) {
            fn_801D70B0(-1, (*(int*)(info + 4) & -0x821) | 0x410,
                        *(int*)(info + 0xc), info + 0x38, 2, 0,
                        fn_801D0C9C, 0, fn_801D0C94, 0);
            a = fn_800A4F98(2);
            if (fn_80201814(a))
                fn_8020123C(8, a, a, 0);
        }
        break;
    case 20:
        fn_801FE934(*(int*)(info + 0x44), 5);
        break;
    case 40:
        d = fn_801D3A34(*(int*)(info + 4), 0x4e);
        c = fn_801D3A34(*(int*)(info + 4), 0x4a);
        b = fn_801D3A34(*(int*)(info + 4), 0x46);
        a = fn_801D3A34(*(int*)(info + 4), 0x35);
        fn_8014EAA4(info + 0x38, 250, fn_801CEB2C(*(int*)(info + 4)), a, b, c, d, 4);
        break;
    case 170:
        if (!(info[0xff0] & 0x10)) {
            handle = fn_80201814(*(int*)(info + 0xe0));
            if (*(int*)(info + 0x13c) == 6) {
                fn_80201D44(handle, 6);
                fn_80201D24(handle, 1);
                fn_802015A4(handle);
            } else if (*(int*)(info + 0x13c) == 5) {
                fn_80201D44(handle, 5);
                fn_80201D24(handle, 1);
                fn_802015A4(handle);
            }
        }
        if (!(info[0xff0] & 0x10) || ((*(int*)(info + 4) & 15) != 8)) {
            if (*(int*)(info + 0x13c) == 6) {
                from = *(Vec3*)(constants + 0xb4);
                to = *(Vec3*)(constants + 0xc0);
                target = fn_80201BC8(fn_80201814(*(int*)(info + 0xe0)));
                fn_802114E0(transform, fn_8011FE34(target));
                fn_8011F114(&position, target);
                fn_80211710(transform, &from, &from);
                fn_80211710(transform, &to, &to);
                fn_80211A6C(&to, &from, &to);
                fn_80211A48(&position, &from, &from);
                distance = fn_80211B44(&to, &from);
                flags = fn_8006749C(fn_801D38E8(*(int*)(info + 4))) | 0x4000;
                fn_80120AD0(target, &to, 100, flags, distance, lbl_806511CC);
            } else if (*(int*)(info + 0x13c) == 5) {
                from = *(Vec3*)(constants + 0xcc);
                to = *(Vec3*)(constants + 0xd8);
                target = fn_80201BC8(fn_80201814(*(int*)(info + 0xe0)));
                from.z = lbl_806511B8 + *(float*)(info + 0x110);
                distance = fn_80211B44(&to, &from);
                flags = fn_8006749C(fn_801D38E8(*(int*)(info + 4))) | 0x4000;
                fn_80120AD0(target, &to, 100, flags, distance, lbl_806511CC);
            } else {
                break;
            }
            if (fn_8012A100(target, 0x8a)) {
                if (info[0xff0] & 0x10) {
                    effect = fn_801294DC(target, 0x8a, 0x20, 9);
                    if (effect)
                        fn_80128C44(effect, fn_801DE8AC, 0);
                } else {
                    fn_801DE7A0(*(int*)(info + 0xe0));
                }
            }
        }
        break;
    case 285:
        if (*(int*)(info + 0x13c) == 5) {
            a = *(int*)(info + 0xe0);
            fn_80201BC8(fn_80201814(a));
            result = fn_801D38E8(*(int*)(info + 4));
            fn_801D62D0(a, 24, 2, a, 23, 3, result, 0,
                        0, 4, 7, 2, 3, 1, 0, 1, 17, 10, 4, 60,
                        0, 1, 68, 0x42800, 0, 4);
        }
        break;
    case 350:
        if (*(int*)(info + 0x13c) == 6) {
            if (*(void (**)(void*, int))(info + 0x28))
                (*(void (**)(void*, int))(info + 0x28))(info, *(int*)(info + 0x2c));
            fn_801E1920(info);
        }
        break;
    case 400:
        if (*(int*)(info + 0x13c) == 5) {
            if (*(void (**)(void*, int))(info + 0x28))
                (*(void (**)(void*, int))(info + 0x28))(info, *(int*)(info + 0x2c));
            fn_801E1920(info);
        }
        break;
    case 460:
        if (*(int*)(info + 0x13c) == 4) {
            if (*(void (**)(void*, int))(info + 0x28))
                (*(void (**)(void*, int))(info + 0x28))(info, *(int*)(info + 0x2c));
            handle = fn_80201814(*(int*)(info + 0xe0));
            fn_80036DA4(handle, fn_80036D5C() & ~0x08000000);
            fn_801E1920(info);
        }
        break;
    }
}
