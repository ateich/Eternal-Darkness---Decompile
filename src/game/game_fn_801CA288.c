typedef unsigned char u8;
typedef unsigned int u32;

typedef struct AudioConfig {
    char pad00[0x210];
    u8 voices;
    u8 field211;
    u8 field212;
    u8 channels;
} AudioConfig;

typedef struct InitConfig {
    u32 value;
    char pad04[0xC];
} InitConfig;

extern AudioConfig lbl_80619C20;
extern u8 lbl_8064D3A0;
extern u8 lbl_8064D3D8;

extern int fn_801CC5D4(InitConfig*, u8, u8, u32);
extern void fn_801C38C0(void);
extern void fn_801BD294(int, u32);
extern void fn_801B58F0(void);
extern void fn_801B86C0(int, u8);
extern void fn_801B9350(void);
extern void fn_801C3158(void);
extern void fn_801CA240(u32);

int fn_801CA288(u8 voices, u8 field211, u8 field212, u8 channels, u32 flags,
                u32 value)
{
    u8 saved_voices;
    InitConfig init;
    int result;

    lbl_8064D3A0 = 0;
    if (voices <= 0x40) {
        lbl_80619C20.voices = voices;
    } else {
        lbl_80619C20.voices = 0x40;
    }
    if (channels <= 8) {
        lbl_80619C20.channels = channels;
    } else {
        lbl_80619C20.channels = 8;
    }
    lbl_80619C20.field211 = field211;
    lbl_80619C20.field212 = field212;
    init.value = 0x7D00;
    result = fn_801CC5D4(&init, lbl_80619C20.voices,
                         lbl_80619C20.channels, flags);
    if (result == 0) {
        saved_voices = lbl_80619C20.voices;
        fn_801C38C0();
        fn_801BD294(0, value);
        fn_801B58F0();
        lbl_8064D3D8 = 0;
        fn_801B86C0(0x7D00, saved_voices);
        fn_801B9350();
        fn_801C3158();
        fn_801CA240(flags);
        lbl_8064D3A0 = 1;
        result = 0;
    }
    return result;
}
