typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Record {
    float x;
    float y;
    u8 pad_8[8];
    float radius;
    u8 pad_14[0x10];
} Record;

typedef struct State {
    u8 pad_0[0x28];
    s8 first_count;
    s8 second_count;
    s8 third_count;
    u8 pad_2B;
    Record records[1];
} State;

extern Vec3 lbl_8023E428;
extern const float lbl_8064E068;
extern float fn_80179A74(Vec3* vector);
extern void fn_80179A18(Vec3* vector);
extern s32 fn_80026118(State* state);

void fn_80032E90(State* state, const Vec3* point)
{
    Vec3* origin = (Vec3*)((u8*)&lbl_8023E428 + ((u8*)state - (u8*)state));
    Vec3 direction;
    float distance;
    State* cursor;
    s32 third_index;
    s32 second_index;
    s32 first_index;
    float x;
    float y;

    direction.x = point->x - origin->x;
    direction.y = point->y - origin->y;
    direction.z = lbl_8064E068;
    distance = fn_80179A74(&direction);
    fn_80179A18(&direction);

    cursor = state;
    for (first_index = 0; first_index < (second_index = state->first_count); first_index++, cursor = (State*)((u8*)cursor + 0x24)) {
        float scale = distance * cursor->records[0].radius;
        cursor->records[0].x = direction.x * scale + lbl_8023E428.x;
        cursor->records[0].y = direction.y * scale + origin->y;
    }

    cursor = (State*)((u8*)state + second_index * 0x24);
    for (; second_index < (third_index = state->second_count + state->first_count); second_index++) {
        float scale = distance * cursor->records[0].radius;
        cursor->records[0].x = -direction.x * scale + lbl_8023E428.x;
        cursor->records[0].y = -direction.y * scale + origin->y;
        cursor = (State*)((u8*)cursor + 0x24);
    }

    x = direction.x * distance + lbl_8023E428.x;
    y = direction.y * distance + origin->y;
    cursor = (State*)((u8*)state + third_index * 0x24);
    for (; third_index < state->third_count + (state->second_count + state->first_count); third_index++) {
        cursor->records[0].x = x;
        cursor->records[0].y = y;
        cursor = (State*)((u8*)cursor + 0x24);
    }

    fn_80026118(state);
}
