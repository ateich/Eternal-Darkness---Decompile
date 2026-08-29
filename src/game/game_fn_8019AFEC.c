typedef unsigned char u8;
typedef unsigned short u16;

extern void* lbl_8064D238;
extern char lbl_80606348[];
extern void* fn_8018038C(void*, char*);
extern void fn_8018B770(void);
extern void fn_8019B4D4(void*, void*, void*, u8);
extern void fn_8019B6F0(void*, u8);
extern void fn_8019B970(void);

void* fn_8019AFEC(void* first, void* second, u8 third)
{
    u8* result;

    result = fn_8018038C(lbl_8064D238, lbl_80606348);
    if (result != 0) {
        fn_8019B4D4(result, first, second, third);
        fn_8019B6F0(result, third);
        *(void (**)(void))(result + 0x14C) = fn_8019B970;
        *(void (**)(void))(result + 0x148) = fn_8018B770;
        *(u16*)(result + 0x22) = 4;
    }
    return result;
}
