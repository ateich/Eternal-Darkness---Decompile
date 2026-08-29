typedef unsigned char u8;
typedef unsigned short u16;

extern void* lbl_8064D238;
extern char lbl_80606334[];
extern void* fn_8018038C(void*, char*);
extern void fn_8018BC68(void);
extern void fn_8019B1BC(void*, void*, void*, u8);
extern void fn_8019B6F0(void*, u8);
extern void fn_8019B9F4(void);

void* fn_8019AD40(void* first, void* second, u8 third)
{
    u8* result;

    result = fn_8018038C(lbl_8064D238, lbl_80606334);
    if (result != 0) {
        fn_8019B1BC(result, first, second, third);
        fn_8019B6F0(result, third);
        *(void (**)(void))(result + 0x14C) = fn_8019B9F4;
        *(void (**)(void))(result + 0x148) = fn_8018BC68;
        *(u16*)(result + 0x22) = 4;
    }
    return result;
}
