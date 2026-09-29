typedef unsigned char u8;
typedef signed short s16;

extern u8 lbl_80607840[];
extern u8 lbl_8063C0C8[];
extern void fn_80212154(void*, void*);
extern void fn_801A2AB4(void*, void*, void*, int);
extern int fn_8018D1F0(u8, int);

void fn_8018A574(u8* transform, u8* object, void* context, s16* output)
{
    s16 matrix[24];
    int count;
    u8* current;
    u8* entry;
    int i;
    s16* dims;

    entry = *(u8**)(object + 0x4C);
    count = object[1];
    current = entry;
    fn_80212154(transform + 0x78, matrix);
    fn_801A2AB4(matrix, context, lbl_80607840, count);
    dims = (s16*)lbl_80607840;

    for (i = 0; i < count; i++) {
        *(s16*)(current + 0xA) = (dims[0] += *(s16*)(object + 0x10));
        *(s16*)(current + 0xC) = (dims[1] += *(s16*)(object + 0x12));
        *(s16*)(current + 0xE) = dims[2];
        dims += 3;
        current += 0x38;
    }

    dims = (s16*)lbl_80607840;
    fn_801A2AB4(lbl_8063C0C8, dims, dims, count);
    {
    u8 radius_value = entry[0x21];
    for (i = 0; i < count; i++) {
        int z;
        int y0;
        int y1;
        int x1;
        int x;
        int x0;
        int raw_radius;
        int y;
        int radius;

        raw_radius = fn_8018D1F0(radius_value, dims[2]);
        radius = raw_radius >> 1;

        if (radius == 0) {
            radius = 1;
        }
        x = dims[0];
        y = dims[1];
        z = dims[2];
        x0 = x - radius;
        x1 = x + radius;
        y0 = y - radius;
        y1 = y + radius;
        output[0] = x0;
        output[1] = y1;
        output[2] = z;
        output[3] = x1;
        output[4] = y1;
        output[5] = z;
        output[6] = x1;
        output[7] = y0;
        output[8] = z;
        output[9] = x0;
        output[10] = y0;
        output[11] = z;
        dims += 3;
        output += 12;
    }
    }
}
