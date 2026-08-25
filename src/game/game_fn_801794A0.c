typedef struct Coord3 {
    float x;
    float y;
    float z;
} Coord3;

extern float fn_800ED720(float);
extern float lbl_80650860;

void fn_801794A0(Coord3* first, Coord3* second, Coord3* output)
{
    float length;

    output->x = first->y * second->z - first->z * second->y;
    output->y = first->z * second->x - first->x * second->z;
    output->z = first->x * second->y - first->y * second->x;

    length = fn_800ED720(output->x * output->x + output->y * output->y + output->z * output->z);
    if (lbl_80650860 != length) {
        output->x /= length;
        output->y /= length;
        output->z /= length;
    }
}
