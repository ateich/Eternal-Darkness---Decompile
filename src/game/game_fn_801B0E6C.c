typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    u8 pad000[0x144];
    u32 field144;
    u8 pad148[0x18];
    int field160;
    u8 pad164[4];
    int field168;
    int field16C;
    u8 pad170[4];
    u16 flags174;
    u8 pad176[4];
    u8 state17A;
    u8 pad17B[6];
    u8 field181;
    u8 pad182[2];
} Entry;

extern Entry lbl_8060B5E0[];
extern int lbl_8064D5A8;
extern int fn_801B0B64(Entry*, int);
extern void fn_801B0E68(int);
extern void fn_801AE1D0(u32, int);
extern int fn_801AEAE0(u32);
extern void fn_801AEF3C(void);

void fn_801B0E6C(void)
{
    int i;
    Entry* entry = lbl_8060B5E0;

    for (i = 0; i < 4; i++, entry++) {
        int value = fn_801B0B64(entry, 0);
        if ((entry->state17A == 2 || entry->state17A == 1) && value != -1) {
            if (value == entry->field160) {
                if (entry->flags174 & 1) {
                    fn_801B0E68(8);
                    fn_801AE1D0(entry->field144, 1);
                    entry->field181 = 8;
                } else {
                    entry->flags174 |= 1;
                }
            } else {
                entry->field160 = value;
                entry->flags174 &= ~1;
            }
        }
        if (entry->state17A == 3 && entry->field168 != 0 && lbl_8064D5A8 > entry->field168 + 120) {
            fn_801B0E68(9);
        }
        if (entry->field16C != 0 && lbl_8064D5A8 > entry->field16C + 120) {
            u8 state = entry->state17A;
            if (state == 3 || (u8)(state - 4) <= 1 || state == 6) {
                fn_801B0E68(10);
            }
        }
        if (entry->state17A != 0 && entry->field144 != -1 && (u8)fn_801AEAE0(entry->field144) == 0) {
            int report = 1;
            if (entry->state17A == 1 && !(entry->flags174 & 4)) {
                report = 0;
                entry->flags174 |= 4;
            }
            if (report != 0) {
                fn_801B0E68(11);
            }
        }
    }
    fn_801AEF3C();
}
