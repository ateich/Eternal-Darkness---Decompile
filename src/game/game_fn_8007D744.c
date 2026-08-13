typedef signed short s16;
typedef unsigned int u32;

extern void *lbl_8064C8EC;
extern unsigned char lbl_8031CBA0[];
extern char lbl_802448F8[];

extern u32 *fn_801E5D20(void *);
extern void fn_801E6228(void *, const char *, ...);

/* NonMatching: honest reconstruction of the time-display update path. */
void fn_8007D744(int event)
{
    int ticks;
    int minutes;
    int hours;
    u32 *flags;

    if (lbl_8064C8EC != 0 && event == 5) {
        flags = fn_801E5D20(lbl_8064C8EC);
        *flags |= 1;
        ticks = *(s16 *)(lbl_8031CBA0 + 0x14);
        if (ticks < 0) {
            ticks = 0;
        }
        hours = ticks / 3600;
        minutes = ticks / 60;
        fn_801E6228(lbl_8064C8EC, lbl_802448F8, hours,
                    minutes - (minutes / 60) * 60,
                    ticks - minutes * 60);
    }
}
