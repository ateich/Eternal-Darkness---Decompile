typedef signed short s16;
typedef unsigned char u8;

typedef struct Sample801F2370 {
    float position[3];
    u8 r, g, b, a;
    int value;
} Sample801F2370;

typedef struct Node801F2370 {
    s16 x, y, z;
    u8 unused[10];
    Sample801F2370* samples;
} Node801F2370;

typedef struct Volume801F2370 {
    int unused0;
    int count;
    float x, y, z;
    s16 half_x, half_y, half_z;
    u8 unused1;
    u8 size_x, size_y, size_z;
    u8 unused2[2];
    Node801F2370* nodes;
} Volume801F2370;

extern float lbl_806513C8;
extern float lbl_806513CC;
extern int lbl_8064CB48;
extern int lbl_8064D18C;

extern void fn_801F10BC(int, int, int);
extern void fn_801F2170(int [8][4], Node801F2370**, int);
extern void fn_800EBF88(float*, float*, int*, int);

int fn_801F2370(Volume801F2370* volume, float* point, int count,
                Sample801F2370* output)
{
    Node801F2370* corners[8];
    float corner_weight[8];
    int mapping[8][4];
    float minimum[3];
    float maximum[3];
    int sx = 1, sy = 1, sz = 1;
    int iz, iy, ix, index;
    int i, j, k;
    float wx, wy, wz;
    float nx, ny, nz;
    float yz00, yz10, yz11, yz01;

    iz = (int)((point[0] - volume->x) / (float)volume->half_x);
    iy = (int)((point[1] - volume->y) / (float)volume->half_y);
    ix = (int)((point[2] - volume->z) / (float)volume->half_z);
    index = iz + iy * volume->size_x + ix * volume->size_x * volume->size_y;
    if (index < 0 || index >= volume->count) {
        fn_801F10BC(0, 0, 0);
        return -1;
    }

    minimum[0] = (float)(volume->nodes[index].x - volume->half_x / 2);
    minimum[1] = (float)(volume->nodes[index].y - volume->half_y / 2);
    minimum[2] = (float)(volume->nodes[index].z - volume->half_z / 2);
    maximum[0] = (float)(volume->nodes[index].x + volume->half_x / 2);
    maximum[1] = (float)(volume->nodes[index].y + volume->half_y / 2);
    maximum[2] = (float)(volume->nodes[index].z + volume->half_z / 2);
    if (lbl_8064CB48 != 0) {
        int mode = *(int*)&lbl_806513CC;
        fn_800EBF88(minimum, maximum, &mode, 0x40);
    }

    {
        wx = (point[0] - volume->nodes[index].x);
        wy = (point[1] - volume->nodes[index].y);
        wz = (point[2] - volume->nodes[index].z);
        if (wx < 0.0f) { wx = -wx; sx = -1; }
        if (wy < 0.0f) { wy = -wy; sy = -1; }
        if (wz < 0.0f) { wz = -wz; sz = -1; }
        wx /= volume->half_x;
        wy /= volume->half_y;
        wz /= volume->half_z;
        if (iz + sx >= volume->size_x || iz + sx < 0) { wx = 0.0f; sx = 0; }
        if (iy + sy >= volume->size_y || iy + sy < 0) { wy = 0.0f; sy = 0; }
        if (ix + sz >= volume->size_z || ix + sz < 0) { wz = 0.0f; sz = 0; }

        nx = 1.0f - wx;
        ny = 1.0f - wy;
        nz = 1.0f - wz;
        /* Retail rounds the Y/Z product before multiplying by X. */
        yz11 = wy * wz;
        yz01 = ny * wz;
        yz10 = wy * nz;
        yz00 = ny * nz;
        sz *= volume->size_x * volume->size_y;
        sy *= volume->size_x;
        corners[0] = &volume->nodes[index];
        corner_weight[0] = nx*yz00;
        corners[1] = &volume->nodes[index + sx];
        corner_weight[1] = wx*yz00;
        corners[2] = &volume->nodes[index + sy];
        corner_weight[2] = nx*yz10;
        corners[3] = &volume->nodes[index + sy + sx];
        corners[4] = &volume->nodes[index + sz];
        corners[5] = &volume->nodes[index + sz + sx];
        corners[6] = &volume->nodes[index + sz + sy];
        corners[7] = &volume->nodes[index + sz + sy + sx];
        corner_weight[3] = wx*yz10;
        corner_weight[4] = nx*yz01;
        corner_weight[5] = wx*yz01;
        corner_weight[6] = nx*yz11;
        corner_weight[7] = wx*yz11;
    }

    fn_801F2170(mapping, corners, count);

    for (i = 0; i < count; i++) {
        for (j = 0; j < 3; j++) {
            output[i].position[j] = 0.0f;
            /* GC/1.3 unrolls the eight-corner accumulation. */
            for (k = 0; k < 8; k++) {
                output[i].position[j] += corner_weight[k] * corners[k]->samples[i].position[j];
            }
        }
        output[i].b = output[i].g = output[i].r = 0;
        output[i].a = 255;
        output[i].value = 0;
        for (j = 0; j < 8; j++) {
            output[i].r = (u8)(int)(output[i].r + corner_weight[j] * corners[j]->samples[i].r);
            output[i].g = (u8)(int)(output[i].g + corner_weight[j] * corners[j]->samples[i].g);
            output[i].b = (u8)(int)(output[i].b + corner_weight[j] * corners[j]->samples[i].b);
            output[i].a = (u8)(int)(output[i].a + corner_weight[j] * corners[j]->samples[i].a);
            output[i].value = (int)(output[i].value + corner_weight[j] * corners[j]->samples[i].value);
        }
        if (lbl_8064D18C == 0x124) output[i].value *= 8;
        else output[i].value = output[i].value > 30000 ? 30000 : output[i].value;
    }
    return index;
}
