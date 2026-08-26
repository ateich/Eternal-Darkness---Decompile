typedef signed short s16;
typedef unsigned short u16;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

int fn_8017D1E0(Vec3s* first, Vec3s* second, u16 distance, u16 close,
                u16 limit, s16* counter)
{
    int result = 0;
    s16 dx;
    s16 dy;
    s16 dz;

    if (distance < close) {
        distance = close;
    }
    dx = second->x - first->x;
    if (dx < 0) {
        dx = -dx;
    }
    if (dx < distance) {
        dy = second->y - first->y;
        if (dy < 0) {
            dy = -dy;
        }
        if (dy < distance) {
            dz = second->z - first->z;
            if (dz < 0) {
                dz = -dz;
            }
            if (dz < distance) {
                if (dx <= close && dy <= close && dz <= close) {
                    result = 1;
                } else if (counter != 0) {
                    int next = *counter + 1;
                    u16 value = limit;
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
