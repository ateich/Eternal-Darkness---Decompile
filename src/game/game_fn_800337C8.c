typedef unsigned short u16;
typedef int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Effect {
    unsigned char pad_00[0x2E];
    u16 flags;
} Effect;

extern const Vec3 lbl_80238D64;
extern volatile s32 lbl_8064D18C;
extern const float lbl_8064E034;
extern const float lbl_8064E138;

extern void fn_801D38BC(s32 object_id, s32* value, short* type);
extern void fn_80211A90(Vec3* output, const Vec3* input, float scale);
extern void fn_80211A48(Vec3* output, const Vec3* left, const Vec3* right);
extern void fn_80152530(Vec3* position, short type, s32 owner, s32 mode,
                        s32* value, Vec3* direction);
extern s32 fn_801D3A24(s32 object_id, s32 property);
extern void fn_80152A88(Vec3* position, Vec3* direction, short type, s32 mode);
extern s32 fn_801D39E0(s32 object_id);
extern void fn_801E2B28(Effect* effect, Vec3* position, s32* value, s32 mode,
                        s32 arg4);
extern void fn_801AAE68(float intensity, s32 effect_type, s32 arg2, s32 arg3,
                        Vec3* position, s32 arg5, s32 arg6, s32 arg7,
                        u16 owner, s32 arg9);

void fn_800337C8(Vec3* position, const Vec3* offset, s32 object_id,
                 Effect* effect, s32 owner, s32 play_sound)
{
    register Vec3* position_r = position;
    register const Vec3* offset_r = offset;
    register s32 object_id_r = object_id;
    register Effect* effect_r = effect;
    register s32 owner_r = owner;
    register s32 play_sound_r = play_sound;
    short type;
    s32 effect_value;
    s32 value;
    Vec3 direction;

    direction = lbl_80238D64;
    fn_801D38BC(object_id_r, &value, &type);

    if (offset_r != 0) {
        s32 value_copy;

        direction = *offset_r;
        fn_80211A90(&direction, &direction, lbl_8064E138);
        fn_80211A48(&direction, position_r, &direction);
        value_copy = value;
        fn_80152530(position_r, type, owner_r, 4, &value_copy, &direction);
    } else {
        s32 value_copy;

        value_copy = value;
        fn_80152530(position_r, type, owner_r, 4, &value_copy, 0);
        direction = *position_r;
    }

    type = fn_801D3A24(object_id_r, 0x31);
    fn_80152A88(position_r, &direction, type, 4);

    if (effect_r != 0) {
        effect_value = fn_801D39E0(object_id_r);
        effect_r->flags |= 2;
        fn_801E2B28(effect_r, position_r, &effect_value, 0x20, 0);
    }

    if (play_sound_r != 0) {
        fn_801AAE68(lbl_8064E034, 0x291, 100, 0, position_r, 2, 2, 0,
                    (u16)lbl_8064D18C, 0);
    }
}
