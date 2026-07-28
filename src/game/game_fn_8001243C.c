typedef int s32;
typedef signed short s16;
typedef unsigned char u8;

typedef struct GameData {
    u8 pad_000[0x1D0];
    s16 value_1D0;
    u8 pad_1D2[8];
    u8 value_1DA;
} GameData;

extern GameData lbl_8030F540;
extern s32 lbl_8064CDC8;
extern s32 lbl_8064C5A4;
extern const char lbl_8023CA4C[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, ...);

s32 fn_8001243C(void* script)
{
    void* parser;

    parser = script;
    lbl_8064CDC8 = 2;
    lbl_8030F540.value_1DA = 0;
    lbl_8030F540.value_1D0 = -1;

    switch (fn_8016A598(parser)) {
    case 3:
        lbl_8030F540.value_1DA = (s32)fn_8016A694(parser, 3);
    case 2:
        lbl_8064CDC8 = (s32)fn_8016A694(parser, 2);
    case 1:
        lbl_8064C5A4 = (s32)fn_8016A694(parser, 1);
        break;
    default:
        fn_80163BB4(parser, lbl_8023CA4C, fn_8016A598(parser));
        break;
    }
    return 0;
}
