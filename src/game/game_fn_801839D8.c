typedef unsigned char u8;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];

extern u8* fn_8018038C(void*, void*);
extern void fn_80183A68(u8*, void*, void*, void*);
extern void fn_80183C54(void);
extern void fn_8018A88C(void);

u8* fn_801839D8(void* arg0, void* arg1, void* arg2)
{
    u8* result;

    result = fn_8018038C(lbl_8064D238, lbl_80606334);
    if (result != 0) {
        fn_80183A68(result, arg0, arg1, arg2);
        *(void (**)(void))(result + 0x14C) = fn_80183C54;
        *(void (**)(void))(result + 0x148) = fn_8018A88C;
    }
    return result;
}
