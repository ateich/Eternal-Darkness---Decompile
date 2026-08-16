typedef struct State {
    unsigned char pad[0x174];
    int value;
} State;

extern State *lbl_8064CC14;

int fn_800ED790(void)
{
    if (lbl_8064CC14 != 0) {
        return lbl_8064CC14->value;
    }
    return -1;
}
