typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

extern void fn_8017A694(const Vec4*, const Vec4*, Vec4*);
extern void fn_8017A6D8(const Vec4*, const Vec4*, Vec4*);
extern float fn_8017A65C(const Vec4*);

int fn_8017A750(const Vec4* left, const Vec4* right)
{
    Vec4 difference;
    Vec4 sum;
    int result = 0;
    float difference_length;

    fn_8017A694(left, right, &difference);
    fn_8017A6D8(left, right, &sum);
    difference_length = fn_8017A65C(&difference);
    if (fn_8017A65C(&sum) < difference_length) {
        result = 1;
    }
    return result;
}
