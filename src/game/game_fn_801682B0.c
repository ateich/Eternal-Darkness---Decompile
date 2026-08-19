typedef struct InputWords {
    unsigned char pad00[0x2c];
    unsigned int* values;
    int count;
} InputWords;

#pragma use_lmw_stmw on

extern int fn_80167FE4(void*, void*, int);
extern void* fn_8016B5CC(void*, void*, unsigned int, const char*, int);
extern void fn_80167F48(void*, void*, int, unsigned int, void*, int);
extern const char lbl_8024FAF4[];

void fn_801682B0(void* object, InputWords* words, void* input, int reverse)
{
    int count = fn_80167FE4(object, input, reverse);

    words->count = count;
    words->values = fn_8016B5CC(object, 0, count * sizeof(unsigned int),
                                lbl_8024FAF4, 131);
    fn_80167F48(object, words->values, count, sizeof(unsigned int), input,
                reverse);
}
