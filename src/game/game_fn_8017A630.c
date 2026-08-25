typedef struct Pair {
    float first;
    float second;
} Pair;

typedef struct Vec4 {
    Pair xy;
    Pair zw;
} Vec4;

extern Vec4 lbl_80250E90;

void fn_8017A630(Vec4* output)
{
    output->xy = lbl_80250E90.xy;
    output->zw = lbl_80250E90.zw;
}
