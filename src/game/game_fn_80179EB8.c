int fn_80179EB8(float* vector)
{
    float x = vector[0];
    float y;
    float z;
    float maximum;
    int axis;

    if (x < 0.0f) {
        x = -x;
    }
    y = vector[1];
    maximum = x;
    axis = 0;

    if (y < 0.0f) {
        y = -y;
    }
    if (y > maximum) {
        maximum = y;
        axis = 1;
    }

    z = vector[2];
    if (z < 0.0f) {
        z = -z;
    }
    if (z > maximum) {
        axis = 2;
    }
    return axis;
}
