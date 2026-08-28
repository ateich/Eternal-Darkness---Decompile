typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];

extern u8* fn_8018038C(void*, void*);
extern void fn_801916D0(u8*, void*, void*, u8*);
extern void fn_80191BA8(u8*, u8*);
extern void fn_80191568(void);
extern void fn_80191F58(void);
extern void fn_80191034(void);
extern void* memcpy(void*, const void*, u32);

u8* fn_80190D7C(void* arg0, void* arg1, u8* config)
{
    u8* result = *(u8**)(config + 0xC);

    if (result == 0) {
        result = fn_8018038C(lbl_8064D238, lbl_80606334);
        if (result != 0) {
            fn_801916D0(result, arg0, arg1, config);
        }
    } else {
        memcpy(result + 0x10, arg0, 6);
    }

    if (result != 0) {
        fn_80191BA8(result, config);
        if (config[0x19] != 0) {
            *(void (**)(void))(result + 0x14C) = fn_80191568;
        } else {
            *(void (**)(void))(result + 0x14C) = fn_80191F58;
        }
        *(void (**)(void))(result + 0x148) = fn_80191034;
        *(u16*)(result + 0x22) = 4;
    }
    return result;
}
