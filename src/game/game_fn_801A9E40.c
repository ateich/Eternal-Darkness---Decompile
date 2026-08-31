typedef unsigned char u8;

typedef struct Entry {
    u8 value;
    signed char delta;
    u8 target;
    u8 timer;
    unsigned short state;
    u8 pad[2];
} Entry;

extern Entry lbl_80607CB0[4];
extern void fn_801A9DCC(int index, u8 target, int time);

void fn_801A9E40(int amount)
{
    int value = 0;

    if (amount == 0) {
        lbl_80607CB0[1].timer = 0;
    } else {
        value = lbl_80607CB0[1].timer + amount;
        if (value < 0) {
            value = 0;
        }
        lbl_80607CB0[1].timer = (u8)value;
    }

    if (value != 0) {
        if (lbl_80607CB0[1].target != 75) {
            fn_801A9DCC(1, 75, 10);
        }
    } else if (lbl_80607CB0[1].target != 100) {
        fn_801A9DCC(1, 100, 10);
    }
}
