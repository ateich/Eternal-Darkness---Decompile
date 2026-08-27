typedef signed short s16;
typedef unsigned char u8;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern u8 lbl_8063C068[];

extern void fn_801F68B0(Vec3*);
extern void fn_80179A18(Vec3*);
extern void fn_8017ACE0(void*, Vec3*, Vec3*);

void fn_80189390(u8* entry, void* context,
                 void (*callback)(void*, float, float, float, float, float),
                 int x_scale, int y_scale)
{
    Vec3 input;
    Vec3 copy;
    Vec3 projected;
    Vec3 output;
    Vec3 seed;
    int x_radius;
    int y_radius;

    fn_801F68B0(&seed);
    copy = seed;
    input.x = copy.x - (float)*(s16*)(entry + 0xA);
    input.y = copy.y - (float)*(s16*)(entry + 0xC);
    input.z = copy.z - (float)*(s16*)(entry + 0xE);
    fn_80179A18(&input);
    projected.x = (float)*(s16*)(entry + 0xA) + input.x * 120.0f;
    projected.y = (float)*(s16*)(entry + 0xC) + input.y * 120.0f;
    projected.z = (float)*(s16*)(entry + 0xE) + input.z * 120.0f;
    fn_8017ACE0(lbl_8063C068, &projected, &output);
    x_radius = (int)(0.078125 * (double)x_scale * (double)entry[0x21]);
    y_radius = (int)(0.078125 * (double)y_scale * (double)entry[0x21]);
    callback(context, output.x - (float)x_radius, output.y + (float)y_radius,
             output.x + (float)x_radius, output.y - (float)y_radius, output.z);
}
