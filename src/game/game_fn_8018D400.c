typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;
typedef void (*Callback)(void*, float, float, float, float, float);

extern u8 lbl_8063C068[];

extern void fn_80179B08(void*, Vec3*);
extern void fn_8017ACE0(void*, Vec3*, Vec3*);
extern unsigned int fn_801F6D90(s16, s16, s16);

void fn_8018D400(u8* self, void* context, Callback callback)
{
    Vec3 input;
    Vec3 output;
    int half_width;
    int half_height;
    int x_radius;
    int y_radius;
    unsigned int location;
    u8* self_local;
    u8* coordinates;
    void* context_local;
    Callback callback_local;

    self_local = self;
    coordinates = self_local + 0x10;
    context_local = context;
    callback_local = callback;
    fn_80179B08(coordinates, &input);
    fn_8017ACE0(lbl_8063C068, &input, &output);

    half_width = *(u16*)(self_local + 0xDC) >> 1;
    half_height = *(u16*)(self_local + 0xDE) >> 1;
    location = fn_801F6D90(*(s16*)(coordinates + 0),
                           *(s16*)(coordinates + 2),
                           *(s16*)(coordinates + 4));

    if (half_width > 1) {
        if (location > 1200) {
            x_radius = (int)((float)(8001 - location) /
                             (6801.0f / (float)(half_width - 1))) + 1;
        } else {
            x_radius = half_width +
                       (int)((float)(1201 - location) /
                             (400.0f / (float)half_width));
        }
        if (x_radius <= 0) {
            x_radius = 1;
        }
    } else {
        x_radius = 0;
    }

    if (half_height > 1) {
        if (location > 1200) {
            y_radius = (int)((float)(8001 - location) /
                             (6801.0f / (float)(half_height - 1))) + 1;
        } else {
            y_radius = half_height +
                       (int)((float)(1201 - location) /
                             (400.0f / (float)half_height));
        }
        if (y_radius <= 0) {
            y_radius = 1;
        }
    } else {
        y_radius = 0;
    }

    callback_local(context_local, output.x - (float)x_radius,
                   output.y + (float)y_radius,
                   output.x + (float)x_radius,
                   output.y - (float)y_radius, output.z);
}
