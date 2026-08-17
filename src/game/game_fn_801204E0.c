extern int fn_80120558(void* object, unsigned value);
extern unsigned lbl_806500B8;
extern unsigned lbl_806500BC;

int fn_801204E0(void* object)
{
    unsigned values[2];
    unsigned i = 0;
    int result = (int)object;

    values[0] = lbl_806500B8;
    values[1] = lbl_806500BC;
    while (i < 2 && result != 0) {
        result = fn_80120558(object, values[i]);
        i++;
    }
    return result;
}
