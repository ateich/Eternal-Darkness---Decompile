typedef signed short s16;
typedef unsigned char u8;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern u8 lbl_8063C068[];

extern void fn_80179B08(void*, Vec3*);
extern void fn_8017ACE0(void*, Vec3*, Vec3*);
extern int fn_801F6D90(s16, s16, s16);
extern int fn_8018D1F0(u8, int);

void fn_80188A7C(u8* entry, void* context,
                 void (*callback)(void*, float, float, float, float, float))
{
    Vec3 input;
    Vec3 output;
    int location;
    float radius;

    fn_80179B08(entry + 0xA, &input);
    fn_8017ACE0(lbl_8063C068, &input, &output);
    location = fn_801F6D90(*(s16*)(entry + 0xA), *(s16*)(entry + 0xC),
                           *(s16*)(entry + 0xE));
    radius = (float)fn_8018D1F0(entry[0x21], location);
    callback(context, output.x - radius, output.y - radius,
             output.x + radius, output.y + radius, output.z);
}
