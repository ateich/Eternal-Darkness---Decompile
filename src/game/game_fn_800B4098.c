extern void fn_800B25AC(void);
extern void fn_800BBCD4(int);
extern void fn_800B6840(int);

void fn_800B4098(int value, int mode)
{
    fn_800B25AC();
    switch (mode) {
    case 0:
        fn_800BBCD4(value);
        break;
    case 1:
    case 2:
        fn_800B6840(value);
        break;
    }
}
