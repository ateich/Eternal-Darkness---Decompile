typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern float lbl_8064D030[2];
extern u16 lbl_8064D02C[2];
extern u16 lbl_8064D028[2];
extern void fn_80179AEC(Vec3*, const Vec3*);
extern float fn_800ED720(float);

static Vec3 first[2] = {0};
static Vec3 second[2] = {0};
static Vec3 third[2] = {0};
static Vec3 normal[2] = {0};

static inline void set_axes(u8 index, u16 major, u16 minor)
{
    u16 major_axis = major;
    u16 minor_axis = minor;
    u16* axes;

    axes = lbl_8064D02C;
    axes[index] = major_axis;
    axes = lbl_8064D028;
    axes[index] = minor_axis;
}

#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_80141EA8(Vec3* a, Vec3* b, Vec3* c, u8 triangle)
{
    Vec3 u;
    Vec3 v;
    float length;
    float ax, ay, az;

    fn_80179AEC(a, &second[triangle]);
    fn_80179AEC(b, &first[triangle]);
    fn_80179AEC(c, &third[triangle]);
    u.x = first[triangle].x - second[triangle].x;
    u.y = first[triangle].y - second[triangle].y;
    u.z = first[triangle].z - second[triangle].z;
    v.x = third[triangle].x - second[triangle].x;
    v.y = third[triangle].y - second[triangle].y;
    v.z = third[triangle].z - second[triangle].z;
    normal[triangle].x = u.y * v.z - u.z * v.y;
    normal[triangle].y = u.z * v.x - u.x * v.z;
    normal[triangle].z = u.x * v.y - u.y * v.x;
    length = normal[triangle].x * normal[triangle].x +
             normal[triangle].y * normal[triangle].y +
             normal[triangle].z * normal[triangle].z;
    if (0.0f != length) {
        length = fn_800ED720(length);
        normal[triangle].x /= length;
        normal[triangle].y /= length;
        normal[triangle].z /= length;
    }
    ax = normal[triangle].x;
    ay = normal[triangle].y;
    az = normal[triangle].z;
    lbl_8064D030[triangle] = -(ax * second[triangle].x + ay * second[triangle].y +
                               az * second[triangle].z);
    if (ax < 0.0f) ax = -ax;
    if (ay < 0.0f) ay = -ay;
    if (az < 0.0f) az = -az;
    if (ax > ay) {
        if (ax > az) {
            set_axes(triangle, 1, 2);
        } else {
            set_axes(triangle, 0, 1);
        }
    } else {
        if (az > ay) {
            set_axes(triangle, 0, 1);
        } else {
            set_axes(triangle, 0, 2);
        }
    }
}
#pragma opt_lifetimes reset
#pragma opt_propagation reset
