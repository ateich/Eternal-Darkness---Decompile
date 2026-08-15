extern char jumptable_80246E60[];
extern char lbl_8064B6C0;
extern void fn_800F9D4C(void *, const char *, ...);

#pragma force_active on
char lbl_802477B4[0x84] =
    "2000 A.D.\0\0\0"
    "1150 A.D.\0\0\0"
    "814 A.D.\0\0\0\0"
    "565 A.D.\0\0\0\0"
    "1760 A.D.\0\0\0"
    "1983 A.D.\0\0\0"
    "1485 A.D.\0\0\0"
    "1460 A.D.\0\0\0"
    "1916 A.D.\0\0\0"
    "1952 A.D.\0\0\0"
    "1991 A.D.\0\0";
#pragma force_active reset

void fn_800B6D10(unsigned int era, void *stream)
{
    char *strings = jumptable_80246E60;

    switch (era) {
    case 0:
        fn_800F9D4C(stream, strings + 0x954);
        break;
    case 1:
        fn_800F9D4C(stream, &lbl_8064B6C0);
        break;
    case 2:
        fn_800F9D4C(stream, strings + 0x960);
        break;
    case 3:
        fn_800F9D4C(stream, strings + 0x96C);
        break;
    case 4:
        fn_800F9D4C(stream, strings + 0x978);
        break;
    case 5:
        fn_800F9D4C(stream, strings + 0x984);
        break;
    case 6:
        fn_800F9D4C(stream, strings + 0x990);
        break;
    case 7:
        fn_800F9D4C(stream, strings + 0x99C);
        break;
    case 8:
        fn_800F9D4C(stream, strings + 0x9A8);
        break;
    case 10:
        fn_800F9D4C(stream, strings + 0x9B4);
        break;
    case 9:
        fn_800F9D4C(stream, strings + 0x9C0);
        break;
    case 11:
        fn_800F9D4C(stream, strings + 0x9CC);
        break;
    }
}
