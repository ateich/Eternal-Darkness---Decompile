typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];
extern float lbl_806509B8;

extern void* fn_8018038C(void*, void*);
extern void fn_80182514(void*, void*, void*, u8*);
extern void fn_80182798(void*, u8*);
extern void fn_80182984(void);
extern void fn_8018A88C(void);
extern void fn_8018ABD4(void);

void* fn_80182448(void* arg0, void* arg1, u8* descriptor)
{
    u8* result;
    u8* localDescriptor = descriptor;
    void* localArg1 = arg1;
    void* localArg0 = arg0;

    result = fn_8018038C(lbl_8064D238, lbl_80606334);
    if (result != 0) {
        fn_80182514(result, localArg0, localArg1, localDescriptor);
        fn_80182798(result, localDescriptor + 0x14);
        result[0xC0] = localDescriptor[1];
        *(void (**)(void))(result + 0x14C) = fn_80182984;
        if (lbl_806509B8 == *(float*)(localDescriptor + 0x28)) {
            *(void (**)(void))(result + 0x148) = fn_8018A88C;
        } else {
            *(void (**)(void))(result + 0x148) = fn_8018ABD4;
        }
        *(u16*)(result + 0x22) = 4;
    }
    return result;
}
