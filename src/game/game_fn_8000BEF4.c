typedef int s32;

extern double fn_8016A694(void*, s32);
extern void fn_8011E19C(s32, s32);

s32 fn_8000BEF4(void* script)
{
    if ((s32)fn_8016A694(script, 1) != 0) {
        fn_8011E19C(1, 0);
    } else {
        fn_8011E19C(1, 1);
    }
    return 0;
}
