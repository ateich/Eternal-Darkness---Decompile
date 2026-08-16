typedef unsigned int u32;

extern u32 lbl_8064CC88;
extern u32 lbl_8064CC8C;
extern unsigned char lbl_8032EA70[];
extern unsigned char lbl_80330A70[];
extern void fn_80106A6C(void);
extern void fn_801090D4(void);
extern void fn_8020F84C(void*, void*, void*, void*, u32, u32, u32);
extern void fn_8020FC0C(void*);

void fn_80109B24(void* state, u32 arg1, u32 arg2)
{
    lbl_8064CC88 = arg1;
    lbl_8064CC8C = arg2;
    fn_80106A6C();
    fn_8020F84C(lbl_80330A70, fn_801090D4, state,
                lbl_8032EA70 + 0x2000, 0x2000, 0x1F, 1);
    fn_8020FC0C(lbl_80330A70);
}
