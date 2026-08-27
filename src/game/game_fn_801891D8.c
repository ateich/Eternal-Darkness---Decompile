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

void fn_801891D8(u8* entry, void* context,
                 void (*callback)(void*, float, float, float, float, float))
{
    Vec3 input;
    Vec3 copy;
    Vec3 projected;
    Vec3 output;
    Vec3 seed;
    float radius;

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
    radius = 100.0f + (float)entry[0x21];
    callback(context, output.x - radius, output.y + radius,
             output.x + radius, output.y - radius, output.z);
}
