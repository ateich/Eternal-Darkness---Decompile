extern unsigned char lbl_80327E88[];
extern unsigned char lbl_80327CD8[];
extern void fn_80224DC0(void *);
extern void fn_80225878(int, void *);

void fn_800EC6C4(void)
{
    fn_80224DC0(lbl_80327E88);
    fn_80225878(3, lbl_80327CD8);
}
