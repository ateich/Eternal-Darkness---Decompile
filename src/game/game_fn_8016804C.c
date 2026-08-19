extern void fn_80167EB0(void*, void*, unsigned int, void*, int);

double fn_8016804C(void* object, void* input, int reverse)
{
    double value;
    fn_80167EB0(object, &value, sizeof(value), input, reverse);
    return value;
}
