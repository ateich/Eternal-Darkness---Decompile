extern void fn_800B18F8(int arg);
extern void fn_80020E94(void);
extern void fn_8001DE68(void);

void fn_8002387C(int arg) {
    fn_800B18F8(arg);
    if (arg == 1) {
        fn_80020E94();
    } else {
        fn_8001DE68();
    }
}
