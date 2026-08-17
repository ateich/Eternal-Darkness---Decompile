extern int fn_801A7DFC(void);
extern void fn_8013B24C(void*, void*, int, void*, int, short*, int*, int, int);
extern void* lbl_8064C4E4;

int fn_8013B9DC(void* object, char* item, unsigned short count, void* other)
{
    int different;
    int output;
    int limit;
    int i;
    int one;
    short value;

    different = object != lbl_8064C4E4;
    if (fn_801A7DFC() != 0) {
        output = 0;
        limit = count;
        i = 0;
        one = 1;
        while (i < limit) {
            value = 0;
            output = 0;
            fn_8013B24C(item, other, different, object, 0, &value,
                        &output, 0, one);
            if (value > 0 && *(short*)(item + 0x6E) < 90)
                return 1;
            i++;
            item += 0x74;
        }
    }
    return 0;
}
