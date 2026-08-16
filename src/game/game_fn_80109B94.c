typedef unsigned int u32;

extern volatile int lbl_8064CDA8;
extern volatile int lbl_8064CDA0;
extern void* lbl_8064CD8C;
extern void* lbl_8064CD88;
extern void* lbl_8064CDC0;
extern void* lbl_8064CCA0;
extern void* lbl_8064CDB4;
extern void* lbl_8064CDB0;
extern void* lbl_8064C508;
extern unsigned char lbl_8024B270[];
extern void fn_80109EEC(void);
extern void fn_80109C5C(void);
extern void* fn_80144628(int, void*, int);
extern void* fn_801E8A8C(void);
extern void* fn_801E6CA0(void*, int, int, int, int);
extern void fn_801E8AEC(void*, int, int, int);
extern void fn_801E8B24(void*, int, int);

void fn_80109B94(void)
{
    while (lbl_8064CDA8 == 0 || lbl_8064CDA0 == 0) {}
    lbl_8064CD8C = fn_80109EEC;
    lbl_8064CD88 = fn_80109C5C;
    lbl_8064CDC0 = fn_80144628(5, lbl_8024B270, 0);
    lbl_8064CCA0 = fn_801E8A8C();
    lbl_8064CDB4 = fn_801E6CA0(lbl_8064C508, 1, 2, 0, 1);
    lbl_8064CDB0 = fn_801E6CA0(lbl_8064C508, 1, 9, 0, 1);
    fn_801E8AEC(lbl_8064CCA0, 0, 3, 3);
    fn_801E8B24(lbl_8064CCA0, 0, 0);
}
