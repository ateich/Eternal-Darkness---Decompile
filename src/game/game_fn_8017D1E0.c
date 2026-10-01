typedef signed short s16;
typedef unsigned short u16;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

#define ABS(x) ((x) < 0 ? -(x) : (x))

int fn_8017D1E0(Vec3s* first, Vec3s* second, u16 distance, u16 close,
                u16 limit, s16* counter)
{
    u16 dx;
    u16 dy;
    int result = 0;
    u16 dz;

    if (distance < close) {
        distance = close;
    }
    dx = ABS(second->x - first->x);
    if (dx < distance) {
        dy = ABS(second->y - first->y);
        if (dy < distance) {
            dz = ABS(second->z - first->z);
            if (dz < distance) {
                if (dx <= close && dy <= close && dz <= close) {
                    result = 1;
                } else if (counter != 0) {
                    int next = *counter + 1;
                    int value = limit;

                    if (next < value) {
                        value = next;
                    }
                    *counter = value;
                }
            }
        }
    }
    return result;
}
