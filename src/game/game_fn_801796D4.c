extern float fn_800ED720(float);

float fn_801796D4(float first_x, float first_y, float first_z,
                  float second_x, float second_y, float second_z)
{
    float x = first_x - second_x;
    float y = first_y - second_y;
    float z = first_z - second_z;

    return fn_800ED720(x * x + y * y + z * z);
}
