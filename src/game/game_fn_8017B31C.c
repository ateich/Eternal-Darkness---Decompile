typedef unsigned char u8;

typedef struct GlobalState {
    u8 pad_00[0x44];
    int value;
} GlobalState;

extern GlobalState lbl_8064A580;

void fn_8017B31C(int value)
{
    lbl_8064A580.value = value;
}
