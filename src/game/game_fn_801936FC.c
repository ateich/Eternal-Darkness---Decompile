typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];
extern u8 lbl_80607120[];
extern void* fn_8018038C(void*, void*);
extern void fn_8019475C(void*, void*, void*, void*);
extern void fn_801947F4(void*, void*);
extern void fn_801945D4(u8, u8, void*, void*, void*, void*);
extern void fn_80195960(void);
extern void fn_80193AB8(void);

void* fn_801936FC(void* argument1, void* argument2, u8* argument3)
{
    u8* saved3;
    void* saved1;
    void* saved2;
    u8* result;
    u8 i;

    saved3 = argument3;
    saved1 = argument1;
    saved2 = argument2;
    result = fn_8018038C(lbl_8064D238, lbl_80606334);
    if (result != 0) {
        fn_8019475C(result, saved1, saved2, saved3);
        fn_801947F4(result, saved3);
        if ((*(u32*)(result + 0x108) & 0x20) == 0) {
            i = 0;
            while (i < result[0x97]) {
                fn_801945D4(result[0x97], i, *(void**)(result + 0x58),
                            result + 0x120, result + 0x11C, result + 0x118);
                fn_801945D4(result[0x97], i,
                            *(u8**)(result + 0x58) + (*(u16*)(lbl_80607120 + 2) << 2),
                            result + 0x120, result + 0x11C, result + 0x118);
                i++;
            }
        }
        *(void (**)(void))(result + 0x14C) = fn_80195960;
        if ((*(u32*)(result + 0x108) & 1) == 0 &&
            (*(u32*)(result + 0x108) & 2) == 0 &&
            (*(u32*)(result + 0x108) & 4) == 0 &&
            (*(u32*)(saved3 + 0x38) & 0x80000) == 0) {
            *(void (**)(void))(result + 0x148) = fn_80193AB8;
        }
        *(u16*)(result + 0x22) = 4;
    }
    return result;
}
