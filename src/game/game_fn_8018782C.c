typedef unsigned char u8;
typedef unsigned short u16;

extern u8 lbl_80606348[];
extern void* lbl_8064D238;
extern void* fn_8018038C(void* heap, void* type);
extern void fn_80187A4C(void* object, void* arg0, void* arg1, void* arg2);
extern void fn_80187BB4(void* object, void* arg2);
extern void fn_80187DF4(void);
extern void fn_80189E7C(void);

void* fn_8018782C(void* arg0, void* arg1, void* arg2)
{
    void* object = fn_8018038C(lbl_8064D238, lbl_80606348);
    if (object != 0) {
        fn_80187A4C(object, arg0, arg1, arg2);
        fn_80187BB4(object, arg2);
        *(void (**)(void))((u8*)object + 0x14C) = fn_80187DF4;
        *(void (**)(void))((u8*)object + 0x148) = fn_80189E7C;
        *(u16*)((u8*)object + 0x22) = 4;
    }
    return object;
}
