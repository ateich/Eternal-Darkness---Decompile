typedef unsigned int u32;

extern int fn_8011F130(void *);
extern u32 fn_80178E94(int, int);
extern void fn_801441C0(int, int, int);

int fn_800C91F8(void *first, void *second)
{
    int second_id = fn_8011F130(second);
    u32 distance = fn_80178E94(fn_8011F130(first), second_id);

    if (distance <= 0x2EE) {
        int mode = 1;
        if (distance <= 0x177) {
            mode = 3;
        }
        fn_801441C0(1, mode, 0xA);
    }
    return 0;
}
