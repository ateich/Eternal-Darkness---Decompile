typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef unsigned long size_t;

typedef struct Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

typedef struct Record {
    u8 pad_0[8];
    s32 width;
    s32 height;
    float scale;
    u8 pad_14[4];
    Color first_color;
    Color second_color;
    u8 pad_20[4];
} Record;

typedef struct State {
    u8 pad_0[0x28];
    s8 first_count;
    s8 second_count;
    s8 third_count;
    u8 pad_2B;
    Record records[11];
} State;

extern void* memset(void* destination, int value, size_t size);
extern const float lbl_8064E054;
extern const float lbl_8064E064;
extern const float lbl_8064E074;
extern const float lbl_8064E1E8;

void fn_80032CB0(State* state)
{
    s32 offset;

    memset(state->records, 0, sizeof(state->records));
    state->first_count = 3;
    state->second_count = 3;
    state->third_count = 5;
    offset = state->first_count + state->second_count;

    state->records[0].width = 12;
    state->records[0].height = 12;
    state->records[0].scale = lbl_8064E074;
    state->records[0].first_color = (Color){100, 150, 250, 200};
    state->records[0].second_color = (Color){100, 150, 250, 200};

    state->records[1].width = 20;
    state->records[1].height = 14;
    state->records[1].scale = lbl_8064E054;
    state->records[1].first_color = (Color){150, 150, 150, 45};
    state->records[1].second_color = (Color){150, 150, 150, 45};

    state->records[2].width = 32;
    state->records[2].height = 14;
    state->records[2].scale = lbl_8064E1E8;
    state->records[2].first_color = (Color){150, 150, 150, 45};
    state->records[2].second_color = (Color){150, 150, 150, 45};

    state->records[3].width = 48;
    state->records[3].height = 13;
    state->records[3].scale = lbl_8064E1E8;
    state->records[3].first_color = (Color){220, 220, 220, 250};
    state->records[3].second_color = (Color){220, 220, 220, 250};

    state->records[4].width = 48;
    state->records[4].height = 12;
    state->records[4].scale = lbl_8064E054;
    state->records[4].first_color = (Color){120, 120, 75, 127};
    state->records[4].second_color = (Color){120, 120, 75, 127};

    state->records[5].width = 81;
    state->records[5].height = 11;
    state->records[5].scale = lbl_8064E054;
    state->records[5].first_color = (Color){120, 120, 75, 85};
    state->records[5].second_color = (Color){120, 120, 75, 85};

    state->records[offset + 0].width = 48;
    state->records[offset + 0].height = 14;
    state->records[offset + 0].scale = lbl_8064E064;
    state->records[offset + 0].first_color = (Color){220, 65, 0, 40};
    state->records[offset + 0].second_color = (Color){220, 65, 0, 40};

    state->records[offset + 1].width = 96;
    state->records[offset + 1].height = 11;
    state->records[offset + 1].scale = lbl_8064E064;
    state->records[offset + 1].first_color = (Color){210, 40, 0, 60};
    state->records[offset + 1].second_color = (Color){210, 40, 0, 60};

    state->records[offset + 2].width = 72;
    state->records[offset + 2].height = 10;
    state->records[offset + 2].scale = lbl_8064E064;
    state->records[offset + 2].first_color = (Color){240, 200, 200, 60};
    state->records[offset + 2].second_color = (Color){240, 200, 200, 60};

    state->records[offset + 3].width = 16;
    state->records[offset + 3].height = 11;
    state->records[offset + 3].scale = lbl_8064E064;
    state->records[offset + 3].first_color = (Color){220, 220, 220, 110};
    state->records[offset + 3].second_color = (Color){220, 220, 220, 110};

    state->records[offset + 4].width = 144;
    state->records[offset + 4].height = 11;
    state->records[offset + 4].scale = lbl_8064E064;
    state->records[offset + 4].first_color = (Color){220, 220, 220, 0};
    state->records[offset + 4].second_color = (Color){220, 220, 220, 0};
}
