int fn_800C4880(int value, int delta, int minimum, int maximum)
{
    value += delta;
    if (value > maximum)
        value = minimum + (value - maximum);
    else if (value < minimum)
        value = maximum - (minimum - value);
    return value;
}
