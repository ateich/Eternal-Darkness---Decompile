extern int fn_800DC4D4(void *);
extern void fn_8011E310(int, int, int, int, int, int, int);
extern void *fn_8004918C(void);
extern int fn_800C280C(void *, void *, int *);
extern void *fn_80036374(void *);
extern void *fn_800365C8(void *, void *);

void fn_800C2528(void *object)
{
    int value;

    if (fn_800DC4D4(object) != 0) {
        fn_8011E310(2, 19, 2246, 0, 49, 1, 0);
    } else if (fn_800C280C(object, fn_8004918C(), &value) != 0) {
        fn_8011E310(2, 21, value, 0, 50, 3, 0);
    } else if (fn_80036374(object) != 0) {
        fn_8011E310(2, 43, 2250, 0, 49, 5, 0);
    } else if (fn_800365C8(object, fn_8004918C()) != 0) {
        fn_8011E310(2, 23, 2244, 0, 49, 3, 2);
    }
}
