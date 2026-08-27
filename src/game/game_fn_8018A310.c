typedef unsigned char u8;
typedef signed short s16;

extern u8 lbl_80607840[];
extern u8 lbl_8063C0C8[];
extern void fn_801A2AB4(void*, void*, void*);
extern int fn_8018D1F0(u8, int);

void fn_8018A310(u8* entry, void* context, s16* out, int count)
{
    int i;
    s16* dims = (s16*)lbl_80607840;

    fn_801A2AB4(lbl_8063C0C8, context, dims);
    for (i = 0; i < count; i++) {
        int radius;
        int z;
        int y1;
        int x;
        int x0;
        int y;
        int x1;
        int y0;

        radius = fn_8018D1F0(entry[0x21], dims[2]);
        x = dims[0];
        y = dims[1];
        z = dims[2];
        x0 = x - radius;
        y1 = y + radius;
        x1 = x + radius;
        y0 = y - radius;

        out[0] = x0;
        out[1] = y1;
        out[2] = z;
        out[3] = x1;
        out[4] = y1;
        out[5] = z;
        out[6] = x1;
        out[7] = y0;
        out[8] = z;
        out[9] = x0;
        out[10] = y0;
        out[11] = z;
        entry += 0x38;
        dims += 3;
        out += 12;
    }
}
