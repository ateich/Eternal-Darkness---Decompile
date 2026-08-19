extern double fn_8016BA4C(signed char*, signed char**);
extern int fn_800F8D14(int);

int fn_80163B14(signed char* text, double* result)
{
    signed char* end;
    double value = fn_8016BA4C(text, &end);

    if (end == text) {
        return 0;
    }
    while (fn_800F8D14((unsigned char)*end)) {
        end++;
    }
    if (*end != 0) {
        return 0;
    }
    *result = value;
    return 1;
}
