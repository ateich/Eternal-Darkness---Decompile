extern void *fn_80201B9C();
extern void *fn_80204844(void *, int);
extern void *fn_8006D444(void);
extern int fn_80070AAC(void *);

int fn_80070A6C(int mask)
{
    int result;

    fn_80204844(fn_80201B9C(), 0x20);
    result = fn_80070AAC(fn_8006D444());
    result &= mask;
    return result;
}
