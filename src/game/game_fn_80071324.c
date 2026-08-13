extern char lbl_80312878[16];
extern void fn_80071364(void *);
extern void *memcpy(void *, const void *, unsigned int);

int fn_80071324(const void *in)
{
    memcpy(lbl_80312878, in, 16);
    fn_80071364(lbl_80312878);
    return 0x20;
}
