typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

typedef struct GameState {
    u8 pad00[8];
    s32 mode;
} GameState;

extern GameState lbl_803003C8;
extern s32 lbl_8064C69C;
extern s32 lbl_8064C6A0;
extern void* lbl_8064C4E0;
extern void* lbl_8064D18C;
extern void* lbl_8064D68C;

extern void fn_8001E604(void);
extern void fn_80159440(void*, s32);
extern void fn_800BC74C(s32);
extern void fn_80042818(s32);
extern void fn_80052424(s32, s32, s32, s32);
extern s32 fn_80007D00(s32);
extern s32 fn_80007DA0(s32);
extern void fn_80042F7C(s32, s32);
extern void fn_80043034(s32);
extern int fn_801E79FC(void*, int);
extern void fn_800B0414(s32, s32, s32, s32, s32);
extern void fn_800452DC(s32);
extern void fn_8001D9FC(int);
extern void fn_80029358(void);
extern u8* fn_8015C28C(s32);
extern void fn_80046B0C(u8*);
extern void fn_800477F8(s32, s32);
extern void fn_801EBA58(void*);
extern void fn_801FCCF8(void);
extern void fn_801443F4(void);

void fn_80023ED4(void)
{
    s32 first;
    s32 second;
    u8* state;

    fn_8001E604();
    if (lbl_8064C6A0 != -1) {
        fn_80159440(lbl_8064D18C, 0);
        fn_800BC74C(1);
        fn_80042818(0);
        fn_80052424(lbl_8064C6A0, lbl_8064C69C, 0, 0);
        lbl_8064C6A0 = -1;
    } else {
        first = fn_80007D00(lbl_803003C8.mode);
        second = fn_80007DA0(lbl_803003C8.mode);
        fn_80042F7C(lbl_803003C8.mode, 1);
        fn_80043034(0);
        if (lbl_803003C8.mode != 15) {
            if (fn_801E79FC(lbl_8064C4E0, 0x313) != 0 && lbl_803003C8.mode != 13) {
                fn_80042818(12);
            } else {
                fn_80042818(lbl_803003C8.mode);
            }
            fn_800B0414(0, 1, 1, first, second);
            fn_800452DC(lbl_803003C8.mode);
        }
        fn_8001D9FC(2);
    }

    fn_80029358();
    state = fn_8015C28C(2);
    if ((s8)state[0x8143] != 0 && (s8)state[0x8142] != 0) {
        fn_80046B0C(state);
    }
    fn_800477F8(1, 0);
    fn_801EBA58(lbl_8064D68C);
    fn_801FCCF8();
    fn_801443F4();
}
