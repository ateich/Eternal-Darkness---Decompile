typedef signed long s32;

extern void fn_801A8974(s32, s32, s32, s32, s32, s32);

void fn_801156D0(s32 index)
{
    switch (index) {
    case 0:
        fn_801A8974(0xB8, 0x3A, 0x40, 0x40, -1, 2);
        break;
    case 1:
        fn_801A8974(0x106, 0x24, 0x40, 0x40, -1, 2);
        break;
    case 2:
        fn_801A8974(0x155, 0x2D, 0x40, 0x40, -1, 2);
        break;
    case 3:
        fn_801A8974(0x1A2, 0x24, 0x40, 0x40, -1, 2);
        break;
    case 4:
        fn_801A8974(0x1F0, 0x32, 0x40, 0x40, -1, 2);
        break;
    }
}
