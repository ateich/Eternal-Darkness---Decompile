extern void fn_800B18F8(void);
extern void fn_80020E94(void);
extern void fn_8001DE68(void);

void fn_8002387C(int mode)
{
    fn_800B18F8();
    if (mode == 1) {
        fn_80020E94();
    } else {
        fn_8001DE68();
    }
}
