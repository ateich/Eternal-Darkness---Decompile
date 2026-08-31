typedef signed char s8;
typedef unsigned char u8;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern float fn_80178F88(float, float, float, float, float, float);
extern int fn_801ABCA8(int, int, int, int, int, int);
extern float lbl_80650E60;
extern float lbl_80650E68;
extern float lbl_80650E78;
extern double lbl_80650E80;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

u8 fn_801ABD3C(Vec3* first, Vec3* second, float range, u8 low, u8 high,
               int mode)
{
    int result;
    float distance;

    distance = fn_80178F88(second->x, second->y, second->z,
                           first->x, first->y, first->z);
    switch ((unsigned int)(s8)mode) {
    case 0:
        /* Retail reaches the clamp with result intentionally untouched. */
        break;
    case 1: {
        float factor;
        float ratio;
        int low_value;

        if (distance < lbl_80650E60) {
            distance = -distance;
        }
        ratio = distance / range;
        low_value = low;
        factor = lbl_80650E68;
        factor -= lbl_80650E78 * ratio +
                  lbl_80650E78 * (ratio * ratio);
        result = low_value + (int)(factor * (high - low_value));
        break;
    }
    case 2:
        result = fn_801ABCA8(high, (int)distance, 1800, 9200, 50, 0);
        break;
    case 3:
        result = fn_801ABCA8(high, (int)distance, 3700, 15167, 50, 0);
        break;
    case 4:
        result = fn_801ABCA8(high, (int)distance, 800, 2900, 50, 0);
        break;
    case 5:
        result = high;
        break;
    case 6:
        result = fn_801ABCA8(high, (int)distance, 7000, 25000, 50, 30);
        break;
    }

    return MIN(MAX(result, 0), 127);
}
