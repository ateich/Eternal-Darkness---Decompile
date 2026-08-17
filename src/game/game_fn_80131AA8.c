extern void fn_800542D0(int, int, int, int, int, int, int, int,
                       int, int, int, int, int);

void fn_80131AA8(int type, int value)
{
    switch (type) {
    case 1:
        if (value == 0) {
            fn_800542D0(-1, -1, 10, 30, 10, 8, 4, -1, -1, -1, -1, 2, 0);
        }
        break;
    case 2:
    case 3:
    case 4:
        if (value == 0) {
            fn_800542D0(-1, -1, 3, 10, 4, 2, 1, -1, -1, 0, 1, 1, -1);
        } else if (value == 450) {
            fn_800542D0(-1, -1, 3, 0, 4, 2, 1, -1, -1, 0, 1, 0, 0x2000);
        }
        break;
    case 6:
        if (value == 0) {
            fn_800542D0(-1, -1, 10, 80, 45, 30, 15, -1, -1, -1, -1, -1, -1);
        }
        break;
    case 9:
        if (value == 0) {
            fn_800542D0(-1, -1, 2, 20, 8, 10, 5, -1, 17, 0, 0, 1, -1);
        }
        break;
    case 12:
    case 13:
    case 14:
        if (value == 0) {
            fn_800542D0(-1, -1, 3, 10, 4, 2, 1, -1, -1, 0, 1, 1, -1);
        }
        break;
    case 19:
        if (value == 0) {
            fn_800542D0(-1, -1, 10, 30, 10, 8, 4, -1, -1, -1, -1, 1, 0);
        }
        break;
    case 39:
    case 40:
    case 41:
        if (value == 0) {
            fn_800542D0(-1, -1, 10, 15, 8, -1, -1, -1, -1, -1, -1, 0, 0);
        }
        break;
    case 91:
    case 97:
    case 98:
        if (value == 0) {
            fn_800542D0(-1, -1, 10, 15, 8, -1, -1, -1, -1, -1, -1, 2, 0x2000);
        }
    case 147:
    case 148:
    case 149:
    case 153:
    case 154:
    case 155:
        if (value == 0) {
            fn_800542D0(-1, -1, 10, 15, 8, -1, -1, -1, -1, -1, -1, 0, 0);
        }
        break;
    }
}
