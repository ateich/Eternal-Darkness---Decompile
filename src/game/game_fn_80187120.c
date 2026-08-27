extern int fn_80179064(int x1, int y1, int x2, int y2);

void fn_80187120(int x1, int y1, int x2, int y2, float* x, float* y)
{
    int delta_y = -(y2 - y1);
    int delta_x = x2 - x1;
    int distance = fn_80179064(x1, y1, x2, y2);

    if (distance > 0) {
        *x = (float)delta_y / (float)distance;
        *y = (float)delta_x / (float)distance;
    } else {
        *x = 0.0f;
        *y = 0.0f;
    }
}
