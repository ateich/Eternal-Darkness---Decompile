typedef unsigned int u32;

extern void fn_8012C62C(void*, int, u32*, u32*, u32*, int);
extern void fn_8012F58C(void*, int, int, int, int, int);
extern void fn_8012C278(void*, int, int, int, u32*, u32*, u32*, int);

void fn_800A1AF0(void* object, int index, int active, int copy_values,
                 u32* first_in, u32* second_in, u32* third_in, int mode)
{
    u32 first;
    u32 second;
    u32 third;

    if (copy_values) {
        second = *second_in;
        first = *first_in;
        third = *third_in;
        fn_8012C62C(object, index, &first, &second, &third, mode);
        if (!active) {
            fn_8012F58C(object, index, 0, 0, 0, 2);
        }
    } else {
        fn_8012C278(object, index, active, copy_values, first_in, second_in,
                    third_in, mode);
    }
}
