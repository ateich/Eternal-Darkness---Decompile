extern int fn_8015EC10(void*);
extern int fn_8015F9B0(void*, int, int);

int fn_8015F47C(void* object, int type, int value)
{
    fn_8015EC10(object);
    return fn_8015F9B0(object, type, value);
}
