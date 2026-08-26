extern unsigned int fn_80178F14(int, int, int, int, int, int);

unsigned int fn_80178E94(const float* first, const float* second)
{
    return fn_80178F14((int)first[0], (int)first[1], (int)first[2],
                       (int)second[0], (int)second[1], (int)second[2]);
}
