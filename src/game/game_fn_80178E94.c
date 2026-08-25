extern void fn_80178F14(int, int, int, int, int, int);

void fn_80178E94(const float* first, const float* second)
{
    fn_80178F14((int)first[0], (int)first[1], (int)first[2],
                (int)second[0], (int)second[1], (int)second[2]);
}
