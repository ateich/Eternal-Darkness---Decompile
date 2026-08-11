typedef unsigned char u8;
typedef int s32;

extern void fn_800B18F8(void);
extern u8 fn_80045230(void);
extern void fn_800238BC(int);
extern void fn_800B177C(int, void*);
extern void fn_800B689C(s32, s32);
extern void fn_800B2548(int, int);
extern void fn_80020D90(int);
extern void fn_8001DE68(void);

void fn_80023800(int mode)
{
    fn_800B18F8();
    if (mode == 1) {
        if (fn_80045230()) {
            fn_800B177C(3, fn_800238BC);
            fn_800B689C(1, 1);
            fn_800B2548(0x23, 0);
        } else {
            fn_80020D90(0);
        }
    } else {
        fn_8001DE68();
    }
}
