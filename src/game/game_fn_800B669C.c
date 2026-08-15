extern void fn_800B261C(int);
extern void fn_8017BBD0(int, int, int, int, int);
extern void fn_800B1974(int);

void fn_800B669C(int value, int state)
{
    fn_800B261C(1);
    fn_8017BBD0(2, value, 0, 0, 0);
    fn_800B1974(state);
}
