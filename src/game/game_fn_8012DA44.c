typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern void fn_8012BE18(const void*, Vec3*, int);
extern void fn_8012BDCC(Vec3*, void*, int);
extern int fn_8012D9D4(float*, const float*, float);

int fn_8012DA44(void* current, void* step, void* limit, int mode)
{
    Vec3 step_vec;
    Vec3 limit_vec;
    Vec3 current_vec;
    int x_complete;
    int y_complete;
    int z_complete;

    fn_8012BE18(current, &current_vec, mode);
    fn_8012BE18(step, &step_vec, mode);
    fn_8012BE18(limit, &limit_vec, mode);
    x_complete = fn_8012D9D4(&current_vec.x, &step_vec.x, limit_vec.x);
    y_complete = fn_8012D9D4(&current_vec.y, &step_vec.y, limit_vec.y);
    z_complete = fn_8012D9D4(&current_vec.z, &step_vec.z, limit_vec.z);
    x_complete = x_complete && y_complete && z_complete;
    fn_8012BDCC(&current_vec, current, mode);
    return x_complete;
}
