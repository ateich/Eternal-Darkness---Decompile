typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct Vec3_80094278 {
    float x, y, z;
} Vec3_80094278;

typedef struct Actor_80094278 {
    u32 flags;
    u8 pad04[0x50];
    s32 field54;
    u8 pad58[0x3C];
    s32 field94;
    u8 pad98[0xB8];
    s16 field150;
    u8 pad152[0xF];
    s8 field161;
} Actor_80094278;

typedef struct State_80094278 {
    u8 pad00[0x8C];
    Actor_80094278 *actor;
    u8 pad90[0xC];
    s16 field9C;
} State_80094278;

extern char lbl_80245238[];
extern char lbl_8064B5F8[7];
extern char lbl_8064B600[8];
extern char lbl_8064B608[4];
extern s32 lbl_8064D5A8;
extern const float lbl_8064EC7C;
extern const float lbl_8064ECA8;
extern const float lbl_8064ECAC;
extern const float lbl_8064ECB0;
extern const float lbl_8064ECB4;

extern int fn_80200C10(void *);
extern void *fn_80201BC8();
extern void *fn_80201B8C();
extern void *fn_80201B94();
extern int fn_80201B54();
extern void fn_8011F114();
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_80201D34(void *, int);
extern void fn_80201D1C(void *, int);
extern unsigned long long fn_8020123C();
extern int fn_80200C20();
extern int fn_80200C28();
extern int fn_80200C38();
extern void fn_800EA3A0(void *, void *);
extern void fn_800BD2DC(void *, void *);
extern void fn_800BD194(void *, void *);
extern void fn_800C9E50(void *);
extern void fn_80062ED0(void *, void *, void *, int *);
extern void fn_80093C04(void *, void *, void *, int *);
extern void fn_80068994(void *, void *);
extern void fn_80064B38(void *, void *, int *);
extern void fn_80093D20(void *, void *);
extern void fn_801A7228();
extern int fn_800654F8();
extern void fn_80066754(void *, void *, int *);
extern void fn_80066888(void *, int, float, float);
extern void fn_8012B324(void *);
extern void fn_8012B344(void *);
extern void fn_801E8328(int, void *);
extern void fn_800EA0FC(void *, void *, int, void *, int *);
extern int fn_80093B80(void *, void *, void *, int, int);
extern int fn_800BE86C(void *, void *, int, int, float);
extern void fn_801294DC(void *, int, int, int);
extern int fn_80128EAC(void *);
extern int fn_801290D0(void *);
extern void fn_80128F74(void *, int);
extern void fn_800BE010(void *, void *);
extern int fn_80201C48(void *);
extern void fn_800BDEE4(void *, void *);
extern int fn_800CA7D4(int, void *, void *, void *, int, int);
extern void fn_800938E4(void *, void *, void *);
extern void fn_80093F6C(void *, void *, int, void *, void *, int, int);
extern s32 fn_80035FB8(void *, char *, char *, char *, char *, char *);
extern void fn_800BE8D4(int);
extern void fn_801AC9F4(int, int, Vec3_80094278 *, int);
extern void *fn_80201B9C();
extern void *fn_80204844(void *, int);
extern int fn_8011FAEC(void *);
extern void fn_8011FADC(void *, int);
extern void fn_800CA2C8(void *);
extern void fn_80204FDC(void *);
extern void fn_8003E5DC(void *, void *, int, void *);
extern void fn_800CF598(void *);
extern void fn_80120AD0(void *, int, int, int, float, float);
extern void fn_802006D4(int, int, int, int, int);

