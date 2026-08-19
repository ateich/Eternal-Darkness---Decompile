extern void fn_80167EB0(void*, void*, unsigned int, void*, int);

int fn_80167FE4(void* object, void* input, int reverse)
{
    int value;
    fn_80167EB0(object, &value, sizeof(value), input, reverse);
    return value;
}
