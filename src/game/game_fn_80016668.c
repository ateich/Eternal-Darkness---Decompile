typedef int s32;
typedef signed short s16;
typedef unsigned char u8;

typedef struct GameData {
    u8 pad_000[0x1D4];
    s16 value_1D4;
} GameData;

extern GameData lbl_8030F540;
extern s32 lbl_8064D1BC;
extern const char lbl_8023BEF8[];
extern const char lbl_8023CB70[];
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80052424(s32, s32, s32, s32);

s32 fn_80016668(void* script)
{
    s32 value;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    value = (s32)fn_8016A694(script, 1);
    if (value < 0) {
        fn_80163BB4(script, lbl_8023CB70, value);
    }
    fn_80052424(value, -1, 0, 0);
    lbl_8030F540.value_1D4 = lbl_8064D1BC;
    return 0;
}
