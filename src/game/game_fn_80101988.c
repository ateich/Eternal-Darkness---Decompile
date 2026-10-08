/* Cosine, with argument reduction into a quadrant and kernel evaluation. */
extern int fn_80100080(double x, double *y);
extern double fn_80100420(double x, double y);
extern double fn_80101368(double x, double y, int tail);
extern const double lbl_8064FE00;

double fn_80101988(double x)
{
    double y[2];
    int quadrant;
    int magnitude;

    magnitude = *(unsigned int *)&x & 0x7fffffff;
    if (magnitude <= 0x3fe921fb) {
        return fn_80100420(x, lbl_8064FE00);
    }
    if (magnitude >= 0x7ff00000) {
        return x - x;
    }
    quadrant = fn_80100080(x, y);
    switch (quadrant & 3) {
    case 0:
        return fn_80100420(y[0], y[1]);
    case 1:
        return -fn_80101368(y[0], y[1], 1);
    case 2:
        return -fn_80100420(y[0], y[1]);
    default:
        return fn_80101368(y[0], y[1], 1);
    }
}
