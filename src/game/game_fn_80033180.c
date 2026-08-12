typedef unsigned char u8;
typedef int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct IVec3 {
    s32 x;
    s32 y;
    s32 z;
} IVec3;

typedef struct State {
    Vec3 position;
    u8 pad_0C[0x10];
    s32 object_id;
    u8 pad_20[6];
    u8 fade_in;
    u8 fade_out;
    u8 pad_28[3];
    u8 flags;
} State;

extern s32 lbl_8064D18C;
extern const float lbl_8064E1F4;

extern s32 fn_80200C10(void*);
extern void *fn_80201B8C();
extern int fn_80201B54();
extern void fn_80201D2C(void *, s32);
extern void fn_80201D14(void *, s32);
extern int fn_801E8328();
extern s32 fn_80032A0C(void);
extern void fn_801F6B6C(State* state, IVec3* position, s32 arg2, s32 arg3);
extern s32 fn_80032924(State* state, IVec3* position);
extern void fn_800329E8(State* state, u8 value);
extern void fn_80033038(State* state);
extern s32 fn_80032A5C(State* state);
extern void fn_80032E90(State* state, const Vec3* point);
extern unsigned long long fn_8020123C();

s32 fn_80033180(void* object, s32 action, void* event, s32* completed)
{
    s32 event_id;
    s32 object_id;
    State* state;
    u8* info;
    IVec3 screen;

    event_id = fn_80200C10(event);
    info = fn_80201B8C(object);
    object_id = fn_80201B54(object);
    state = *(State**)(info + 0x7C);

    if (action == 0) {
        if (event_id == 1) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        }
        if (event_id == 0x39) {
            fn_801E8328(2, object);
            return 1;
        }
        if (event_id == 0xC4) {
            state->flags |= 1;
            fn_80201D2C(object, 0xB);
            fn_80201D14(object, 1);
            return 1;
        }
    } else if (action == 0x26) {
        if (event_id == 3) {
            if (lbl_8064D18C == state->object_id &&
                fn_80032A0C() != 0) {
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        }
    } else if (action == 1) {
        if (event_id == 1) {
            fn_800329E8(state, 0);
            return 1;
        }
        if (event_id == 3) {
            if (lbl_8064D18C != state->object_id ||
                fn_80032A0C() == 0) {
                fn_80201D2C(object, 0x26);
                fn_80201D14(object, 1);
            } else {
                if (lbl_8064D18C != (*(State**)(info + 0x7C))->object_id) {
                    fn_80201D2C(object, 1);
                    fn_80201D14(object, 1);
                }
                fn_801F6B6C(state, &screen, 0, 0);
                if (fn_80032924(state, &screen) == 0) {
                    fn_80201D2C(object, 0xA);
                    fn_80201D14(object, 1);
                }
            }
            return 1;
        }
    } else if (action == 0xC) {
        if (event_id == 3) {
            if (lbl_8064D18C != state->object_id ||
                fn_80032A0C() == 0) {
                fn_80201D2C(object, 0x26);
                fn_80201D14(object, 1);
            } else {
                Vec3 point;
                fn_801F6B6C(state, &screen, 0, 5);
                point.x = (float)screen.x * lbl_8064E1F4;
                point.y = (float)screen.y * lbl_8064E1F4;
                point.z = (float)screen.z * lbl_8064E1F4;
                screen.x >>= 5;
                screen.y >>= 5;
                screen.z >>= 5;
                if (fn_80032924(state, &screen) != 0) {
                    fn_80201D2C(object, 0xB);
                    fn_80201D14(object, 1);
                }
                fn_80033038(state);
                fn_80032E90(state, &point);
            }
            return 1;
        }
    } else if (action == 0xA) {
        if (event_id == 1) {
            state->fade_in = 0xF;
            state->fade_out = 0;
            return 1;
        }
        if (event_id == 3) {
            if (lbl_8064D18C != state->object_id ||
                fn_80032A0C() == 0) {
                fn_80201D2C(object, 0x26);
                fn_80201D14(object, 1);
            } else {
                Vec3 point;
                fn_801F6B6C(state, &screen, 0, 5);
                point.x = (float)screen.x * lbl_8064E1F4;
                point.y = (float)screen.y * lbl_8064E1F4;
                point.z = (float)screen.z * lbl_8064E1F4;
                screen.x >>= 5;
                screen.y >>= 5;
                screen.z >>= 5;
                if (fn_80032924(state, &screen) != 0) {
                    fn_80201D2C(object, 0xB);
                    fn_80201D14(object, 1);
                } else if (fn_80032A5C(state) != 0) {
                    fn_80201D2C(object, 0xC);
                    fn_80201D14(object, 1);
                }
                fn_80032E90(state, &point);
            }
            return 1;
        }
    } else if (action == 0xB) {
        if (event_id == 1) {
            state->fade_in = 0;
            state->fade_out = 0xF;
            return 1;
        }
        if (event_id == 3) {
            if (lbl_8064D18C != state->object_id ||
                fn_80032A0C() == 0) {
                fn_80201D2C(object, 0x26);
                fn_80201D14(object, 1);
            } else {
                Vec3 point;
                s32 update = 1;
                fn_801F6B6C(state, &screen, 0, 5);
                point.x = (float)screen.x * lbl_8064E1F4;
                point.y = (float)screen.y * lbl_8064E1F4;
                point.z = (float)screen.z * lbl_8064E1F4;
                screen.x >>= 5;
                screen.y >>= 5;
                screen.z >>= 5;
                if (fn_80032924(state, &screen) == 0 && !(state->flags & 1)) {
                    fn_80201D2C(object, 0x26);
                    fn_80201D14(object, 1);
                } else if (fn_80032A5C(state) != 0) {
                    if (state->flags & 1) {
                        fn_8020123C(0x39, object_id, object_id, 0);
                        update = 0;
                    } else {
                        fn_80201D2C(object, 1);
                        fn_80201D14(object, 1);
                    }
                }
                if (update != 0) {
                    fn_80032E90(state, &point);
                }
            }
            return 1;
        }
    }

    return 0;
}
