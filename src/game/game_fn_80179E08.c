extern float fn_80179B58(short*, float*);

void fn_80179E08(float* destination, short* source)
{
    fn_80179B58(source, destination);
    fn_80179B58(source + 1, destination + 1);
    fn_80179B58(source + 2, destination + 2);
}
