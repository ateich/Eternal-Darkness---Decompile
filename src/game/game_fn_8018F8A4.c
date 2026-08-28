typedef unsigned char u8;
typedef unsigned short u16;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];

extern u8* fn_8018038C(void*, void*);
extern void fn_8018F948(u8*, void*, void*, void*);
extern void fn_8018FAC8(u8*, void*);
extern void fn_8018FB74(void);
extern void fn_8018FC6C(void);

u8* fn_8018F8A4(void* arg0, void* arg1, void* arg2)
{
    u8* result = fn_8018038C(lbl_8064D238, lbl_80606334);

    if (result != 0) {
        fn_8018F948(result, arg0, arg1, arg2);
        fn_8018FAC8(result, arg2);
        *(void (**)(void))(result + 0x14C) = fn_8018FB74;
        *(void (**)(void))(result + 0x148) = fn_8018FC6C;
        *(u16*)(result + 0x22) = 4;
    }

    return result;
}
