typedef unsigned char u8;

typedef struct Entry {
    u8 active;
    u8 remainder[131];
} Entry;

extern Entry lbl_8060B430[];
extern void fn_801ADC08(void);
extern void fn_801ADBC0(void);

int fn_801AE2F4(void)
{
    int count = 0;
    Entry* entry;
    int i;

    fn_801ADC08();
    for (i = 0, entry = lbl_8060B430; i < 3; i++, entry++) {
        if (entry->active == 0) {
            count++;
        }
    }
    fn_801ADBC0();
    return count;
}
