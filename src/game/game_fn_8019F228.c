typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_802FC5BC[];

typedef struct State {
    u8 field_00;
    u8 field_01;
    u8 field_02;
    signed char field_03;
    u16 field_04;
    u16 field_06;
    u16 field_08;
    u8 pad_0A[6];
    u32 field_10;
    u16 field_14;
    u16 field_16;
    u8 field_18;
} State;

void fn_8019F228(State* state)
{
    state->field_00 = 1;
    state->field_01 = 4;
    state->field_02 = 0xC0;
    state->field_03 = -16;
    state->field_04 = 0x3D;
    state->field_08 = 0x80;
    state->field_06 = 0x80;
    state->field_10 = *(u32*)(lbl_802FC5BC + 0x34);
    state->field_14 = 0x87;
    state->field_16 = 0x50;
    state->field_18 = 1;
}
