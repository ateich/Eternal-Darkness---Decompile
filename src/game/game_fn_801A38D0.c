typedef unsigned char u8;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];
extern void* fn_8018038C(void*, void*);
extern void fn_801A3A78(void*, void*, void*, void*);
extern void* memcpy(void*, const void*, unsigned long);
extern void fn_801A3D18(void*, void*);
extern void fn_801A3DF8(void);
extern void fn_8018ABD4(void);

void* fn_801A38D0(void* coordinate, void* descriptor, u8* owner)
{
    u8* result = *(u8**)(owner + 0xC);

    if (result == 0) {
        result = fn_8018038C(lbl_8064D238, lbl_80606334);
        if (result != 0) {
            fn_801A3A78(result, coordinate, descriptor, owner);
        }
    } else {
        memcpy(result + 0x10, coordinate, 6);
    }

    if (result != 0) {
        fn_801A3D18(result, owner);
        *(void (**)(void))(result + 0x14C) = fn_801A3DF8;
        *(void (**)(void))(result + 0x148) = fn_8018ABD4;
        *(unsigned short*)(result + 0x22) = 4;
    }
    return result;
}
