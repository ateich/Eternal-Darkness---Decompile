typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];
extern u8* fn_8018038C(void*, void*);
extern void fn_8019BDE8(u8*, void*, void*, void*);
extern void fn_8019BFA0(u8*, void*);
extern void fn_8019C06C(void);
extern void fn_8019C3B8(void);

u8* fn_8019BC48(void* arg0, void* arg1, void* arg2)
{
    u8* result = fn_8018038C(lbl_8064D238, lbl_80606334);

    if (result != 0) {
        fn_8019BDE8(result, arg0, arg1, arg2);
        fn_8019BFA0(result, arg2);
        *(u32*)(result + 0x14C) = (u32)fn_8019C06C;
        *(u32*)(result + 0x148) = (u32)fn_8019C3B8;
        *(u16*)(result + 0x22) = 4;
    }
    return result;
}
