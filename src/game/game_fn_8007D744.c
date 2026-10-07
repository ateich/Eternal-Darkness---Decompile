typedef signed short s16;
typedef unsigned int u32;
typedef struct TextDescriptor TextDescriptor;

extern void *lbl_8064C8EC;
extern unsigned char lbl_8031CBA0[];
extern char lbl_802448F8[];

extern void *fn_801E5D20(void *);
extern void fn_801E6228(TextDescriptor *, const char *, ...);

/* Update the elapsed-time display for event 5. */
void fn_8007D744(int event)
{
    int ticks;
    u32 *flags;

    if (lbl_8064C8EC == 0) {
        return;
    }
    switch (event) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        flags = fn_801E5D20(lbl_8064C8EC);
        ticks = *(s16 *)(lbl_8031CBA0 + 0x14);
        ticks = 0 > ticks ? 0 : ticks;
        *flags |= 1;
        fn_801E6228(lbl_8064C8EC, lbl_802448F8, ticks / 3600,
                    (ticks / 60) % 60, ticks % 60);
        break;
    case 6:
        break;
    default:
        break;
    }
}
