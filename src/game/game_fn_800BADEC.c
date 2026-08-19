extern void *fn_80201BC8();
extern void *fn_80201B8C();
extern void *memcpy(void *, const void *, unsigned int);
extern int fn_800389E0(void *, int, signed short, int);

unsigned short fn_800BADEC(void *input, void *object)
{
    signed short values[4];

    fn_80201BC8(object);
    fn_80201B8C(object);
    memcpy(values, input, sizeof(values));
    fn_800389E0(object, 1, values[0], 0);
    fn_800389E0(object, 2, values[1], 0);
    fn_800389E0(object, 3, values[2], 0);
    return sizeof(values);
}
