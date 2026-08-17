typedef unsigned char u8;
typedef unsigned short u16;

typedef float Matrix[3][4];

extern void fn_8011F41C(void* object, u16 angle, int first, Matrix matrix,
                        int second, int third);

void fn_8011F3B4(void* object, Matrix matrix, u16 angle, int options)
{
    u8 flags = options;
    int first = 0;
    int second = 1;
    int third = 1;

    if (flags & 2) {
        second = 0;
    } else if (flags & 4) {
        first = 1;
    }
    if (flags & 8) {
        third = 0;
    }
    fn_8011F41C(object, angle, first, matrix, second, third);
}
