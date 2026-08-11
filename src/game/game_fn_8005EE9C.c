typedef signed int s32;

s32 fn_8005EE9C(s32 first, s32 second, s32 *state)
{
    s32 either = second | first;
    s32 result = -1;

    while (result == -1) {
        *state = ((*state += 1) >= 8) ? 0 : *state;

        switch (*state) {
        case 0:
            result = 7;
            break;
        case 1:
            result = 2;
            break;
        case 2:
            result = second != 0 ? -1 : 3;
            break;
        case 3:
            result = first != 0 ? -1 : 4;
            break;
        case 4:
            result = first != 0 ? -1 : 6;
            break;
        case 5:
            result = second != 0 ? -1 : 0;
            break;
        case 6:
            result = either != 0 ? -1 : 1;
            break;
        case 7:
            result = either != 0 ? -1 : 5;
            break;
        }
    }

    return result;
}
