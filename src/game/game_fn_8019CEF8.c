typedef unsigned char u8;
typedef unsigned short u16;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];
extern u8* fn_8018038C(void*, void*);
extern void fn_8019D030(u8*, u8*, void*, u8*);
extern void fn_8019D34C(u8*, u8*);
extern void fn_8019D390(void);
extern void fn_8018ABD4(void);
extern void* memcpy(void*, const void*, unsigned int);

u8* fn_8019CEF8(u8* source, void* arg, u8* config)
{
    u8* object = *(u8**)(config + 0xC);

    if (object == 0) {
        object = fn_8018038C(lbl_8064D238, lbl_80606334);
        fn_8019D030(object, source, arg, config);
    } else {
        memcpy(object + 0x10, source, 6);
    }

    if (object != 0) {
        fn_8019D34C(object, config);
        *(void (**)(void))(object + 0x14C) = fn_8019D390;
        *(void (**)(void))(object + 0x148) = fn_8018ABD4;
        *(u16*)(object + 0x22) = 4;
    }
    return object;
}
