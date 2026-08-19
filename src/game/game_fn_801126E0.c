extern unsigned int lbl_80331748[];

extern double fn_8016A694(void*, int);
extern unsigned int fn_800F5C54();
extern void fn_8016A830(void*, double);
extern void fn_8016A7D8(void*);

int fn_801126E0(void* object)
{
    unsigned int value = fn_800F5C54(fn_8016A694(object, 1));

    value &= lbl_80331748[0];

    if (value != 0) {
        fn_8016A830(object, (double)value);
    } else {
        fn_8016A7D8(object);
    }
    return 1;
}
