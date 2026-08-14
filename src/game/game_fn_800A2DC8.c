extern int fn_800A2060(void);
extern void fn_800A2ED8(void*, int);

void fn_800A2DC8(void* object)
{
    fn_800A2ED8(object, fn_800A2060());
}
