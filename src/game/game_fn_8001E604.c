typedef unsigned char u8;

extern void* lbl_8064C658;
extern u8 lbl_8030241C[];

extern void fn_80144680(void*);

void fn_8001E604(void)
{
    if (lbl_8064C658 != 0) {
        fn_80144680(lbl_8064C658);
    }

    lbl_8064C658 = 0;
    *(void**)(lbl_8030241C + 0x10) = 0;
}
