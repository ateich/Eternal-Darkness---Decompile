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

typedef struct UiConstants {
    u8 pad_000[0x1CC];
    RectTriplet rectangles;
} UiConstants;

typedef struct RuntimeState {
    u8 pad_00[0x14];
    s32 menu_state;
    u8 pad_18[0x28];
    u8 selection;
} RuntimeState;

extern u8 lbl_802515D0[];
extern u8 lbl_8023D020[];
extern UiConstants lbl_80238978;
extern RuntimeState lbl_8030241C;
extern u32 lbl_8064C2A8;
extern u32 lbl_8064C2C4;
extern float lbl_8064DEE0;
extern float lbl_8064DEC0;

extern void fn_801A9250(s32, s32, s32);
extern void fn_801A90BC(void*, void*);
extern s32 fn_800AF7E4(s32, s32*);
extern void fn_801A85D4(u32*, s32, s32, u32);
extern void fn_801A852C(Color, int, int, u32);
extern void fn_801A8F08(s16, s16, s16, s16, s32, s32, s32);
extern void fn_801A872C(s32, s32, s32, s32, s32, s32, u32*);
extern s32 fn_800B7EC0(void);
extern s32 fn_800B194C(void);
extern void fn_801ED5F4(s32, s32, s32, s32, s32, float);
extern void fn_801A8D38(int);
extern void fn_800B2EC0(s32);

extern const RectTriplet lbl_80238B44;

void fn_80021490(s32 selection)
{
    RectTriplet* rectangles;
    u32 draw_color;
    RectPair first;
    RectPair third;
    RectPair second;
    s32 status;
    s32 result;
    u32 first_color;
    u32 second_color;
    s32 i;

    rectangles = &lbl_80238978.rectangles;
    draw_color = lbl_8064C2A8;
    first = rectangles->first;
    third = rectangles->third;
    second = rectangles->second;

    fn_801A9250(3, selection, 1);
    fn_801A90BC(lbl_802515D0, lbl_8023D020);
    ((u8*)&draw_color)[3] = selection;

    for (i = 0; i < 2; i++) {
        result = fn_800AF7E4(i, &status);
        if (result == 1 || (result != 1 && status != -3)) {
            first_color = draw_color;
            fn_801A85D4(&first_color, 0x41, 0x42, 0x80000000);
            fn_801A8F08(first.value[i].left, first.value[i].top,
                        first.value[i].right + first.value[i].left,
                        first.value[i].bottom + first.value[i].top,
                        -1, 0, 5);
        }
        if (result != 1) {
            second_color = draw_color;
            fn_801A852C(&second_color, 0, (s16)(i + 0x4B), 0x80000000);
            fn_801A8F08(second.value[i].left, second.value[i].top,
                        second.value[i].right, second.value[i].bottom,
                        -1, 0, 5);
        }

        if (lbl_8030241C.menu_state == 0xFF && fn_800B7EC0() == i) {
            switch (fn_800B194C()) {
            case 1: {
                volatile u32 prompt_color;
                u32 prompt_color_value;
                volatile Rect* prompt_rect;
                s16 prompt_left;
                s16 prompt_top;
                s16 prompt_right;
                s16 prompt_bottom;
                fn_801ED5F4(1, 0x502, 1, 0, 0, lbl_8064DEE0);
                prompt_color_value = lbl_8064C2C4;
                prompt_rect = &third.value[i];
                prompt_left = prompt_rect->left;
                prompt_top = prompt_rect->top;
                prompt_right = prompt_rect->right;
                prompt_bottom = prompt_rect->bottom;
                prompt_color = prompt_color_value;
                fn_801A872C(prompt_left, prompt_top, prompt_right,
                            prompt_bottom, -1, 6, (u32*)&prompt_color);
                fn_801ED5F4(0, 2, 1, 0, 0, lbl_8064DEC0);
                fn_801A8D38(5);
                break;
            }
            default: {
                volatile u32 prompt_color;
                u32 prompt_color_value = lbl_8064C2C4;
                volatile Rect* prompt_rect = &third.value[i];
                s16 prompt_left = prompt_rect->left;
                s16 prompt_top = prompt_rect->top;
                s16 prompt_right = prompt_rect->right;
                s16 prompt_bottom = prompt_rect->bottom;
                prompt_color = prompt_color_value;
                fn_801A872C(prompt_left, prompt_top, prompt_right,
                            prompt_bottom, -1, 6, (u32*)&prompt_color);
                break;
            }
            }
        }
    }

    if (lbl_8030241C.menu_state == 0xFF) {
        fn_800B2EC0(lbl_8030241C.selection);
    }
}
