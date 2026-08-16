extern unsigned char lbl_80327E88[];
extern unsigned char lbl_80327CD8[];
extern void fn_80225460(void *);
extern void fn_80225ED8(int, void *);
extern void fn_802254D0(void);
extern void fn_80224A60(int, int);
extern void fn_8022551C(int, int, int, int, int);

void fn_800EC640(void)
{
    fn_80225460(lbl_80327E88);
    fn_80225ED8(3, lbl_80327CD8);
    fn_802254D0();
    fn_80224A60(9, 1);
    fn_80224A60(10, 1);
    fn_8022551C(3, 9, 1, 4, 0);
    fn_8022551C(3, 10, 0, 4, 0);
}
