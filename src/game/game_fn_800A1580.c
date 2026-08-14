int fn_800A1580(int value)
{
    int result = 0;

    switch (value) {
    case 36:
        result = 1;
        break;
    case 24:
    case 31:
        result = 2;
        break;
    case 12:
        result = 4;
        break;
    }
    return result;
}
