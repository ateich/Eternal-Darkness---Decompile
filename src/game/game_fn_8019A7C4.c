typedef unsigned char u8;
typedef unsigned short u16;

extern void* lbl_8064D238;
extern char lbl_80606334[];
extern void* fn_8018038C(void*, char*);
extern void fn_8019A8C4(void*, void*, void*, void*);
extern void fn_8019AAB4(void*, void*);
extern void fn_8019AAF0(void);
extern void fn_8018AD14(void);

void* fn_8019A7C4(void* first, void* second, void* third)
{
    u8* result;

    result = fn_8018038C(lbl_8064D238, lbl_80606334);
    if (result != 0) {
        fn_8019A8C4(result, first, second, third);
        fn_8019AAB4(result, third);
        *(void (**)(void))(result + 0x14c) = fn_8019AAF0;
        *(void (**)(void))(result + 0x148) = fn_8018AD14;
        *(u16*)(result + 0x22) = 4;
    }
    return result;
}
