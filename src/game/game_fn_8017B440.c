typedef unsigned char u8;
typedef unsigned long long u64;

typedef struct GlobalState {
    u8 pad_00[0x28];
    int states[2];
    u64 values[2];
} GlobalState;

extern GlobalState lbl_8064A580;

u64 fn_8017B440(int index)
{
    if (lbl_8064A580.states[index] != 0) {
        return lbl_8064A580.values[index];
    }

    return 0;
}
