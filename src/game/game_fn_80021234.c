typedef signed short s16;
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef u32* Color;

#pragma use_lmw_stmw on

typedef struct Rect {
    s16 left;
    s16 top;
    s16 right;
    s16 bottom;
} Rect;

typedef struct RectPair {
    Rect value[2];
} RectPair;

typedef struct RectTriplet {
    RectPair first;
    RectPair third;
    RectPair second;
} RectTriplet;

typedef struct RuntimeState {
    u8 pad_00[0x10];
    void* draw_context;
    s32 menu_state;
} RuntimeState;

typedef struct PairSource {
    u8 pad_00[0xC];
    u32 color;
} PairSource;

extern u8 lbl_802515D0[];
extern u8 lbl_8023D020[];
extern PairSource lbl_802FC5BC;
extern RuntimeState lbl_8030241C;
extern u32 lbl_8064C2A8;
extern u8 lbl_8064B2C4;

extern void fn_801A91D4(s32, s32, s32);
extern void fn_801A90BC(void*, void*);
extern void fn_801E3AA4(s32);
extern void fn_801E5AD0(s32);
extern void fn_801E3A34(u32*);
extern void fn_801ED3F4(void*);
extern s32 fn_800AF7E4(s32, s32*);
extern void fn_801A85D4(u32*, s32, s32, u32);
extern void fn_801A852C(Color, int, int, u32);
extern void fn_801A8F08(s16, s16, s16, s16, s32, s32, s32);
extern void fn_801A8EDC(void*);
extern s32 fn_800B193C(void);
extern void fn_800B2EC0(s32);

#pragma section ".rodata"
#pragma force_active on
__declspec(section ".rodata") const u32 lbl_80238B20 = 0;
#pragma force_active reset

void fn_80021234(s32 selection)
{
    RectPair first = {{{0x6B, 0x49, 0xDE, 0xCF},
                       {0x1A7, 0x49, 0x219, 0xCF}}};
    RectPair second = {{{0x60, 0xE5, 0xEF, 0x112},
                        {0x19E, 0xE6, 0x228, 0x111}}};
    u32 draw_color = lbl_8064C2A8;
    s32 status;
    u32 setup_color;
    u32 first_color;
    u32 second_color;
    u32 final_color;
    s32 result;
    s32 i;

    ((u8*)&draw_color)[3] = selection;
    fn_801A91D4(0x15, selection, 1);
    fn_801A90BC(lbl_802515D0, lbl_8023D020);
    fn_801E3AA4(0);
    fn_801E5AD0(0x6C);
    setup_color = lbl_802FC5BC.color;
    fn_801E3A34(&setup_color);
    fn_801ED3F4(lbl_8030241C.draw_context);

    for (i = 0; i < 2; i++) {
        result = fn_800AF7E4(i, &status);
        if (result == 1 || (result != 1 && status != -3)) {
            first_color = draw_color;
            fn_801A85D4(&first_color, 0x16, 0x43, 0x80000000);
            fn_801A8F08(first.value[i].left, first.value[i].top,
                        first.value[i].right, first.value[i].bottom,
                        -1, 0, 5);
        }
        if (result != 1) {
            second_color = draw_color;
            fn_801A852C(&second_color, 0, (s16)(i + 0x49), 0x80000000);
            fn_801A8F08(second.value[i].left, second.value[i].top,
                        second.value[i].right, second.value[i].bottom,
                        -1, 0, 5);
        }
    }

    fn_801ED3F4(lbl_8030241C.draw_context);
    fn_801A8EDC(lbl_802515D0);

    if (lbl_8030241C.menu_state == 0xFF && fn_800B193C() == 0) {
        if (lbl_8064B2C4 != 0) {
            lbl_8064B2C4--;
        }
    } else {
        lbl_8064B2C4 = 2;
    }

    if (lbl_8064B2C4 == 0) {
        final_color = draw_color;
        fn_801A852C(&final_color, 0, 0x17, 0x80000000);
        fn_801A8F08(0xC0, 0x16A, 0x1CA, 0x19A, -1, 0, 5);
    }

    if (fn_800B193C() != 0) {
        fn_800B2EC0(selection);
    }
}

#pragma section ".rodata"
#pragma force_active on
__declspec(section ".rodata") const RectTriplet lbl_80238B44 = {
    {{{0x41, 0x73, 0x5F, 0x6C}, {0xBA, 0x73, 0x5F, 0x6C}}},
    {{{0x39, 0x6A, 0x70, 0x7F}, {0xB1, 0x6A, 0x6F, 0x7F}}},
    {{{0x47, 0x4A, 0x9F, 0x67}, {0xC2, 0x4C, 0x111, 0x65}}}
};
#pragma force_active reset
