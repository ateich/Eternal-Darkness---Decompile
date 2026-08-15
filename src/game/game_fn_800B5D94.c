extern void fn_8017B074(int);
extern void fn_800B5D10(int);
extern void fn_800B1974(int);

void fn_800B5D94(int value)
{
    fn_8017B074(value);
    if (value == 0) {
        fn_800B5D10(1);
    } else {
        fn_800B1974(0);
    }
}
