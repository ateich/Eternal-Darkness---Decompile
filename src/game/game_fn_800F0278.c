extern int fn_800F2BEC(void);
extern int fn_800F2BE0(int);
extern void OSReport(const char *);

int fn_800F0278(const char *text)
{
    int result = 0;
    signed char ch;

    while (result == 0 && (ch = *text++) != 0) {
        int state = fn_800F2BEC();
        char string[2];

        string[0] = ch;
        string[1] = 0;
        fn_800F2BE0(0);
        OSReport(string);
        fn_800F2BE0(state);
        result = 0;
    }
    return result;
}
