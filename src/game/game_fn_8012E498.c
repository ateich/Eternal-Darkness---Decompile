typedef unsigned char u8;

extern void fn_802114E0(void*, const void*);
extern void fn_80210FDC(void*, void*, void*);

void fn_8012E498(int* initialized, const void* value, void* matrix)
{
    u8 temporary[48];

    if (*initialized != 0) {
        fn_802114E0(temporary, value);
        fn_80210FDC(temporary, matrix, matrix);
    } else {
        fn_802114E0(matrix, value);
    }
    *initialized = 1;
}
