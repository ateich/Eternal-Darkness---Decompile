typedef unsigned char u8;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern u8 lbl_8063C068[];

extern void fn_80179B08(void*, Vec3*);
extern void fn_8017ACE0(void*, Vec3*, Vec3*);

void fn_80188B44(u8* entry, void* context,
                 void (*callback)(void*, float, float, float, float, float))
{
    Vec3 input;
    Vec3 output;

    fn_80179B08(entry + 0xA, &input);
    fn_8017ACE0(lbl_8063C068, &input, &output);
    callback(context, output.x - (float)entry[0x21],
             output.y + (float)entry[0x21],
             output.x + (float)entry[0x21],
             output.y - (float)entry[0x21], output.z);
}