int fn_80094278(void *object, int state, void *event, int *result)
{
    int message;
    char *strings = lbl_80245238;
    Actor_80094278 *actor;
    void *parent;
    void *model;
    int owner;
    int base;
    int kind;
    State_80094278 *info;
    Vec3_80094278 position;

    message = fn_80200C10(event);
    model = fn_80201BC8(object);
    info = fn_80201B8C(object);
    actor = info->actor;
    parent = fn_80201B94(object);
    owner = fn_80201B54(object);
    fn_8011F114(&position, model);
    base = lbl_8064D5A8 + info->field9C;
    kind = info->actor->field161;

    if (message == 3) {
        actor->field150 = actor->field150 >= 1 ? actor->field150 - 1 : 0;
    }

    if (state == 0) {
        if (message == 1) {
            if (actor->flags & 0x40000) {
                actor->flags = actor->flags & ~0x40000;
                fn_80201D2C(object, 0x21);
                fn_80201D14(object, 1);
            } else {
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        } else if (message == 0x3B) {
            if (result != 0) {
                *result = 1;
            }
            return 1;
        } else if (message == 0x3D) {
            fn_800EA3A0(object, actor);
            fn_800BD2DC(object, actor);
            return 1;
        } else if (message == 0x20) {
            fn_80062ED0(object, model, event, result);
            return 1;
        } else if (message == 0x3E) {
            fn_800BD194(object, actor);
            fn_800C9E50(object);
            return 1;
        } else if (message == 0x7D) {
            if (fn_80200C38(event) != 0) {
                fn_80093C04(object, model, event, result);
            } else if (result != 0) {
                *result = 1;
            }
            return 1;
        } else if (message == 0xE) {
            fn_80068994(object, event);
            return 1;
        } else if (message == 0x27) {
            fn_80064B38(object, event, result);
            return 1;
        } else if (message == 8) {
            fn_80093D20(object, event);
            return 1;
        } else if (message == 0xED) {
            fn_8020123C(0xB, fn_80200C20(event), fn_80200C28(event), fn_80200C38(event));
            fn_801A7228(fn_80200C38(event));
            return 1;
        } else if (message == 0x3A) {
            fn_8020123C(0x27, fn_80200C20(event), fn_80200C28(event), fn_80200C38(event));
            fn_801A7228(fn_80200C38(event));
            return 1;
        } else if (message == 0xB) {
            int value = fn_800654F8(fn_80200C38(event));
            if (result != 0) {
                *result = value;
            }
            return 1;
        } else if (message == 0x35) {
            fn_80066754(object, event, result);
            return 1;
        } else if (message == 0xE6) {
            fn_80066888(model, fn_80200C38(event), lbl_8064ECA8, lbl_8064ECAC);
            return 1;
        } else if (message == 0x39) {
            fn_800EA3A0(object, actor);
            fn_8012B324(model);
            fn_80201D34(object, 0);
            fn_80201D1C(object, 1);
            fn_801E8328(2, object);
            return 1;
        } else if (message == 0x33) {
            fn_8020123C(0x39, owner, owner, 0);
            return 1;
        } else if (message == 0xF3) {
            int value = fn_80200C38(event);

            fn_800EA0FC(object, actor, value, event, result);
            return 1;
        }
    } else if (state == 1) {
        if (message == 3) {
            fn_80093B80(object, model, event, base, kind);
            return 1;
        }
    } else if (state == 0x15) {
        if (message == 1) {
            fn_8012B344(model);
            return 1;
        } else if (message == 3) {
            if (fn_80093B80(object, model, event, base, kind) == 0 &&
                fn_800BE86C(model, &actor->field94, 2, 0, lbl_8064ECB0) == 0) {
                fn_801294DC(model, 0xF, 0x25, 1);
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        } else if (message == 2) {
            int mode = fn_80128EAC(model);
            int bits = fn_801290D0(model);
            if ((bits & 4) && (mode == 3 || mode == 2)) {
                fn_80128F74(model, bits & ~4);
            }
            return 1;
        }
    } else if (state == 3) {
        if (message == 3) {
            fn_800BE010(object, actor);
            if (fn_80201C48(parent) != 0) {
                fn_800BDEE4(object, actor);
            }
            if (fn_800CA7D4(owner, object, actor, model, 0x1E, 1) != 0) {
                fn_800938E4(object, model, event);
            } else {
                fn_80093F6C(object, model, owner, actor, event, base, kind);
            }
            return 1;
        } else if (message == 0x66) {
            fn_8012B344(model);
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        }
    } else if (state == 6) {
        if (message == 0xC) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (message == 7) {
            if (fn_80035FB8(object, strings, lbl_8064B5F8, strings + 0x10, lbl_8064B600, strings + 0x1C) == 0) {
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        }
    } else if (state == 7) {
        if (message == 0x36) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (message == 7) {
            if (fn_80035FB8(object, strings, lbl_8064B608, strings + 0x10, lbl_8064B600, strings + 0x1C) == 0) {
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        }
    } else if (state == 0x21) {
        if (message == 1) {
            fn_800BE8D4(owner);
            return 1;
        } else if (message == 6) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (message == 2) {
            fn_801AC9F4(0x77, 0x64, &position, 2);
            return 1;
        } else if (message == 0x35) {
            return 1;
        } else if (message == 0x7D) {
            return 1;
        } else if (message == 0xA7) {
            return 1;
        } else if (message == 0x20) {
            return 1;
        } else if (message == 0x93) {
            return 1;
        } else if (message == 0x20) {
            return 1;
        } else if (message == 0x6B) {
            return 1;
        } else if (message == 0x3B) {
            return 1;
        } else if (message == 0x35) {
            return 1;
        } else if (message == 0x37) {
            return 1;
        } else if (message == 0x32) {
            return 1;
        } else if (message == 0xB) {
            return 1;
        } else if (message == 0x27) {
            return 1;
        }
    } else if (state == 0x38) {
        if (message == 1) {
            return 1;
        } else if (message == 8) {
            fn_8020123C(0x7E, owner, actor->field54, 0);
            fn_80093D20(object, event);
            return 1;
        } else if (message == 0x7E) {
            actor->field54 = 0;
            fn_8012B344(model);
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (message == 0x39) {
            fn_800EA3A0(object, actor);
            fn_8020123C(0x7E, owner, actor->field54, 0);
            actor->field54 = 0;
            fn_8012B324(model);
            fn_80201D34(object, 0);
            fn_80201D1C(object, 1);
            fn_801E8328(2, object);
            return 1;
        } else if (message == 0x3D) {
            fn_800EA3A0(object, actor);
            fn_800BD2DC(object, actor);
            fn_8020123C(0x39, owner, owner, 0);
            return 1;
        } else if (message == 0x80) {
            return 1;
        } else if (message == 2) {
            return 1;
        } else if (message == 0x35) {
            return 1;
        } else if (message == 0x20) {
            return 1;
        }
    } else if (state == 8) {
        if (message == 1) {
            int bits;

            fn_80204844(fn_80201B9C(), 0x20);
            bits = fn_8011FAEC(model);
            fn_8011FADC(model, bits & ~0xC0);
            fn_800CA2C8(object);
            fn_80204FDC(object);
            return 1;
        } else if (message == 3) {
            fn_8003E5DC(object, model, owner, actor);
            return 1;
        } else if (message == 0x3D) {
            fn_800EA3A0(object, actor);
            fn_800BD2DC(object, actor);
            fn_8020123C(0x39, owner, owner, 0);
            return 1;
        } else if (message == 0x11) {
            fn_800EA3A0(object, actor);
            fn_800CF598(object);
            fn_80120AD0(model, 0, 0, 0x101, lbl_8064ECB4, lbl_8064EC7C);
            fn_801294DC(model, 0x28, 0x25, 0xA);
            fn_80201D34(object, 0x15);
            fn_80201D1C(object, 1);
            return 1;
        } else if (message == 2) {
            fn_802006D4(owner, owner, 8, 0x11, 0);
            return 1;
        } else if (message == 0x3B) {
            return 1;
        } else if (message == 0x35) {
            return 1;
        } else if (message == 0x37) {
            return 1;
        } else if (message == 8) {
            return 1;
        } else if (message == 0xB) {
            return 1;
        } else if (message == 0x27) {
            return 1;
        } else if (message == 0x7D) {
            return 1;
        } else if (message == 0x20) {
            return 1;
        }
    } else {
        return 0;
    }
    return 0;
}
