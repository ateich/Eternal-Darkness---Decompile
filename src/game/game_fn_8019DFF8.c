typedef unsigned char u8;
typedef unsigned short u16;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];
extern signed char lbl_8064D258;

extern u8* fn_8018038C(void*, void*);
extern void fn_8019E0B0(u8*, void*, void*, void*);
extern void fn_8019E580(u8*, void*);
extern void fn_8019E8C8(void);
extern void fn_8019ECA0(void);

u8* fn_8019DFF8(void* arg0, void* arg1, void* arg2)
{
    u8* result = 0;

    if (lbl_8064D258 == 0) {
        result = fn_8018038C(lbl_8064D238, lbl_80606334);
        if (result != 0) {
            fn_8019E0B0(result, arg0, arg1, arg2);
            fn_8019E580(result, arg2);
            lbl_8064D258 = 1;
            *(void (**)(void))(result + 0x14C) = fn_8019E8C8;
            *(void (**)(void))(result + 0x148) = fn_8019ECA0;
            *(u16*)(result + 0x22) = 4;
        }
    }
    return result;
}
