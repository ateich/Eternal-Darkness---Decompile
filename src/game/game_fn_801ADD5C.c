typedef struct Entry {
    unsigned char active;
    unsigned char padding[91];
    unsigned int buffer;
    unsigned int size;
    unsigned int second_size;
    unsigned char remainder[28];
} Entry;

typedef struct State {
    Entry entries[3];
    unsigned int initialized;
    unsigned int interrupts;
    unsigned int interrupt_depth;
} State;

extern State lbl_8060B430;
extern int lbl_8064D308;
extern unsigned int lbl_8064D30C;
extern unsigned char lbl_802517F8[];
extern unsigned int fn_801FEA8C(unsigned int, unsigned int, void*, unsigned int);
extern void fn_801ADC50(void);

void fn_801ADD5C(void)
{
    unsigned int allocation;

    allocation = fn_801FEA8C(0x3C000, 1, lbl_802517F8, 0x13C);
    lbl_8064D30C = allocation;
    lbl_8064D308 = 0;

    lbl_8060B430.entries[0].active = 0;
    lbl_8060B430.entries[0].buffer = allocation;
    lbl_8060B430.entries[0].size = 0xB2C0;
    lbl_8060B430.entries[0].second_size = 0x138D0;

    lbl_8060B430.entries[1].active = 0;
    lbl_8060B430.entries[1].buffer = allocation + 0xB2C0;
    lbl_8060B430.entries[1].size = 0xB2C0;
    lbl_8060B430.entries[1].second_size = 0x138D0;

    lbl_8060B430.entries[2].active = 0;
    lbl_8060B430.entries[2].buffer = allocation + 0x16580;
    lbl_8060B430.entries[2].size = 0xB2C0;
    lbl_8060B430.entries[2].second_size = 0x138D0;

    fn_801ADC50();
    lbl_8060B430.initialized = 1;
    lbl_8060B430.interrupt_depth = 0;
}
