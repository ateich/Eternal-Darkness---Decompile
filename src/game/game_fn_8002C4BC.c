typedef int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct EventPlacementState {
    void* object;
    s32 mode;
    Vec3 origin;
    Vec3 first;
    Vec3 second;
} EventPlacementState;

extern const s32 lbl_8064E080;
extern const s32 lbl_8064E084;
extern const float lbl_8064E088;
extern const float lbl_8064E08C;
extern const float lbl_8064E090;
extern const Vec3 lbl_8023E410;
extern const Vec3 lbl_8023E41C;

extern s32 fn_80200C10(void*);
extern void* fn_80201B8C();
extern int fn_80201B54();
extern void fn_80201D2C(void*, s32);
extern void fn_80201D14(void*, s32);
extern int fn_801E8328();
extern void fn_80201D34(void*, s32);
extern void fn_80201D1C(void*, s32);
extern void* fn_80201814();
extern void* fn_80201BC8();
extern void fn_8011F114(void*, void*);
extern void fn_8017AB08(const Vec3*, Vec3*, float);
extern void fn_8012B690(void*, Vec3*, Vec3*);

s32 fn_8002C4BC(void* callback, s32 phase, void* event)
{
    s32 event_id = fn_80200C10(event);
    EventPlacementState* placement = *(EventPlacementState**)((char*)fn_80201B8C(callback) + 0x10);
    s32 object_id = fn_80201B54(callback);

    if (phase == 0) {
        if (event_id == 1) {
            placement->mode = lbl_8064E080;
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
        goto event_unhandled;
    }

    if (phase == 1) {
        if (event_id == 5) {
            placement->mode = lbl_8064E084;
            return 1;
        }
        if (event_id == 3) {
            Vec3 position;
            Vec3 direction;
            void* state = fn_80201BC8(fn_80201814(placement->object));

            fn_8011F114(&position, state);
            placement->origin.x = position.x;
            placement->origin.y = position.y;
            placement->origin.z = lbl_8064E088 + position.z;
            fn_8017AB08(&lbl_8023E410, &direction, lbl_8064E08C);
            fn_8012B690(state, &direction, &direction);
            placement->first.x = direction.x * lbl_8064E090 + placement->origin.x;
            placement->first.y = direction.y * lbl_8064E090 + placement->origin.y;
            placement->first.z = placement->origin.z;
            fn_8017AB08(&lbl_8023E410, &direction, -lbl_8064E08C);
            fn_8012B690(state, &direction, &direction);
            placement->second.x = direction.x * lbl_8064E090 + placement->origin.x;
            placement->second.y = direction.y * lbl_8064E090 + placement->origin.y;
            placement->second.z = placement->origin.z;
            return 1;
        }
        goto event_unhandled;
    }

    if (phase == 3) {
        if (event_id == 3) {
            Vec3 position;
            Vec3 direction;
            void* state = fn_80201BC8(fn_80201814(placement->object));

            fn_8011F114(&position, state);
            placement->origin.x = position.x;
            placement->origin.y = position.y;
            placement->origin.z = lbl_8064E088 + position.z;
            fn_8017AB08(&lbl_8023E41C, &direction, lbl_8064E08C);
            fn_8012B690(state, &direction, &direction);
            placement->first.x = direction.x * lbl_8064E090 + placement->origin.x;
            placement->first.y = direction.y * lbl_8064E090 + placement->origin.y;
            placement->first.z = placement->origin.z;
            fn_8017AB08(&lbl_8023E41C, &direction, -lbl_8064E08C);
            fn_8012B690(state, &direction, &direction);
            placement->second.x = direction.x * lbl_8064E090 + placement->origin.x;
            placement->second.y = direction.y * lbl_8064E090 + placement->origin.y;
            placement->second.z = placement->origin.z;
            return 1;
        }
        goto event_unhandled;
    }

    return 0;

event_unhandled:
    return 0;
}
