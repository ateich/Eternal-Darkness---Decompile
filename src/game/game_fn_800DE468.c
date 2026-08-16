extern void fn_801A98F4(int, int);
extern int fn_80201B44();
extern void fn_801ACACC(int, int, int, int);

void fn_800DE468(int alternate)
{
    if (alternate != 0) {
        fn_801A98F4(226, 100);
        fn_801ACACC(224, 100, fn_80201B44(), 60);
    } else {
        fn_801A98F4(226, 65);
        fn_801ACACC(224, 65, fn_80201B44(), 60);
    }
}
