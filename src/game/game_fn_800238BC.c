extern void fn_800B18F8(void);
extern void fn_80020D90(int mode);

void fn_800238BC(int mode)
{
    fn_800B18F8();
    switch (mode) {
    case -1:
        break;
    case 0:
        fn_80020D90(0);
        break;
    case 1:
        fn_80020D90(1);
        break;
    }
}
