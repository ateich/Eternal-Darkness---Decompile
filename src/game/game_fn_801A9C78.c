typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry {
    u8 value;
    u8 delta;
    u8 target;
    u8 timer;
    u16 state;
    u8 pad[2];
} Entry;

typedef struct State {
    Entry entry0;
    Entry entry1;
    Entry entry2;
    Entry entry3;
} State;

extern State lbl_80607CB0;

void fn_801A9C78(void)
{
    lbl_80607CB0.entry0.value = 100;
    lbl_80607CB0.entry0.target = 100;
    lbl_80607CB0.entry0.delta = 0;
    lbl_80607CB0.entry0.timer = 0;
    lbl_80607CB0.entry0.state = 0;
    lbl_80607CB0.entry1.value = 100;
    lbl_80607CB0.entry1.target = 100;
    lbl_80607CB0.entry1.delta = 0;
    lbl_80607CB0.entry1.timer = 0;
    lbl_80607CB0.entry1.state = 0;
    lbl_80607CB0.entry2.value = 100;
    lbl_80607CB0.entry2.target = 100;
    lbl_80607CB0.entry2.delta = 0;
    lbl_80607CB0.entry2.timer = 0;
    lbl_80607CB0.entry2.state = 0;
    lbl_80607CB0.entry3.value = 100;
    lbl_80607CB0.entry3.target = 100;
    lbl_80607CB0.entry3.delta = 0;
    lbl_80607CB0.entry3.timer = 0;
    lbl_80607CB0.entry3.state = 0;
}
