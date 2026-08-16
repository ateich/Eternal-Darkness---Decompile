extern void *fn_80201BC8();
extern void *fn_80201B8C();
extern void fn_80038308(void *, int, void *);
extern void *memset(void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);

unsigned short fn_800B9C88(void *output, void *input)
{
    unsigned short values[4];

    fn_80201BC8(input);
    fn_80201B8C(input);
    memset(values, 0, sizeof(values));
    fn_80038308(input, 1, &values[0]);
    fn_80038308(input, 2, &values[1]);
    fn_80038308(input, 3, &values[2]);
    memcpy(output, values, sizeof(values));
    return sizeof(values);
}
