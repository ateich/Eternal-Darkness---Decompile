typedef unsigned short u16;

typedef float Matrix[3][4];

extern void fn_8011F3B4(void* object, Matrix matrix, u16 angle, int enabled);
extern void fn_8011F304(void* output, Matrix matrix, int enabled);

void fn_8011F2B8(void* object, void* output, u16 angle, int enabled)
{
    Matrix matrix;

    fn_8011F3B4(object, matrix, angle, enabled);
    fn_8011F304(output, matrix, enabled);
}
