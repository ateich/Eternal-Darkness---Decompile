typedef unsigned char u8;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];

extern void* fn_8018038C(void*, void*);
extern void fn_801820B0(void*, void*, void*, void*);
extern void fn_80182274(void*, void*);
extern void fn_80182290(void);
extern void fn_8018A88C(void);

void* fn_80182014(void* arg0, void* arg1, void* arg2)
{
    void* result;

    result = fn_8018038C(lbl_8064D238, lbl_80606334);
    if (result != 0) {
        fn_801820B0(result, arg0, arg1, arg2);
        fn_80182274(result, arg2);
        *(void (**)(void))((u8*)result + 0x14C) = fn_80182290;
        *(void (**)(void))((u8*)result + 0x148) = fn_8018A88C;
    }
    return result;
}
