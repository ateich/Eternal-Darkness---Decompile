extern const double lbl_80650650;
extern int fn_8015ECF8(void*, double);
extern int fn_8015F9B0(void*, int, int);

int fn_8015EDC0(void* object, double value)
{
    if (value <= lbl_80650650) {
        if ((double)(int)value == value)
            return fn_8015F9B0(object, 6, (int)value);
    }

    return fn_8015F9B0(object, 8, fn_8015ECF8(object, value));
}
