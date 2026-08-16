typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct CallbackInfo {
    u8 pad_00[0x8C];
    void* object8C;
} CallbackInfo;

typedef struct CallbackObject {
    u8 pad_00[0xBC];
    s32 valueBC;
} CallbackObject;

typedef struct BoundObject {
    u8 pad_00[0x2A];
    u16 value2A;
} BoundObject;

extern u8 lbl_80303D18[0x78];

extern int fn_80200C10(void *);
extern int fn_80200C38();
extern s32 fn_80200C20(void*);
extern void fn_802006D4(s32, s32, s32, s32, s32);
extern void *fn_80201BC8();
extern int fn_80201B54();
extern void *fn_80201B8C();
extern void* fn_80201B94(void*);
extern int fn_80201AE4(void);
extern void fn_80201D14();
extern void fn_80201D1C(void *, s32);
extern void fn_80201D2C();
extern void fn_80201D34(void *, s32);
extern void fn_802020B4(void*, int);
extern void *fn_80201814();
extern BoundObject* fn_801FD6F4(void*);
extern void fn_8011FB54(void*, s32);
extern void fn_80046F28(void*, s32);
extern void fn_80046FC4(s32, s32);
extern void fn_8012B324(void*);
extern int fn_801E8328();
extern s32 fn_80128EAC(void*);
extern void *fn_8011F114();
extern float fn_8012B750(void*);
extern void fn_8011F0E8(void*, Vec3*);
extern void fn_8012B7A0(void*, float);
extern void *fn_801294DC(void *, int, int, int);
#define fn_801294DC(a, b, c, d) fn_801294DC((void *)(a), (b), (c), (d))
extern void fn_8012B344(void *);

s32 fn_80033970(void* callback, s32 action, void* event, s32* completed)
{
    s32 event_id = fn_80200C10(event);
    CallbackObject* state;
    void* object = fn_80201BC8(callback);
    s32 object_id = fn_80201B54(callback);
    state = (CallbackObject*)((CallbackInfo*)fn_80201B8C(callback))->object8C;

    fn_80201B94(callback);

    if (action == 0) {
        if (event_id == 1) {
            fn_80201D2C(callback, 1);
            fn_80201D14(callback, 1);
            return 1;
        }

        if (event_id == 0xF0) {
            s32 value = fn_80200C38(event);

            fn_802006D4(object_id, object_id, -1, 0x69, 0);
            fn_80201D34(callback, value);
            fn_80201D1C(callback, 1);
            if (completed != 0) {
                *completed = 1;
            }
            return 1;
        }

        if (event_id == 0x3D) {
            return 1;
        }
        if (event_id == 0x3E) {
            return 1;
        }

        if (event_id == 0x69) {
            s32 value = fn_80200C38(event);
            BoundObject* bound;

            fn_80200C20(event);
            bound = fn_801FD6F4(*(void**)lbl_80303D18);
            fn_8011FB54(object, value);
            fn_80046F28(callback, value);
            if (object_id == fn_80201AE4()) {
                fn_80046FC4(value, 0);
            }
            if (bound != 0) {
                bound->value2A = value;
            }
            state->valueBC = 0;
            fn_80201D2C(callback, 1);
            fn_80201D14(callback, 1);
            return 1;
        }

        if (event_id == 0x39) {
            fn_8012B324(object);
            fn_80201D34(callback, 0);
            fn_80201D1C(callback, 1);
            fn_801E8328(2, callback);
            return 1;
        }

        if (event_id == 0xD5) {
            state->valueBC = fn_80200C38(event);
            fn_80201D2C(callback, 3);
            fn_80201D14(callback, 1);
            return 1;
        }

        if (event_id == 0xFA) {
            s32 value = fn_80200C38(event);

            switch (value) {
            case 13:
                fn_802020B4(callback, 1);
                break;
            case 12:
                fn_802020B4(callback, 0);
                break;
            }
            return 1;
        }
    } else if (action == 1) {
        if (event_id == 3) {
            return 1;
        }
    } else if (action == 3) {
        if (event_id == 1) {
            return 1;
        }

        if (event_id == 3) {
            void* target = fn_80201814(state->valueBC);
            void* target_object = target != 0 ? fn_80201BC8(target) : 0;

            if (target != 0 && target_object != 0) {
                s32 target_type = fn_80128EAC(target_object);
                s32 object_type = fn_80128EAC(object);
                Vec3 position;
                Vec3 target_position;
                float scale;

                fn_8011F114(&target_position, target_object);
                position = target_position;
                scale = fn_8012B750(target_object);
                fn_8011F0E8(object, &position);
                fn_8012B7A0(object, scale);
                if (object_type != target_type) {
                    if (fn_801294DC(object, target_type, 0x20, 1) == 0) {
                        fn_8012B344(object);
                        fn_801294DC(object, target_type, 0x20, 1);
                    }
                }
            } else {
                state->valueBC = 0;
                fn_80201D2C(callback, 1);
                fn_80201D14(callback, 1);
            }
            return 1;
        }

        if (event_id == 2) {
            fn_802006D4(object_id, object_id, -1, 0x69, 0);
            return 1;
        }
    } else {
        return 0;
    }

    return 0;
}
