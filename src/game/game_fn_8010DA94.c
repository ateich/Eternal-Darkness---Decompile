short fn_8010DA94(int value)
{
    switch (value) {
    case -1:
        return 74;
    case -2:
        return 85;
    default:
        return (value >> 1) * 96 + 208;
    }
}
