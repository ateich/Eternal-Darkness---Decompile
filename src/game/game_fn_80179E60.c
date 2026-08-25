extern void fn_80179BB4(float*, short*);

void fn_80179E60(short* destination, float* source)
{
    fn_80179BB4(source, destination);
    fn_80179BB4(source + 1, destination + 1);
    fn_80179BB4(source + 2, destination + 2);
}
