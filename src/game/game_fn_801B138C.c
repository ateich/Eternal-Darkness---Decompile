typedef unsigned char u8;

typedef struct Entry {
    struct Entry* previous;
    struct Entry* next;
    u8 pad008[0x10];
    u8 callback[1];
} Entry;

extern void (*lbl_8064D320)(void);
extern int lbl_8064D328;
extern int lbl_8064D33C;
extern Entry* lbl_8064D340;
extern Entry* lbl_8064D344;
extern Entry* lbl_8064D348;

extern void fn_8021345C(void*);
extern void fn_8021A1A8(int);

void fn_801B138C(void)
{
    Entry* entry;

    fn_8021A1A8(0);
    entry = lbl_8064D344;
    while (entry != 0) {
        fn_8021345C(entry->callback);
        entry = entry->next;
    }
    lbl_8064D344 = 0;
    lbl_8064D340 = 0;
    lbl_8064D348 = 0;
    lbl_8064D33C = 0;
    if (lbl_8064D320 != 0) {
        lbl_8064D320();
        lbl_8064D320 = 0;
    }
    lbl_8064D33C = 0;
    lbl_8064D328 = 0;
}
