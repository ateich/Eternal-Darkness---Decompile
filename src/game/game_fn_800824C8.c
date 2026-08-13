extern void fn_8011E310(int, int, int, int, int, int, int);

void fn_800824C8(int unused, int event)
{
    if (event == 1) {
        fn_8011E310(6, 7, 0, 0, 0x32, 0, 0);
    }
}
