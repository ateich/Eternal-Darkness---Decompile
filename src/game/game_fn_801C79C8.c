typedef unsigned char u8;
typedef unsigned int u32;

extern float lbl_80252F2C[];
extern float lbl_80253148[];
extern const float lbl_80650F88;
extern const float lbl_80650F90;
extern const float lbl_80650FA0;
extern const float lbl_80650FA4;
extern const float lbl_80650FA8;
extern const float lbl_80650FAC;
extern float fn_800F6318(float);
extern float fn_800F6264(float);
extern u32 fn_800F5C54(float);

static inline float wrap_unit(float value)
{
    float one = 1.0f;
    /* Keep the multiply and subtract as separate float expressions. */
    float product;
    if (__fabs(one) > __fabs(value)) return value;
    product = one * fn_800F6264(fn_800F6318(value / one));
    return value - product;
}

void fn_801C79C8(u8 table_kind, float* output, u32 packed_min, u32 packed_max,
                 float x, float y, float z, u32 bias_x, u32 alternate_layout)
{
    float* table;
    float* fixed = lbl_80253148;
    float a, b, af, bf, caf, cbf, old_af, old_caf, ca, cb;
    u32 ai, bi, cai, cbi, old_ai, old_cai;
    float wb, wc, first, second;
    float scaled_x, fraction_x, sample_x;
    u32 index_x;
    float scaled_y, fraction_y, sample_y;
    u32 index_y;
    float scaled_z, fraction_z, sample_z;
    u32 index_z;
    float scaled_alternate_x, fraction_alternate_x, sample_alternate_x;
    u32 index_alternate_x;
    float scaled_alternate_y, fraction_alternate_y, sample_alternate_y;
    u32 index_alternate_y;

    table = table_kind == 0 ? fixed : lbl_80252F2C;
    /* The packed sentinel is 0x00800000, not the sign bit. */
    if (packed_min == 0x00800000) {
        packed_min = 0;
        packed_max = 0x007F0000;
    }
    packed_min = packed_min <= 0x10000 ? 0 : packed_min - 0x10000;
    packed_max = packed_max <= 0x10000 ? 0 : packed_max - 0x10000;
    a = lbl_80650FA0 * packed_min;
    b = lbl_80650FA0 * packed_max;

    if (alternate_layout != 0) {
        old_af = wrap_unit(a);
        old_ai = fn_800F5C54(a);
        ca = lbl_80650FA4 - a;
        old_caf = wrap_unit(ca);
        old_cai = fn_800F5C54(ca);
    }
    if (bias_x != 0) {
        first = lbl_80650FA8 * (a - 1.0f);
        a = 1.0f + first;
    }
    af = wrap_unit(a);
    ai = fn_800F5C54(a);
    bf = wrap_unit(b);
    bi = fn_800F5C54(b);
    ca = lbl_80650FA4 - a;
    cb = lbl_80650FA4 - b;
    caf = wrap_unit(ca);
    cai = fn_800F5C54(ca);
    cbf = wrap_unit(cb);
    cbi = fn_800F5C54(cb);

    /* Output stores may alias the tables: reload bands between rows. */
    if (alternate_layout == 0) {
        float* next_band;

        scaled_x = lbl_80650F88 * x;
        index_x = fn_800F5C54(scaled_x);
        next_band = fixed + 130;
        fraction_x = scaled_x - index_x;
        first = (1.0f - fraction_x) * table[index_x];
        second = fraction_x * table[index_x + 1];
        sample_x = first + second;
        first = (1.0f - bf) * fixed[bi + 129];
        second = bf * next_band[bi];
        wc = first + second;
        output[2] = lbl_80650F90 * (sample_x * wc);
        first = (1.0f - cbf) * fixed[cbi + 129];
        second = cbf * next_band[cbi];
        wc = first + second;
        sample_x = sample_x * wc;
        first = (1.0f - af) * fixed[ai + 129];
        second = af * next_band[ai];
        wc = first + second;
        output[1] = sample_x * wc;
        first = (1.0f - caf) * fixed[cai + 129];
        second = caf * next_band[cai];
        wc = first + second;
        output[0] = sample_x * wc;

        scaled_y = lbl_80650F88 * y;
        index_y = fn_800F5C54(scaled_y);
        fraction_y = scaled_y - index_y;
        first = (1.0f - fraction_y) * table[index_y];
        second = fraction_y * table[index_y + 1];
        sample_y = first + second;
        first = (1.0f - bf) * fixed[bi + 129];
        second = bf * next_band[bi];
        wc = first + second;
        output[5] = lbl_80650F90 * (sample_y * wc);
        first = (1.0f - cbf) * fixed[cbi + 129];
        second = cbf * next_band[cbi];
        wc = first + second;
        sample_y = sample_y * wc;
        first = (1.0f - af) * fixed[ai + 129];
        second = af * next_band[ai];
        wc = first + second;
        output[4] = sample_y * wc;
        first = (1.0f - caf) * fixed[cai + 129];
        second = caf * next_band[cai];
        wc = first + second;
        output[3] = sample_y * wc;

        scaled_z = lbl_80650F88 * z;
        index_z = fn_800F5C54(scaled_z);
        fraction_z = scaled_z - index_z;
        first = (1.0f - fraction_z) * table[index_z];
        second = fraction_z * table[index_z + 1];
        sample_z = first + second;
        first = (1.0f - bf) * fixed[bi + 129];
        second = bf * next_band[bi];
        wc = first + second;
        output[8] = lbl_80650F90 * (sample_z * wc);
        first = (1.0f - cbf) * fixed[cbi + 129];
        second = cbf * next_band[cbi];
        wc = first + second;
        sample_z = sample_z * wc;
        first = (1.0f - af) * fixed[ai + 129];
        second = af * next_band[ai];
        wc = first + second;
        output[7] = sample_z * wc;
        first = (1.0f - caf) * fixed[cai + 129];
        second = caf * next_band[cai];
        wc = first + second;
        output[6] = sample_z * wc;
    } else {
        float* next_band;
        scaled_alternate_x = lbl_80650F88 * x;
        index_alternate_x = fn_800F5C54(scaled_alternate_x);
        next_band = fixed + 130;
        fraction_alternate_x = scaled_alternate_x - index_alternate_x;
        first = (1.0f - fraction_alternate_x) * table[index_alternate_x];
        second = fraction_alternate_x * table[index_alternate_x + 1];
        sample_alternate_x = first + second;
        first = (1.0f - bf) * fixed[bi + 129];
        second = bf * next_band[bi];
        wc = first + second;
        wb = sample_alternate_x * wc;
        first = (1.0f - cbf) * fixed[cbi + 129];
        second = cbf * next_band[cbi];
        wc = first + second;
        sample_alternate_x = sample_alternate_x * wc;
        first = (1.0f - af) * fixed[ai + 129];
        second = af * next_band[ai];
        wc = first + second;
        output[1] = sample_alternate_x * wc;
        first = (1.0f - caf) * fixed[cai + 129];
        second = caf * next_band[cai];
        wc = first + second;
        output[0] = sample_alternate_x * wc;
        /* This layout uses the first sample for both outer channel pairs.
         * Its old-phase lower tap is at +0x214; the upper tap is +0x208. */
        first = (1.0f - old_af) * fixed[old_ai + 133];
        second = old_af * next_band[old_ai];
        output[7] = wb * (first + second);
        first = (1.0f - old_caf) * fixed[old_cai + 133];
        second = old_caf * next_band[old_cai];
        output[6] = wb * (first + second);

        scaled_alternate_y = lbl_80650F88 * y;
        index_alternate_y = fn_800F5C54(scaled_alternate_y);
        fraction_alternate_y = scaled_alternate_y - index_alternate_y;
        first = (1.0f - fraction_alternate_y) * table[index_alternate_y];
        second = fraction_alternate_y * table[index_alternate_y + 1];
        sample_alternate_y = first + second;
        first = (1.0f - bf) * fixed[bi + 129];
        second = bf * next_band[bi];
        wc = first + second;
        output[5] = lbl_80650F90 * (sample_alternate_y * wc);
        first = (1.0f - cbf) * fixed[cbi + 129];
        second = cbf * next_band[cbi];
        wc = first + second;
        sample_alternate_y = sample_alternate_y * wc;
        first = (1.0f - af) * fixed[ai + 129];
        second = af * next_band[ai];
        wc = first + second;
        output[4] = sample_alternate_y * wc;
        first = (1.0f - caf) * fixed[cai + 129];
        second = caf * next_band[cai];
        wc = first + second;
        output[3] = sample_alternate_y * wc;
        output[2] = lbl_80650FAC;
        output[8] = lbl_80650FAC;
    }
}
