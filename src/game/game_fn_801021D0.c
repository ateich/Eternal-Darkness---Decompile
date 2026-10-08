typedef unsigned int u32;

extern int fn_80100080(double x, double *y);
extern double fn_80100420(double x, double y);
extern double fn_80101368(double x, double y, int tail);
extern const double lbl_8064FE48;

double fn_801021D0(double x)
{
    double y[2];
    int n;
    int ix;

    ix = *(u32 *)&x & 0x7fffffff;
    if (ix <= 0x3fe921fb) {
        return fn_80101368(x, lbl_8064FE48, 0);
    }
    if (ix >= 0x7ff00000) {
        return x - x;
    }
    n = fn_80100080(x, y);
    switch (n & 3) {
    case 0:
        return fn_80101368(y[0], y[1], 1);
    case 1:
        return fn_80100420(y[0], y[1]);
    case 2:
        return -fn_80101368(y[0], y[1], 1);
    default:
        return -fn_80100420(y[0], y[1]);
    }
}
