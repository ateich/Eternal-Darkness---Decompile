extern void fn_801084B0(void);
extern int fn_80108470(void);
extern void* memset(void*, int, unsigned long);

int fn_80109868(void* state)
{
    if (state == 0) {
        return 1;
    }

    fn_801084B0();
    memset(state, 0, 0x1C0);
    while (fn_80108470() != 3) {}
    return 0;
}
