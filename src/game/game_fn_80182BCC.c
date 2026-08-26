typedef unsigned char u8;
typedef unsigned int u32;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];

extern u8* fn_8018038C(void*, void*);
extern void fn_80182C68(u8*, void*, void*, void*);
extern void fn_80182E64(u8*, void*);
extern void fn_80182E90(void);
extern void fn_8018A88C(void);

u8* fn_80182BCC(void* arg0, void* arg1, void* arg2)
{
    u8* result = fn_8018038C(lbl_8064D238, lbl_80606334);

    if (result != 0) {
        fn_80182C68(result, arg0, arg1, arg2);
        fn_80182E64(result, arg2);
        *(void (**)(void))(result + 0x14C) = fn_80182E90;
        *(void (**)(void))(result + 0x148) = fn_8018A88C;
    }
    return result;
}
