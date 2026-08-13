extern char lbl_80312878[16];
extern void fn_800714CC(void *);
extern void *memcpy(void *, const void *, unsigned int);

int fn_800712D8(void *out)
{
    fn_800714CC(lbl_80312878);
    memcpy(out, lbl_80312878, 16);
    return 0x20;
}
