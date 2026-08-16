typedef unsigned int u32;

extern int fn_80035628(void *);

void fn_800CA660(void *object, u32 *flags)
{
    switch (fn_80035628(object)) {
    case 1:
        *flags |= 1;
        break;
    case 2:
        *flags |= 2;
        break;
    case 3:
        *flags |= 4;
        break;
    }
}
