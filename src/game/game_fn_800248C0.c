typedef unsigned int u32;

extern char lbl_8023DD9C[];

extern u32 fn_8017CC28(void);
extern u32 fn_8017CC30(void);
extern void fn_8017CC38(void*, u32, u32, void*, u32, u32);
extern void* fn_801FEA8C(u32, u32, const char*, u32);

void fn_800248C0(void)
{
    register u32 second_count;
    register void* second;
    register void* first;

    first = fn_801FEA8C(fn_8017CC28() * 2000, 1, lbl_8023DD9C, 204);
    second = fn_801FEA8C(fn_8017CC30() * 6000, 1, lbl_8023DD9C, 205);
    second_count = fn_8017CC30();
    fn_8017CC38(first, fn_8017CC28(), 2000, second, second_count, 6000);
}
