extern unsigned int fn_800FBFB0();
#define fn_800FBFB0() ((int)fn_800FBFB0())
extern int fn_8011F598(int, int, int, int, void*, int);
extern void* lbl_8064C5A8;
extern void fn_801D6724(int, int, int, int, int, int, int, int, int, int,
                       int, int, int, int, int, int, int, int, int, int,
                       int, int, int, int, int);

void fn_800AA94C(int owner, int search, int option, int value,
                 int resource)
{
    unsigned char result[0x30];
    int first;
    int second;

    first = 17;
    for (;;) {
        while (first >= 17) {
            first = fn_800FBFB0() & 0xF;
        }
        if (fn_8011F598(search, 9, 15, first - 1, result, 1) != -1) {
            break;
        }
    }

    second = 17;
    for (;;) {
        while (second >= 17 || first == second) {
            second = fn_800FBFB0() & 0xF;
        }
        if (fn_8011F598(search, 9, 15, second - 1, result, 1) != -1) {
            break;
        }
    }

    search = 0x42040;
    if ((unsigned short)option == 0) {
        search |= 0x10;
    }
    if ((fn_800FBFB0() & 1) != 0) {
        search |= 0x10000;
    } else {
        search |= 0x20000;
    }

    fn_801D6724(owner, 9, 15, first, second, *(int*)lbl_8064C5A8, 0, 0,
                value, 6, 2, 3, 1, 0, 1, 17, 4, 2, 16, 0, resource,
                option, search, 0, 4);
}
