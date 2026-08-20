typedef unsigned char u8;

typedef struct DVDFileInfo {
    u8 data[0x3C];
} DVDFileInfo;

extern void* fn_8015E4A4(void);
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, int, ...);
extern int fn_800F9D4C(char*, const char*, ...);
extern int fn_802136A4(const char*);
extern int fn_80213394(const char*, DVDFileInfo*);
extern void fn_8021345C(DVDFileInfo*);
extern void fn_8015977C(int, int, int, int, int);
extern const char lbl_8024FF00[];
extern const char lbl_8024FFEC[];
extern const char lbl_8064DC80[];
extern char lbl_8064BC10;
extern char lbl_8064BC18;

int fn_8016E294(void* state)
{
    signed char path[16];
    DVDFileInfo file;
    int first;
    int second;
    int third;
    int i;
    int opened;

    fn_8015E4A4();
    if (fn_8016A598(state) != 3) {
        fn_80163BB4(state, lbl_8024FF00, 3, fn_8016A598(state));
        return 0;
    }

    first = (int)fn_8016A694(state, 1);
    second = (int)fn_8016A694(state, 2);
    third = (int)fn_8016A694(state, 3);
    fn_800F9D4C((char*)path, lbl_8024FFEC, lbl_8064DC80, first);
    for (i = 0; i < 13; i++) {
        if (path[i] == ' ') {
            path[i] = '0';
        }
    }
    fn_802136A4(&lbl_8064BC10);
    opened = fn_80213394((char*)path, &file);
    fn_802136A4(&lbl_8064BC18);
    if (opened != 0) {
        fn_8021345C(&file);
        fn_8015977C(first, second, third, 0, 0);
    }
    return 0;
}
