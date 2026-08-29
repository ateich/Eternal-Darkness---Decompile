typedef unsigned char u8;
typedef unsigned int u32;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];

extern void* fn_8018038C(void* manager, void* data);
extern void fn_801A00B8(void* object, void* arg1, void* arg2, void* descriptor);
extern void fn_801A0268(void* object, void* descriptor);
extern void fn_801A0284(void);
extern u8 fn_8018AA30[];
extern u8 fn_8018A88C[];

void* fn_801A0008(void* arg1, void* arg2, void* descriptor)
{
    void* object;
    u32 callback;

    object = fn_8018038C(lbl_8064D238, lbl_80606334);
    if (object != 0) {
        fn_801A00B8(object, arg1, arg2, descriptor);
        fn_801A0268(object, descriptor);
        *(void (**)(void))((u8*)object + 0x14C) = fn_801A0284;
        callback = *((u8*)descriptor + 0x21) != 0
                       ? (u32)fn_8018A88C
                       : (u32)fn_8018AA30;
        *(u32*)((u8*)object + 0x148) = callback;
    }
    return object;
}
