extern void (*lbl_8064CD88)(void);
extern void (*lbl_8064CD8C)(void);
extern void *lbl_8064CDC0;
extern unsigned char lbl_8024EB68[];

extern void fn_8011C1F8(void);
extern void fn_8011C4D8(void);
extern void *fn_80144628(int, void *, int);

void fn_8011C1AC(void)
{
    lbl_8064CD8C = fn_8011C4D8;
    lbl_8064CD88 = fn_8011C1F8;
    lbl_8064CDC0 = fn_80144628(5, lbl_8024EB68, 0);
}
