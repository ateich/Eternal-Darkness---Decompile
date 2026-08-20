extern int fn_80201B44(void);
extern void fn_8020123C(int, int, int, int);

void fn_8016E254(int value)
{
    int current = fn_80201B44();
    fn_8020123C(253, 0, current, value);
}
