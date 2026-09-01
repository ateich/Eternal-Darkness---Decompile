typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry Entry;
struct Entry {
    u8 state;
    u8 padding01[3];
    u32 id;
    Entry* first;
    Entry* second;
    u8 padding10[116];
};

extern Entry lbl_8060B430[];
extern void fn_801ADC08(void);
extern void fn_801ADBC0(void);
extern void fn_801AE1D0(u32, int);
extern int fn_801B0C08(u32);
extern void fn_801B0E68(int);

void fn_801AEF3C(void)
{
    int i;
    Entry* entry = lbl_8060B430;

    fn_801ADC08();
    for (i = 0; i < 3; i++, entry++) {
        if (entry->state != 0 && fn_801B0C08(entry->id) == -1 &&
            (entry->first == 0 || fn_801B0C08(entry->first->id) == -1) &&
            (entry->second == 0 || fn_801B0C08(entry->second->id) == -1)) {
            fn_801B0E68(101);
            fn_801AE1D0(entry->id, 1);
            fn_801B0E68(102);
        }
    }
    fn_801ADBC0();
}
