extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8011E26C(int);
extern void fn_8011DD8C(int, int);
extern const char lbl_8024FF00[];

int fn_80175964(void* state)
{
    int second;
    int first;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    fn_8011E26C(1);
    second = fn_8016A694(state, 2);
    first = fn_8016A694(state, 1);
    fn_8011DD8C(first, second);
    return 0;
}
