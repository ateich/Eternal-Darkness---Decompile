typedef unsigned char u8;
typedef unsigned short u16;

extern void* lbl_8064D238;
extern char lbl_80606334[];
extern void* fn_8018038C(void*, char*);
extern void fn_8019A3E0(void*, void*, void*, void*);
extern void fn_8019A5C8(void*, void*);
extern void fn_8018A88C(void);
extern void fn_8019A5DC(void);

void* fn_8019A300(void* first, void* second, void* third)
{
    void* result;

    result = fn_8018038C(lbl_8064D238, lbl_80606334);
    if (result != 0) {
        fn_8019A3E0(result, first, second, third);
        fn_8019A5C8(result, third);
        *(void (**)(void))((u8*)result + 0x14c) = fn_8019A5DC;
        *(void (**)(void))((u8*)result + 0x148) = fn_8018A88C;
        *(u16*)((u8*)result + 0x22) = 4;
    }
    return result;
}
