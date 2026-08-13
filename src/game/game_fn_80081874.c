extern void fn_8011E310(int, int, int, int, int, int, int);

void fn_80081874(int unused, int event)
{
    if (event == 1) {
        fn_8011E310(6, 0x32, 0, 0, 0x32, 0, 0);
    }
}
