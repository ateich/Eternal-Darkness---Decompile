extern void fn_80167EB0(void*, void*, unsigned int, void*, int);

unsigned int fn_80168018(void* object, void* input, int reverse)
{
    unsigned int value;
    fn_80167EB0(object, &value, sizeof(value), input, reverse);
    return value;
}
