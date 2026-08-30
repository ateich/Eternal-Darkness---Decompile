typedef unsigned char u8;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];
extern void* fn_8018038C(void*, void*);
extern void fn_801A329C(void*, void*, void*, void*);
extern void fn_801A1F18(void*, void*);
extern void fn_801A2540(void);
extern void fn_801A2FB4(void);

void* fn_801A3200(void* arg0, void* arg1, void* arg2)
{
    u8* result = fn_8018038C(lbl_8064D238, lbl_80606334);

    if (result != 0) {
        fn_801A329C(result, arg0, arg1, arg2);
        fn_801A1F18(result, arg2);
        *(void (**)(void))(result + 0x14C) = fn_801A2540;
        *(void (**)(void))(result + 0x148) = fn_801A2FB4;
    }
    return result;
}
