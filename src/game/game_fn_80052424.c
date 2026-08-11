typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

typedef struct GameState {
    u8 pad[8];
    s32 mode;
} GameState;

extern void* fn_80201ADC(void);
extern s32 fn_80201B64(void* object);
extern void fn_80045A24(s32 value, s32 flags);
extern void fn_801EFE84(s32 value);
extern void fn_8001DA0C(void);
extern void fn_8001D9FC(s32 mode);

extern GameState lbl_803003C8;
extern u8 lbl_8030F540[];
extern s32 lbl_8064C600;
extern s32 lbl_8064C5E8;

void fn_80052424(s32 type, s32 value, s32 flag, s32 options)
{
    void* object = fn_80201ADC();

    if (lbl_803003C8.mode == 13 || object == 0 || fn_80201B64(object) != 8) {
        if ((s8)lbl_8030F540[0x1DC] != 0) {
            options |= 1;
        }
        fn_80045A24(1, options);

        lbl_8030F540[0x1DA] = type;
        lbl_8030F540[0x1DD] = flag;
        *(s16*)(lbl_8030F540 + 0x1D0) = value;

        if ((u8)type != 0x53 && (u8)type != 0x54 && (u8)type != 0x55) {
            fn_801EFE84(1);
        } else {
            lbl_8064C600 = 10000;
        }

        if (lbl_8064C5E8 == 6) {
            fn_8001DA0C();
        }
        fn_8001D9FC(6);
    }
}
