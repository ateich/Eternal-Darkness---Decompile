typedef unsigned char u8;
typedef int s32;

typedef struct CallbackState {
    char unk00[0x9F];
    volatile u8 mode;
} CallbackState;

extern const s32 lbl_8064E0B4;
extern const s32 lbl_8064E0B8;
extern const float lbl_8064E0BC;
extern const float lbl_8064E0C0;
extern s32 lbl_80651908;

extern int fn_80200C10(void *);
extern void *fn_80201BC8();
extern int fn_80201B54();
extern void *fn_80201B8C();
extern int fn_80201EB8();
extern void fn_80128754(s32, s32);
extern void fn_8011FA8C(void*, int, int);
extern void fn_802020B4(void*, int);
extern void fn_8020104C(int, void *, void *, int, float);
#define fn_8020104C(a, b, c, d, e) fn_8020104C((a), (void *)(b), (void *)(c), (int)(d), (e))
extern void fn_8012C62C(void*, s32, void*, void*, void*, s32);
extern void fn_80201D2C();
extern void fn_80201D14();
extern int fn_801E8328();
extern void fn_80201D34(void *, s32);
extern void fn_80201D1C(void *, s32);
extern s32 fn_80120BD0(s32);
extern unsigned long long fn_8020123C();

s32 fn_8002D17C(void* callback, s32 phase, void* event)
{
    s32 event_id = fn_80200C10(event);
    s32 object = (s32)fn_80201BC8(callback);
    s32 object_id = fn_80201B54(callback);
    CallbackState* state = fn_80201B8C(callback);

    if (phase == 0) {
        if (event_id == 1) {
            s32 resource = fn_80201EB8(callback);

            fn_80128754(object, -1);
            fn_8011FA8C((void*)object, 0x20000000, 0);
            fn_802020B4(callback, 0);

            if ((resource == 0x199 || resource == 0x60 || resource == 0xB9) &&
                (unsigned int)object != 0) {
                s32 value0;
                s32 value1;
                s32 value2;

                fn_8020104C(0x39, fn_80201B54(callback),
                            fn_80201B54(callback), 0, lbl_8064E0BC);
                value2 = lbl_80651908;
                value1 = lbl_8064E0B8;
                value0 = lbl_8064E0B4;
                fn_8012C62C((void*)object, 0xF, &value0, &value1, &value2, 4);
            } else {
                fn_8020104C(0x39, fn_80201B54(callback),
                            fn_80201B54(callback), 0, lbl_8064E0C0);
            }

            if ((unsigned int)object != 0) {
                if (state->mode == 6) {
                    fn_8011FA8C((void*)object, 0x180, 0);
                } else {
                    fn_8011FA8C((void*)object, 0x180, 0);
                }
            }

            fn_80201D2C(callback, 1);
            fn_80201D14(callback, 1);
            return 1;
        }
        if (event_id == 0x39) {
            fn_801E8328(2, callback);
            fn_80201D34(callback, 0);
            fn_80201D1C(callback, 1);
            return 1;
        }
        goto unhandled;
    }

    if (phase == 1) {
        if (event_id != 3) {
            goto unhandled;
        }
        if ((unsigned int)object != 0 && fn_80120BD0(object) != 0) {
            fn_8020123C(0x39, object_id, object_id, 0);
        }
        return 1;
    }

    return 0;

unhandled:
    return 0;
}
