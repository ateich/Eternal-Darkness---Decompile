typedef unsigned short u16;
typedef unsigned char u8;

extern u8 lbl_80606334[];
extern void* lbl_8064D238;
extern void* fn_8018038C(void*, void*);
extern void fn_80199598(void*, void*, void*, void*);
extern void fn_801997E8(void*, void*);
extern void fn_80199868(void);
extern void fn_80199ABC(void);
extern void fn_8018AD14(void);

void* fn_8019901C(void* first, void* second, u8* third)
{
    u8* result = fn_8018038C(lbl_8064D238, lbl_80606334);

    if (result != 0) {
        fn_80199598(result, first, second, third);
        fn_801997E8(result, third);
        if (third[0x15] < third[0]) {
            *(void (**)(void))(result + 0x14c) = fn_80199868;
        } else {
            *(void (**)(void))(result + 0x14c) = fn_80199ABC;
        }
        *(void (**)(void))(result + 0x148) = fn_8018AD14;
        *(u16*)(result + 0x22) = 4;
    }
    return result;
}
