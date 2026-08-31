typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

typedef struct Entry {
    u8 value;
    s8 delta;
    u8 target;
    u8 timer;
    u16 state;
    u8 pad[2];
} Entry;

extern Entry lbl_80607CB0[4];
extern void fn_801AD8B4(void);

void fn_801A9DCC(int index, u8 target, int time)
{
    int delta;

    if (time != 0) {
        delta = (target - lbl_80607CB0[index].value) / time;
    } else {
        delta = 0;
    }
    lbl_80607CB0[index].target = target;
    lbl_80607CB0[index].delta = (s8)delta;
    if (delta == 0) {
        lbl_80607CB0[index].value = target;
        fn_801AD8B4();
    }
}
