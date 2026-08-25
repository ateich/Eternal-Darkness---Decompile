typedef unsigned char u8;
typedef unsigned long long u64;

typedef struct GlobalState {
    u8 pad_00[0x28];
    int states[2];
    u64 values[2];
} GlobalState;

extern GlobalState lbl_8064A580;
extern u64 fn_8017B35C(int);

void fn_8017B3C8(int index)
{
    if (lbl_8064A580.states[index] != 0) {
        lbl_8064A580.values[index] = fn_8017B35C(index);
    } else {
        lbl_8064A580.values[index] = 0;
    }
}
