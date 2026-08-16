typedef unsigned char u8;

extern void *fn_800A1D28(void);
extern void *fn_8011F130(void *);
extern int fn_800A4DD4(void *, void *, int, int);

int fn_800DA400(void *context, void *object, int value)
{
    int result = 0;

    if ((signed char)((u8 *)fn_800A1D28())[0x25C] == 0) {
        result = fn_800A4DD4(context, fn_8011F130(object), value, 0x78);
    }
    return result;
}
