typedef unsigned char u8;

typedef struct GlobalState {
    u8 pad_00[0x28];
    int states[2];
} GlobalState;

extern GlobalState lbl_8064A580;

void fn_8017B344(int index, int value)
{
    lbl_8064A580.states[index] = value;
}
