typedef int s32;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct ObjectState {
    u8 pad_00[0x2C];
    u32 flags;
} ObjectState;

typedef struct ObjectInfo {
    u8 pad_00[0x68];
    ObjectState* state;
    u8 pad_6C[0x33];
    u8 type;
} ObjectInfo;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern void* fn_80201814(s32);
extern ObjectInfo* fn_80201B8C(void*);

s32 fn_8000B444(void* script)
{
    void* object;
    ObjectInfo* info;
    s32 enabled;
    s32 object_id;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    object_id = (s32)fn_8016A694(script, 1);
    enabled = (s32)fn_8016A694(script, 2);
    object = fn_80201814(object_id);
    info = object != 0 ? fn_80201B8C(object) : 0;

    if (object != 0 && info != 0 && info->type == 10 && info->state != 0) {
        if (enabled != 0) {
            info->state->flags |= 0x100;
        } else {
            info->state->flags &= 0xFFFFFEFF;
        }
    }
    return 0;
}
