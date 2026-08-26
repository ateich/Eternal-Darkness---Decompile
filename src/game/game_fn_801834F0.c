typedef unsigned char u8;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];

extern u8* fn_8018038C(void*, void*);
extern void fn_801835F4(u8*, void*, void*, void*);
extern void fn_801837AC(u8*, void*);
extern void fn_801837D8(void);
extern void fn_8018BFEC(void);

u8* fn_801834F0(void* arg0, void* arg1, void* arg2)
{
    u8* result;

    result = fn_8018038C(lbl_8064D238, lbl_80606334);
    if (result != 0) {
        fn_801835F4(result, arg0, arg1, arg2);
        fn_801837AC(result, arg2);
        *(void (**)(void))(result + 0x14C) = fn_801837D8;
        *(void (**)(void))(result + 0x148) = fn_8018BFEC;
    }
    return result;
}
