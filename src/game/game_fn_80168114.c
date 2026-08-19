typedef struct InputArray {
    unsigned char pad00[0x18];
    unsigned int* values;
} InputArray;

#pragma use_lmw_stmw on

extern int fn_80167FE4(void*, void*, int);
extern void* fn_8016B5CC(void*, void*, unsigned int, const char*, int);
extern void fn_80167F48(void*, void*, int, unsigned int, void*, int);
extern int fn_80167D68(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80161244(void*, InputArray*, int);
extern const char lbl_8024FAF4[];
extern const char lbl_8024FB00[];

void fn_80168114(void* object, InputArray* array, void* input, int reverse)
{
    int count = fn_80167FE4(object, input, reverse);

    array->values = fn_8016B5CC(object, 0, count * sizeof(int),
                                lbl_8024FAF4, 108);
    fn_80167F48(object, array->values, count, sizeof(int), input, reverse);
    if (array->values[count - 1] != 0) {
        fn_80163BB4(object, lbl_8024FB00, fn_80167D68(input));
    }
    fn_80161244(object, array, count);
}
