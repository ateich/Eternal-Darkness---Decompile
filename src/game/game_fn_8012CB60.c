typedef unsigned char u8;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern float lbl_806501DC;
extern int fn_8012E114(u8*, int, Vec3*);

float fn_8012CB60(u8* state, int index, int component)
{
    Vec3 value;
    float result = lbl_806501DC;

    if (fn_8012E114(state, index, &value)) {
        switch (component) {
        case 0:
            result = value.x;
            break;
        case 1:
            result = value.y;
            break;
        case 2:
            result = value.z;
            break;
        }
    }
    return result;
}
