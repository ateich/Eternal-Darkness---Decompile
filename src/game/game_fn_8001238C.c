typedef int s32;

typedef struct GameState {
    void* value;
    unsigned char pad_04[4];
    s32 mode;
} GameState;

extern const char lbl_8023BEF8[];
extern s32 lbl_8023D5B8[];
extern GameState lbl_803003C8;
extern s32 lbl_8064D18C;
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80045A24(s32, s32);
extern void fn_80025A78(int);

s32 fn_8001238C(void* script)
{
    s32 value;
    void* parser;

    parser = script;
    if (fn_8016A598(parser) != 1) {
        fn_80163BB4(parser, lbl_8023BEF8, 1, fn_8016A598(parser));
        return 0;
    }

    value = (s32)fn_8016A694(parser, 1);
    lbl_8064D18C = lbl_8023D5B8[value];
    lbl_803003C8.mode = value;
    fn_80045A24(0, 0);
    fn_80025A78(9);
    return 0;
}
