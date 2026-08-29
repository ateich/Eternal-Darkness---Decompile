typedef unsigned char u8;

extern u8 lbl_80606334[];
extern void* lbl_8064D238;

extern u8* fn_8018038C(void*, void*);
extern void fn_8018A88C(void);
extern void fn_8019F320(u8*, void*, void*, void*);
extern void fn_8019F508(u8*, void*);
extern void fn_8019F5AC(void);

u8* fn_8019F284(void* arg0, void* arg1, void* arg2)
{
    u8* result;

    result = fn_8018038C(lbl_8064D238, lbl_80606334);
    if (result != 0) {
        fn_8019F320(result, arg0, arg1, arg2);
        fn_8019F508(result, arg2);
        *(void (**)(void))(result + 0x14C) = fn_8019F5AC;
        *(void (**)(void))(result + 0x148) = fn_8018A88C;
    }
    return result;
}
