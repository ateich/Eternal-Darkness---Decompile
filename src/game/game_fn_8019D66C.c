typedef unsigned char u8;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];

extern u8* fn_8018038C(void*, void*);
extern void fn_80180374(void*, int);
extern void fn_8019D714(u8*, void*, void*, void*);
extern void fn_8019D92C(u8*, void*);
extern void fn_8019DA3C(void);
extern void fn_8019D50C(void);

u8* fn_8019D66C(void* arg0, void* arg1, void* arg2)
{
    u8* result = fn_8018038C(lbl_8064D238, lbl_80606334);

    if (result != 0) {
        fn_8019D714(result, arg0, arg1, arg2);
        fn_80180374(result, 0x40);
        fn_8019D92C(result, arg2);
        *(void (**)(void))(result + 0x14C) = fn_8019DA3C;
        *(void (**)(void))(result + 0x148) = fn_8019D50C;
    }
    return result;
}
