typedef unsigned int u32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

typedef struct Color {
    u8 r, g, b, a;
} Color;

typedef struct ColorDelta {
    s8 r, g, b, a;
} ColorDelta;

extern Color lbl_806515D0;
extern ColorDelta lbl_806515D4;
extern ColorDelta lbl_806515D8;
extern float lbl_806515DC;
extern float lbl_806515E0;
extern float lbl_806515E4;
extern Color lbl_80651F70;

extern int fn_80200C10(void *data);
extern int fn_80200C38(void *data);
extern void *fn_80155DB4(void *object);
extern void *fn_80201BC8(void *object);
extern void *fn_80201B54(void *object);
extern u32 fn_8011FAEC(void *object);
extern int fn_8011EB1C(void *object);
extern void *fn_80126880(void *object);
extern void fn_8020104C(int type, void *a, void *b, int value, float amount);
extern void fn_8020123C(int type, void *a, void *b, int value);
extern void fn_80201D2C(void *object, int value);
extern void fn_80201D14(void *object, int value);
extern void fn_801E8328(int value, void *object);
extern void fn_801568C0(void *object, void (*callback)(void));
extern void fn_8012C198(void *object);
extern void fn_8011FABC(void *object, int value, int other);
extern void fn_8012C774(u8* state, Color a, ColorDelta b, Color c, int flags);
extern void fn_8011FA8C(void *object, int value, int flags);
extern void fn_80205DB8(void);

int fn_80205914(void *object, int event, void *data)
{
    int data_type = fn_80200C10(data);
    void *handle = fn_80155DB4(object);
    void *target = fn_80201BC8(object);
    void *effect = fn_80201B54(object);

    if (event == 0) {
        if (data_type == 1) {
            if (fn_8011FAEC(target) & 0x2000) {
                fn_8020104C(0x11, effect, effect, 0, lbl_806515DC);
                fn_80201D2C(object, 0xB);
                fn_80201D14(object, 1);
            } else {
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        }
        if (data_type == 0x39) {
            fn_801E8328(2, object);
            fn_80201D2C(object, 0);
            fn_80201D14(object, 1);
            return 1;
        }
        if (data_type == 0x3D) {
            fn_80126880(fn_80201BC8(object));
            fn_8020123C(0x39, effect, effect, 0);
            return 1;
        }
        if (data_type == 0x59) {
            fn_80126880(fn_80201BC8(object));
            fn_8020123C(0x39, effect, effect, 0);
            return 1;
        }
        if (data_type == 0x1C) {
            if (fn_80200C38(data) != 0 && fn_8011EB1C(target) == 6) {
                fn_80126880(target);
                fn_8020123C(0x39, effect, effect, 0);
            }
            return 1;
        }
        if (data_type == 0xE5) {
            if (fn_8011EB1C(target) == 6) {
                fn_80126880(target);
                fn_8020123C(0x39, effect, effect, 0);
            }
            return 1;
        }
    } else if (event == 1) {
        if (data_type == 0x47) {
            fn_80201D2C(object, 0x23);
            fn_80201D14(object, 1);
            return 1;
        }
        if (data_type == 0x11) {
            fn_80201D2C(object, 0xB);
            fn_80201D14(object, 1);
            return 1;
        }
    } else if (event == 0x23) {
        if (data_type == 1) {
            fn_801568C0(handle, fn_80205DB8);
            fn_8012C198(target);
            fn_8011FABC(target, 8, 0);
            return 1;
        }
        if (data_type == 0x2E) {
            fn_8020104C(0x11, effect, effect, 0, lbl_806515E0);
            fn_80201D2C(object, 0xB);
            fn_80201D14(object, 1);
            return 1;
        }
    } else if (event == 0xB) {
        if (data_type == 0x11) {
            Color a = lbl_806515D0;
            ColorDelta b = lbl_806515D4;
            ColorDelta alternate = lbl_806515D8;
            Color c = lbl_80651F70;

            if (!(fn_8011FAEC(target) & 0x2000)) {
                b = alternate;
            }
            fn_8012C774(target, a, b, c, 4);
            fn_8011FA8C(target, 0, 0x2000);
            fn_8020104C(0x39, effect, effect, 0, lbl_806515E4);
            return 1;
        }
    } else {
        return 0;
    }
    return 0;
}
