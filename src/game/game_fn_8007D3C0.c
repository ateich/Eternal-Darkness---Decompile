typedef unsigned char u8;
typedef struct Vec3 Vec3;

extern int lbl_8064C8D8;
extern float lbl_8064E988;
extern float lbl_8064E9D0;
extern float lbl_8064E9EC;
extern float lbl_8064E9F0;
extern float lbl_8064E9F4;
extern float lbl_8064E9F8;

extern void fn_8007D294(const Vec3 *);
extern void fn_8007D2B4(Vec3 *, float, float, float, int, u8);

void fn_8007D3C0(Vec3 *position)
{
    fn_8007D294(position);
    lbl_8064C8D8 = 0;
    fn_8007D2B4(position, lbl_8064E9EC, lbl_8064E988, lbl_8064E9D0, 0, 0xFF);
    fn_8007D2B4(position, lbl_8064E9D0, lbl_8064E988, lbl_8064E9D0, 1, 0xFF);
    fn_8007D2B4(position, lbl_8064E9EC, lbl_8064E988, lbl_8064E9EC, 2, 0xFF);
    fn_8007D2B4(position, lbl_8064E9D0, lbl_8064E988, lbl_8064E9EC, 3, 0xFF);
    fn_8007D2B4(position, lbl_8064E9F0, lbl_8064E9F4, lbl_8064E9F8, 4, 0xFF);
    fn_8007D2B4(position, lbl_8064E9F8, lbl_8064E9F4, lbl_8064E9F8, 5, 0xFF);
    fn_8007D2B4(position, lbl_8064E9F0, lbl_8064E9F4, lbl_8064E9F0, 6, 0xFF);
    fn_8007D2B4(position, lbl_8064E9F8, lbl_8064E9F4, lbl_8064E9F0, 7, 0xFF);
}
