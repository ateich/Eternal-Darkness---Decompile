typedef unsigned int u32;

#pragma use_lmw_stmw on

extern void* lbl_8064C6E0;
extern u32 lbl_8064C6DC;
extern char lbl_8023DD9C[];

extern u32 fn_8015AA14(void);
extern u32 fn_800460FC(void);
extern u32 fn_80138E58(void);
extern u32 fn_8015885C(void);
extern u32 fn_801380EC(void);
extern void* fn_801FEA8C(u32, u32, const char*, u32);
extern void* memset(void*, int, u32);
extern void fn_8015ADD0(void*);
extern void fn_80138E64(void*);
extern void fn_80158868(void*);
extern void fn_801380F8(void*);

void fn_80024794(void)
{
    u32 size1;
    u32 count;
    u32 total;
    u32 size2;
    u32 size3;
    void* base;

    size1 = fn_8015AA14();
    count = fn_800460FC();
    size3 = ((size1 + 31) & ~31) * count;
    size2 = fn_80138E58();
    total = size3 + ((size2 + 31) & ~31);
    size3 = fn_8015885C();
    total += ((size3 + 31) & ~31) * count;
    total += (fn_801380EC() + 31) & ~31;

    if (lbl_8064C6E0 == 0) {
        lbl_8064C6DC = total;
        lbl_8064C6E0 = fn_801FEA8C(total, 1, lbl_8023DD9C, 0x79);
    }

    memset(lbl_8064C6E0, 0, total);
    base = lbl_8064C6E0;
    fn_8015ADD0(base);
    size1 = (u32)base + size1;
    fn_80138E64((void*)size1);
    size1 += size2;
    fn_80158868((void*)size1);
    size1 += size3;
    fn_801380F8((void*)size1);
}
