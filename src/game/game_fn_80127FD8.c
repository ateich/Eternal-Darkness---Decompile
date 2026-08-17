typedef unsigned char u8;
typedef float Matrix34[3][4];

extern void fn_80127DF8(void*, int, Matrix34);
extern void fn_80210FB0(Matrix34);
extern void fn_80211484(Matrix34, float, float, float);
extern void fn_802114E0(Matrix34, const Matrix34);
extern void fn_80210FDC(const Matrix34, const Matrix34, Matrix34);

void fn_80127FD8(void* entry, int index, Matrix34 output)
{
    Matrix34 transform;
    Matrix34 local;

    fn_80127DF8(entry, index, output);
    fn_80210FB0(transform);
    fn_80211484(transform, *(float*)((u8*)entry + 0),
                 *(float*)((u8*)entry + 4), *(float*)((u8*)entry + 8));
    fn_802114E0(local, (const float (*)[4])((u8*)entry + 0x2C));
    fn_80210FDC(transform, local, transform);
    fn_80210FDC(transform, output, output);
}
