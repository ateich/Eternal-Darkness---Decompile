typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Effect {
    u8 pad0[0x50];
    Vec3 position;
    u8 pad1[0x1C];
    float scale;
    u8 pad_value[4];
    u32 value80;
    u16 value84;
    u16 value86;
    u8 value88;
    u8 value89;
    u8 pad2[3];
    u8 value8D;
    u8 pad3;
    s8 active;
    u8 pad4[2];
    s8 detailed;
    u8 pad5;
    u8 value94;
} Effect;

extern u8 lbl_802FC5BC[];
extern char lbl_8025167C[];
extern char lbl_802516E8[];
extern void fn_800EBA80(int, Vec3*, u32*, int, float);
extern void fn_800ED4BC(Vec3*, int, const char*, int, u16, u8, u16, u32,
                        float, ...);

void fn_801AC194(Effect* effect, int index)
{
    Vec3* position;
    int mode;
    u32 color;

    position = &effect->position;
    if (effect->active == 1) {
        if (effect->detailed != 0) {
            mode = 8;
        } else {
            mode = 9;
        }
    } else if (effect->active == 2) {
        mode = 12;
    } else {
        mode = 6;
    }

    color = ((u32*)lbl_802FC5BC)[mode];
    fn_800EBA80(1, position, &color, 0x40, effect->scale);
    if (effect->detailed != 0) {
        fn_800ED4BC(position, mode, lbl_8025167C, index, effect->value86,
                    effect->value89, effect->value84, effect->value80,
                    effect->scale, effect->value8D, effect->value88,
                    effect->value94);
    } else {
        fn_800ED4BC(position, mode, lbl_802516E8, index, effect->value86,
                    effect->value89, effect->value84, effect->value80,
                    effect->scale, effect->value88, effect->value94);
    }
}
