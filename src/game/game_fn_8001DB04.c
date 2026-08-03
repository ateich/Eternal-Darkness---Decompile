typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct LocalObject {
    u8 data[0x20];
} LocalObject;

typedef struct Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

extern Color lbl_8064DEB0;
extern Color lbl_8064DEB4;
extern float lbl_8064DEA8;
extern float lbl_8064DEB8;
extern float lbl_8064DEBC;
extern float lbl_8064DEC0;
extern u32 lbl_8064CBA0;
extern s32 lbl_8064CBA4;
extern void* lbl_8064D740;
extern void* lbl_8064D74C;
extern char lbl_8063BEC0[];
extern char lbl_802515D0[];
extern char lbl_802515E0[];

extern void* fn_8012070C(void);
extern void fn_80227290(Color, u32);
extern void fn_801F44B8(void*);
extern void fn_8022B94C(float, float, float, float, float, float);
extern void fn_8022B970(s32, s32, s32, s32);
extern void fn_8022A5D8(s32, s32, s32, s32);
extern void fn_80226D28(s32);
extern void fn_801F10BC(s32, s32, s32);
extern void fn_801F0044(void);
extern void fn_8022A6DC(s32);
extern void fn_8022A71C(s32);
extern void fn_80228020(s32);
extern void fn_8022806C(s32, s32, s32, s32, s32, s32, s32);
extern void fn_8022A75C(s32, s32, s32);
extern void fn_801EF530(void);
extern void fn_801EF580(void*);
extern void* fn_801EB080(void);
extern void fn_8022753C(void*, s32);
extern void fn_80226598(void);
extern void fn_802264D4(s32);
extern void fn_8020D250(void*, s32, s32);
extern void fn_801EFEC4(s32);
extern void fn_8015DB84(void*, LocalObject*, s32);
extern void fn_80228AFC(LocalObject*, s32);
extern void fn_801ECB40(u8);
extern void fn_80229D8C(s32, Color);
extern void fn_80229E74(s32, s32);
extern void fn_80225FE8(s32, s32, s32, s32, s32, s32);
extern void fn_80229C0C(s32, s32, s32, s32, s32, s32);
extern void fn_80229B08(s32, s32, s32, s32, s32);
extern void fn_80229B88(s32, s32, s32, s32, s32);
extern void fn_80229CCC(s32, s32, s32, s32, s32, s32);
extern void fn_802262B8(s32);
extern void fn_8022A2F4(s32);
extern void fn_801A8D38(s32);
extern void fn_801A8FE8(void*, void*, s32, s32, s32);

void fn_8001DB04(u32 mode)
{
    LocalObject object;
    s32 i;
    void* destination;
    u32 alpha = 0;
    Color color = lbl_8064DEB0;
    Color tint = lbl_8064DEB4;
    u32 channel;

    destination = fn_8012070C();
    channel = lbl_8064CBA0;

    tint.r = channel;
    tint.g = channel;
    tint.b = channel;
    fn_80227290(tint, 0xFFFFFF);
    fn_801F44B8(lbl_8064D740);
    fn_8022B94C(lbl_8064DEA8, lbl_8064DEA8, lbl_8064DEB8,
                lbl_8064DEBC, lbl_8064DEA8, lbl_8064DEC0);
    fn_8022B970(0, 0, 640, 480);
    fn_8022A5D8(1, 4, 5, 0);
    fn_80226D28(0);
    fn_801F10BC(0, 0, 0);
    fn_801F0044();
    fn_8022A6DC(1);
    fn_8022A71C(0);
    fn_80228020(1);
    fn_8022806C(4, 0, 0, 0, 0, 0, 2);
    fn_8022806C(5, 0, 0, 0, 0, 0, 2);
    fn_8022A75C(1, 3, 1);
    fn_8022A6DC(1);
    fn_8022A71C(1);

    for (i = 0; i < 2; i++) {
        void* value;
        fn_801EF530();
        fn_801EF580(lbl_8064D74C);
        value = fn_801EB080();
        fn_8022753C(value, 1);
        fn_80226598();
        fn_802264D4(0xBEEF);
        fn_8020D250(lbl_8063BEC0, 0, 1);
        fn_801EFEC4(1);
    }

    while ((s32)alpha < 255) {
        void* value;
        fn_801EF530();
        fn_801EF580(lbl_8064D74C);
        alpha += 5;
        if ((s32)alpha > 255) {
            alpha = 255;
        }
        color.a = alpha;
        fn_8015DB84(destination, &object, mode);
        fn_80228AFC(&object, 0);
        fn_801ECB40((u8)(lbl_8064CBA0 + 1));
        fn_801ECB40((u8)lbl_8064CBA0);
        fn_80229D8C(1, color);
        fn_80229E74(0, 13);
        fn_80225FE8(0, 1, 4, 60, 0, 125);
        fn_80229C0C(0, 0, 0, 0, 1, 0);
        fn_80229B08(0, 15, 12, 8, 14);
        fn_80229B88(0, 7, 7, 7, 1);
        fn_80229CCC(0, 0, 0, 0, 1, 0);
        fn_802262B8(1);
        fn_8022A2F4(1);
        fn_801A8D38(5);
        if ((s32)mode == 0 && lbl_8064CBA4 == 1) {
            fn_801A8FE8(lbl_802515D0, lbl_802515E0 + 0x30, 0, 0, 5);
        } else {
            fn_801A8FE8(lbl_802515D0, lbl_802515E0, 0, 0, 5);
        }
        value = fn_801EB080();
        fn_8022753C(value, 1);
        fn_80226598();
        fn_802264D4(0xBEEF);
        fn_8020D250(lbl_8063BEC0, 0, 1);
        fn_801EFEC4(1);
    }
}
