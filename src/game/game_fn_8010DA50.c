int fn_8010DA50(int value)
{
    int result;

    switch (value) {
    case -1:
        result = 441;
        break;
    case -2:
        result = 320;
        break;
    default:
        result = (value & 1) ? 488 : 398;
        break;
    }
    return (short)result;
}
