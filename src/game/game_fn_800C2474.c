typedef unsigned int u32;

typedef struct Vec4 {
    u32 word[4];
} Vec4;

extern float lbl_8064F198;

extern void fn_8012CEA4(void *, int, Vec4 *);
extern void fn_8012CF08(void *, int, Vec4, Vec4, int, int, float);
extern void fn_8017A630(Vec4 *);

void fn_800C2474(void *object, int index)
{
    Vec4 identity;
    Vec4 current;

    fn_8017A630(&identity);
    fn_8012CEA4(object, index, &current);
    fn_8012CF08(object, index, current, identity, 0, 0, lbl_8064F198);
}
