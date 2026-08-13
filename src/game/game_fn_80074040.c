extern void *fn_801A7498(void *);
extern void *fn_801A7490(void *);
extern void fn_8020123C(int, void *, void *, void *);

/* NonMatching: behavior-complete event forwarding; remaining differences are
 * an equivalent swap of the argument and first-result registers. */
int fn_80074040(void *unused, void *argument)
{
    void *first;
    void *second;

    first = fn_801A7498(argument);
    second = fn_801A7490(argument);
    fn_8020123C(0x72, first, second, argument);
    return 1;
}
