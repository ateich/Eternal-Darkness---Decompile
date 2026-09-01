typedef unsigned char u8;

typedef struct Entry {
    struct Entry* previous;
    struct Entry* next;
    u8 pad008[8];
    int value;
    u8 pad014[4];
    u8 callback[1];
} Entry;

extern u8 lbl_8060BF60[];
extern unsigned int lbl_8064D324;
extern int lbl_8064D334;
extern int lbl_8064D338;
extern int lbl_8064D33C;
extern Entry* lbl_8064D344;
extern Entry* lbl_8064D348;

extern void fn_801B1070(void);
extern void fn_801B10A4(Entry*, unsigned int);
extern void fn_801B1194(void);
extern void fn_801B10EC(void);
extern void fn_802159A8(void*, void (*)(void));

void fn_801B1204(int value)
{
    lbl_8064D334 = value;
    if (lbl_8064D324 != 0) {
        lbl_8064D324 = 0;
        fn_801B10A4(lbl_8064D348, 0x10);
        lbl_8064D33C = 3;
        switch (lbl_8064D338) {
        case 0:
            if (lbl_8064D348 != 0) {
                Entry* entry = lbl_8064D348->next;
                if (entry != 0) {
                    lbl_8064D348 = entry;
                    entry->value = 0;
                    fn_801B1070();
                    fn_801B1194();
                } else {
                    entry = lbl_8064D344;
                    lbl_8064D348 = entry;
                    entry->value = 0;
                    fn_801B1070();
                    lbl_8064D33C = 0;
                }
            }
            break;
        case 1:
            if (lbl_8064D348 != 0) {
                Entry* entry = lbl_8064D348->next;
                if (entry != 0) {
                    lbl_8064D348 = entry;
                    entry->value = 0;
                    fn_801B1070();
                    fn_801B1194();
                } else {
                    entry = lbl_8064D344;
                    lbl_8064D348 = entry;
                    entry->value = 0;
                    fn_801B1070();
                    fn_801B1194();
                }
            }
            break;
        case 2:
            if (lbl_8064D348 != 0) {
                lbl_8064D348->value = 0;
                fn_801B1070();
                fn_801B1194();
            }
            break;
        }
    } else {
        fn_802159A8(lbl_8060BF60, fn_801B10EC);
    }
}
