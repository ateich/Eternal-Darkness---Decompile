typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

typedef union InitialValue {
    u32 value;
    struct {
        u8 unk_00;
        u8 unk_01;
        u8 unk_02;
        u8 unk_03;
    } byte;
} InitialValue;

typedef struct RectState {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    s16 unk_12;
    s16 unk_14;
    s16 unk_16;
} RectState;

typedef struct DisplayBody {
    RectState rects[2];
    Color colors_a[2][4];
    Color colors_b[2][4];
    u8 unk_78[0x78];
} DisplayBody;

typedef struct DisplayState {
    InitialValue first;
    u32 second;
    DisplayBody body;
    s16 unk_F0;
    s16 unk_F2;
    u8 unk_F4;
} DisplayState;

extern Color lbl_80651A94;
extern Color lbl_80651A98;

void fn_800CD384(void *state_arg, void *value_arg, void *unk_f0_arg,
                 void *unk_f4_arg)
{
    DisplayState *state = (DisplayState *)state_arg;
    DisplayBody *rect_body = &state->body;
    DisplayBody *color_body = rect_body;
    u32 *value = (u32 *)value_arg;
    Color color_a = lbl_80651A94;
    Color color_b = lbl_80651A98;
    int i;

    state->first.value = *value;
    state->first.byte.unk_03 = 0;
    state->second = *value;
    state->unk_F0 = (s16)(u32)unk_f0_arg;
    state->unk_F2 = 0;
    state->unk_F4 = (u8)(u32)unk_f4_arg;

    for (i = 0; i < 2; i++) {
        RectState *rect = &rect_body->rects[i];
        rect->unk_00 = 0;
        rect->unk_02 = 0;
        rect->unk_04 = -1;
        rect->unk_06 = 0x280;
        rect->unk_08 = 0;
        rect->unk_0A = -1;
        rect->unk_0C = 0x280;
        rect->unk_0E = 0x1E0;
        rect->unk_10 = -1;
        rect->unk_12 = 0;
        rect->unk_14 = 0x1E0;
        rect->unk_16 = -1;

        color_body->colors_a[i][0] = color_body->colors_a[i][1] =
            color_body->colors_a[i][2] = color_body->colors_a[i][3] = color_a;
        color_body->colors_b[i][0] = color_body->colors_b[i][1] =
            color_body->colors_b[i][2] = color_body->colors_b[i][3] = color_b;
    }
}
