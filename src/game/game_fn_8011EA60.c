extern const char lbl_8024EDC8[];
extern void* lbl_8064CEA8;
extern void* fn_801FEA8C(unsigned long, int, const char*, int);
extern void* fn_8017CCD8(void*, unsigned long, unsigned short);

void fn_8011EA60(unsigned short count)
{
    void* storage;

    storage = fn_801FEA8C(count * 736, 1, lbl_8024EDC8, 88);
    lbl_8064CEA8 = fn_8017CCD8(storage, 736, count);
}
