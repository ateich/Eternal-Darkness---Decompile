typedef unsigned char u8;

extern void fn_8011FA8C(void *, int, int);
extern void fn_80137ED0(int);

int fn_8007780C(void *object, void *state)
{
    fn_8011FA8C(object, 0, 0xC0);
    if (*(int *)((u8 *)state + 0x1B4) != -1) {
        fn_80137ED0(*(int *)((u8 *)state + 0x1B4));
        *(int *)((u8 *)state + 0x1B4) = -1;
    }
    return 1;
}
