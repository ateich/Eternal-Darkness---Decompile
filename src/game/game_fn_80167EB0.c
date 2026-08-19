extern unsigned int fn_80167DC8(void*, void*);
extern void fn_80167E58(void*, void*, void*, unsigned int);

void fn_80167EB0(void* object, unsigned char* destination, unsigned int size,
                 void* input, int reverse)
{
    if (reverse != 0) {
        unsigned char* output = destination + size - 1;
        unsigned int count = size;

        while (count-- != 0) {
            *output-- = fn_80167DC8(object, input);
        }
    } else {
        fn_80167E58(object, input, destination, size);
    }
}
