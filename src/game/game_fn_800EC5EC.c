typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern void fn_800EC434(void *, Vec3 *, Vec3 *, Vec3 *);

void fn_800EC5EC(void *context, unsigned char triangle, Vec3 *vertices,
                 unsigned char *indices)
{
    fn_800EC434(context, vertices + indices[triangle * 3],
                vertices + indices[triangle * 3 + 1],
                vertices + indices[triangle * 3 + 2]);
}
