typedef union DoubleBits {
    double value;
    struct {
        unsigned long high;
        unsigned long low;
    } words;
} DoubleBits;

double fn_80101960(double magnitude, double sign)
{
    DoubleBits y;
    DoubleBits x;

    x.value = magnitude;
    y.value = sign;
    x.words.high = (x.words.high & 0x7FFFFFFF) | (y.words.high & 0x80000000);
    return x.value;
}
