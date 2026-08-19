extern unsigned int fn_80168018(void*, void*, int);
extern void* fn_80163A9C(void*, unsigned int);
extern void fn_80167EB0(void*, void*, unsigned int, void*, int);
extern void* fn_80166E3C(void*, void*, unsigned int);

void* fn_80168080(void* object, void* input, int reverse)
{
    unsigned int size = fn_80168018(object, input, reverse);
    void* data;

    if (size == 0) {
        return 0;
    }
    data = fn_80163A9C(object, size);
    fn_80167EB0(object, data, size, input, 0);
    return fn_80166E3C(object, data, size - 1);
}
