int fn_800CAC5C(int type, int mode, int *first, int *second, int *third)
{
    int result = 1;

    switch (type) {
    case 3:
        *third = 4;
        switch (mode) {
        case 1: *first = 13; *second = 1; break;
        case 2: *first = 22; *second = 6; break;
        case 3: *first = 20; *second = 7; break;
        default: *first = 24; *second = 8; break;
        }
        break;
    case 4:
        *third = 5;
        switch (mode) {
        case 1: *first = 14; *second = 2; break;
        case 2: *first = 37; *second = 16; break;
        case 3: *first = 38; *second = 15; break;
        default: result = 0; break;
        }
        break;
    case 5:
        *third = 7;
        switch (mode) {
        case 1: *first = 21; *second = 3; break;
        case 2: *first = 59; *second = 71; break;
        case 3: *first = 60; *second = 72; break;
        default: result = 0; break;
        }
        break;
    case 6:
        *third = 6;
        switch (mode) {
        case 1: *first = 50; *second = 28; break;
        case 2: *first = 51; *second = 79; break;
        case 3: *first = 52; *second = 80; break;
        default: result = 0; break;
        }
        break;
    case 7:
        *third = 8;
        switch (mode) {
        case 1: *first = 23; *second = 4; break;
        case 2: *first = 56; *second = 29; break;
        case 3: *first = 57; *second = 30; break;
        default: result = 0; break;
        }
        break;
    case 8:
        *third = 9;
        switch (mode) {
        case 1: *first = 61; *second = 66; break;
        case 2: *first = 62; *second = 67; break;
        case 3: *first = 63; *second = 68; break;
        default: result = 0; break;
        }
        break;
    case 34:
        *third = 63;
        *first = 99;
        *second = 128;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}
