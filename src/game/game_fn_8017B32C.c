typedef unsigned char u8;

typedef struct GlobalState {
    u8 pad_00[0x28];
    int states[2];
} GlobalState;

extern GlobalState lbl_8064A580;

int fn_8017B32C(int value)
{
    return lbl_8064A580.states[value];
}
