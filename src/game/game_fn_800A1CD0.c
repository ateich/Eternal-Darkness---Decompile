extern void fn_80201B94(void);
extern int fn_80201C48(void);
extern void* fn_80201814(void);
extern int fn_80201BC8(void);

int fn_800A1CD0(void)
{
    int result = 0;
    fn_80201B94();
    if (fn_80201C48()) {
        fn_80201814();
        result = fn_80201BC8();
    }
    return result;
}
