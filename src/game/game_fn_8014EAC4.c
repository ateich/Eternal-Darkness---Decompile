typedef struct Vec3Words {
    unsigned int x, y, z;
} Vec3Words;

extern unsigned char* fn_8014EC30(void*, unsigned short, unsigned char,
                                  unsigned short, unsigned short,
                                  unsigned short, unsigned short,
                                  unsigned char);

unsigned char* fn_8014EAC4(void* first, Vec3Words* position,
                           unsigned short second, unsigned char third,
                           unsigned short fourth, unsigned short fifth,
                           unsigned short sixth, unsigned short seventh,
                           unsigned char eighth)
{
    unsigned char* result;

    result = fn_8014EC30(first, second, third, fourth, fifth, sixth, seventh,
                         eighth);
    if (result != 0) {
        *(unsigned int*)(result + 4) = 1;
        *(Vec3Words*)(result + 0x40) = *position;
    }
    return result;
}
