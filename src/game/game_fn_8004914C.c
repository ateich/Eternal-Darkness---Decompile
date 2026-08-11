extern void* fn_8004910C(void);
extern void* fn_80201BC8(void* object);

void* fn_8004914C(void)
{
    void* result = 0;
    void* object = fn_8004910C();

    if (object != 0) {
        result = fn_80201BC8(object);
    }
    return result;
}
