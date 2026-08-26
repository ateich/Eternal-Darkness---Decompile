typedef unsigned char u8;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];

extern u8* fn_8018038C(void*, void*);
extern void fn_80183068(u8*, void*, void*, void*);
extern void fn_80183208(u8*, void*);
extern void fn_8018322C(void);
extern void fn_8018A88C(void);

u8* fn_80182FCC(void* arg0, void* arg1, void* arg2)
{
    u8* result = fn_8018038C(lbl_8064D238, lbl_80606334);

    if (result != 0) {
        fn_80183068(result, arg0, arg1, arg2);
        fn_80183208(result, arg2);
        *(void (**)(void))(result + 0x14C) = fn_8018322C;
        *(void (**)(void))(result + 0x148) = fn_8018A88C;
    }
    return result;
}
