typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

typedef struct SoundRequest {
    void* object;
    u32 value;
    u8 volume;
    u8 scale;
    u8 divisor;
    u8 mode;
    u16 parameter;
    u32 flags;
    u16 sound;
} SoundRequest;

extern u16 fn_8004A608(void*, u16, u8*, u8*, u16*, u32*);
extern void fn_801B0CA4(s32, u16);
extern s32 fn_800A1060(void);
extern void fn_801B05E8(s32, u8, s32, s32, s32, s32, s32, s32);
extern void* fn_8011F130(void*);
extern void fn_801AAE68(u16, u8, s32, f32, void*, s32, u8, s32, u16, s32);
extern void fn_80201A84(void*);
extern void* fn_80201814(void);
extern void fn_80204028(void*, u16, s32, SoundRequest*);
extern u8 fn_80205630(void);
extern s32 fn_8005099C(void);
extern s32 fn_80050950(void);
extern u16 fn_80050B08(s32, s32, s32, u8*, s32, s32, s32);
extern s32 fn_801AA388(s32);
extern s32 fn_80052228(void);
extern s32 fn_800522A4(void);
extern u16 fn_80052250(void);
extern s32 fn_8005227C(void);
extern s32 fn_800FBFB0(void);
extern void fn_801ACACC(u16, u8, s32, short);

extern u32 lbl_8064D18C;
extern void* lbl_8064C4E4;
extern f32 lbl_80650E50;

s32 fn_801A9FA4(void* object, u32 value)
{
    u8 scale = (value & 0xFF000000) >> 24;
    u16 sound;
    register void* owner = object;
    u16 packed = value;
    u8 divisor = (value & 0x00FF0000) >> 16;
    u8 volume;
    u8 mode;
    u16 parameter;
    u32 flags;
    void* position;
    s32 adjusted;
    SoundRequest request;

    sound = fn_8004A608(owner, packed, &volume, &mode, &parameter, &flags);

    if (scale != 0 && divisor != 0) {
        s32 converted = (s32)(((f32)scale / (f32)divisor) * (f32)volume);
        u8 adjusted;
        if ((u8)converted != 0) {
            adjusted = (u8)converted;
        } else {
            adjusted = 0;
        }
        if (adjusted > 100) {
            adjusted = 100;
        } else {
            if ((u8)converted != 0) {
                adjusted = (u8)converted;
            } else {
                adjusted = 0;
            }
        }
        volume = adjusted;
    }

    if (flags & 0x10) {
        fn_801B0CA4(-1, sound);
        goto done;
    }

    if (flags & 8) {
        s32 type;
        s32 index = (u16)sound;
        if (index == 28) {
            type = fn_800A1060() ? 4 : 6;
        } else if (index >= 91 && index < 95) {
            type = 4;
        } else {
            type = 2;
        }
        fn_801B05E8(index, volume, type, 1, 0, 5, 0, 0);
        goto done;
    }

    if (sound != 0xFFFF && volume != 0) {
        position = fn_8011F130(owner);
        fn_801AAE68(sound, volume, 0, lbl_80650E50, position, 2, mode, 0,
                    (u16)lbl_8064D18C, (flags & 0x40) ? 0x40 : 0);

        fn_80201A84(owner);
        {
            void* queue = fn_80201814();
            if (queue != 0) {
                request.object = owner;
                request.value = packed;
                request.volume = volume;
                request.scale = scale;
                request.divisor = divisor;
                request.mode = mode;
                request.parameter = parameter;
                request.flags = flags;
                request.sound = sound;
                fn_80204028(queue, parameter, 0, &request);
            }
        }

        if (owner == lbl_8064C4E4 && (flags & 1) && (flags & 2) && fn_80205630()) {
            s32 first = fn_8005099C();
            s32 second = fn_80050950();
            if (fn_80050B08(first, second, 77, &volume, 0, 0, 0) == 0xFFFF) {
                goto done;
            }
            fn_801AAE68(sound, volume, 0, lbl_80650E50, position, 2, mode, 0,
                        (u16)lbl_8064D18C, 0);
            goto done;
        }

        if ((flags & 0x20) && owner == lbl_8064C4E4) {
            fn_801AA388(1);
            if (fn_80052228() && !fn_800522A4()) {
                sound = fn_80052250();
                adjusted = volume + 30;
                if (adjusted > 127) {
                    adjusted = 127;
                }
                volume = (u8)adjusted;
                fn_801AAE68(sound, volume, 0, lbl_80650E50, position, 2, mode, 0,
                            (u16)lbl_8064D18C, 0);
            }
            if (fn_8005227C()) {
                adjusted = volume + 15;
                if (adjusted > 127) {
                    adjusted = 127;
                }
                volume = (u8)adjusted;
                fn_801ACACC(sound, volume, 0, (short)((fn_800FBFB0() & 15) + 120));
            }
        }
    }
done:
    return 1;
}
