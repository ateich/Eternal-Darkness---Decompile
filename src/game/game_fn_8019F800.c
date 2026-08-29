typedef unsigned char u8;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];

extern u8* fn_8018038C(void*, void*);
extern void fn_8019F8A8(u8*, void*, void*, void*);
extern void fn_8019FA94(u8*, void*);
extern void fn_80180374(u8*, int);
extern void fn_8019FAB8(void);
extern void fn_8019FCB4(void);

u8* fn_8019F800(void* arg0, void* arg1, void* arg2)
{
    u8* result = fn_8018038C(lbl_8064D238, lbl_80606334);

    if (result != 0) {
        fn_8019F8A8(result, arg0, arg1, arg2);
        fn_8019FA94(result, arg2);
        fn_80180374(result, 0xFF);
        *(void (**)(void))(result + 0x14C) = fn_8019FAB8;
        *(void (**)(void))(result + 0x148) = fn_8019FCB4;
    }
    return result;
}
