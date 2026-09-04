typedef unsigned char u8;
typedef unsigned int u32;

extern float lbl_80252F2C[];
extern float lbl_80253148[];
extern float fn_800F6318(float);
extern float fn_800F6264(float);
extern u32 fn_800F5C54(float);

static float wrap_unit(float value)
{
    float one = 1.0f;
    if (__fabs(value) < one) {
        return value;
    }
    return value - one * fn_800F6264(fn_800F6318(value / one));
}

/* Trilinear lookup used to construct two RGB triples.  The interpolation
 * arithmetic remains under reconstruction; keeping it in C preserves the
 * recovered interface, table selection, phase handling, and output shape. */
void fn_801C79C8(u8 table_kind, float* output, u32 packed_min, u32 packed_max,
                 float x, float y, float z, u8 bias_x, u8 alternate_layout)
{
    float* table;
    float sx;
    float sy;
    float tx;
    float ty;
    u32 ix;
    u32 iy;
    u32 ix1;
    u32 iy1;
    float fx;
    float fy;
    float fz;
    u32 iz;

    table = table_kind == 0 ? lbl_80253148 : lbl_80252F2C;
    if ((packed_min & 0xFF000000) == 0x80000000) {
        packed_min = 0;
        packed_max = 0x007F0000;
    }

    sx = ((packed_min <= 0x10000 ? 0 : packed_min - 0x10000) / 65536.0f) * (1.0f / 127.0f);
    sy = ((packed_max <= 0x10000 ? 0 : packed_max - 0x10000) / 65536.0f) * (1.0f / 127.0f);

    if (alternate_layout != 0) {
        tx = wrap_unit(sx);
        ix = fn_800F5C54(sx);
        ty = 1.0f - sx;
        fy = wrap_unit(ty);
        iy = fn_800F5C54(ty);
    }

    if (bias_x != 0) {
        sx = 1.0f + 0.5f * (sx - 1.0f);
    }
    fx = wrap_unit(sx);
    ix1 = fn_800F5C54(sx);
    fy = wrap_unit(sy);
    iy1 = fn_800F5C54(sy);
    tx = wrap_unit(1.0f - sx);
    ix = fn_800F5C54(1.0f - sx);
    ty = wrap_unit(1.0f - sy);
    iy = fn_800F5C54(1.0f - sy);

    fz = 127.0f * x;
    iz = fn_800F5C54(fz);
    output[0] = table[iz] * (1.0f - fx) + table[ix1] * fx;
    output[1] = table[iz + 1] * (1.0f - fy) + table[iy1] * fy;
    output[2] = table[ix] * tx + table[iy] * ty;

    fz = 127.0f * y;
    iz = fn_800F5C54(fz);
    output[3] = table[iz] * (1.0f - fx) + table[ix1] * fx;
    output[4] = table[iz + 1] * (1.0f - fy) + table[iy1] * fy;
    output[5] = table[ix] * tx + table[iy] * ty;

    fz = 127.0f * z;
    iz = fn_800F5C54(fz);
    output[6] = table[iz] * (1.0f - fx) + table[ix1] * fx;
    output[7] = table[iz + 1] * (1.0f - fy) + table[iy1] * fy;
    output[8] = table[ix] * tx + table[iy] * ty;
}
