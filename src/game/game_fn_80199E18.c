typedef unsigned char u8;
typedef unsigned short u16;

extern void* lbl_8064D238;
extern char lbl_80606334[];
extern void* fn_8018038C(void*, const char*);
extern void fn_80199F10(void*, void*, void*, void*);
extern void fn_8019A0DC(void*, void*);
extern void fn_8019A150(void);
extern void fn_8018A88C(void);

void* fn_80199E18(void* first, void* second, void* third)
{
    u8* result = fn_8018038C(lbl_8064D238, lbl_80606334);

    if (result != 0) {
        fn_80199F10(result, first, second, third);
        fn_8019A0DC(result, third);
        *(void (**)(void))(result + 0x14c) = fn_8019A150;
        *(void (**)(void))(result + 0x148) = fn_8018A88C;
        *(u16*)(result + 0x22) = 4;
    }
    return result;
}
