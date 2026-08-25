extern int fn_80179064(int, int, int, int);

int fn_80179004(const float* first, const float* second)
{
    return fn_80179064((int)first[0], (int)first[1],
                       (int)second[0], (int)second[1]);
}
