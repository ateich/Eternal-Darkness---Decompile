typedef unsigned char u8;
typedef unsigned short u16;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];

extern void* fn_8018038C(void*, void*);
extern void fn_8019197C(void*, void*, void*, u8*);
extern void fn_80191C8C(void*, u8*);
extern void fn_8018ABD4(void);
extern void fn_801926EC(void);
extern void* memcpy(void*, const void*, unsigned long);

void* fn_801925F0(void* source, void* value, u8* info)
{
    void* object;

    object = *(void**)(info + 0xC);
    if (object == 0) {
        object = fn_8018038C(lbl_8064D238, lbl_80606334);
        if (object != 0) {
            info[1] = 1;
            info[0x14] = 3;
            info[0x16] = 100;
            info[0x17] = 5;
            info[0x18] = 1;
            info[0x19] = 200;
            info[0x1B] = 10;
            fn_8019197C(object, source, value, info);
        }
    } else {
        memcpy((u8*)object + 0x10, source, 6);
    }

    if (object != 0) {
        fn_80191C8C(object, info);
        *(void (**)(void))((u8*)object + 0x14C) = fn_801926EC;
        *(void (**)(void))((u8*)object + 0x148) = fn_8018ABD4;
        *(u16*)((u8*)object + 0x22) = 4;
    }
    return object;
}
