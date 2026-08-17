int fn_80130998(int value, float scale)
{
    int scaled = (int)(value * scale);
    int result;
    result = value < (scaled > 0 ? scaled : 0)
                 ? value
                 : (scaled > 0 ? scaled : 0);

    if (result < 100) {
        result = value < 100 ? value : 100;
    }
    return result;
}
