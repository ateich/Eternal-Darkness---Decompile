typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;


extern void* lbl_8064D224;
extern int lbl_8064D18C;
extern u8 lbl_802FC5BC[];
extern u8 lbl_80607130[];
extern u8 lbl_80606318[];
extern u8 lbl_80606328[];

extern void fn_801805E0(void*, int, u8, u32, void*, float);
extern void fn_8018CB70(void*, int, u16);
extern void fn_8018C540(void*, void*, u8, int, u16);
extern void fn_801F5A04(void*, s16, void*, void*);

void fn_8018F1D0(u8* self, void* arg1, void* arg2, u8* desc)
{
    u8* table = lbl_802FC5BC + 0xC;
    u8* entry;

    self[1] = 1;
    self[0] = 0x80;
    *(s16*)(self + 0xE) = *(s16*)(desc + 4);
    *(u16*)(self + 0xC) = *(u16*)(desc + 6);
    *(void**)(self + 0x68) = lbl_8064D224;
    *(u16*)(self + 0xA) = 0;
    *(u32*)(self + 0x44) = 0;
    *(int*)(self + 0x38) = lbl_8064D18C;
    self[3] = 9;

    entry = *(u8**)(self + 0x4C);
    *(s16*)(entry + 0xA) = *(float*)(desc + 0x14);
    *(s16*)(entry + 0xC) = *(float*)(desc + 0x18);
    *(s16*)(entry + 0xE) = *(float*)(desc + 0x1C);
    fn_801805E0(entry + 0x20, 4, desc[1], 0, table, 1.0f);
    fn_8018CB70(*(void**)(self + 0x54), 1,
                *(u16*)(lbl_80607130 + 2));
    fn_8018C540(*(void**)(self + 0x58), table, 1, 4,
                *(u16*)(lbl_80607130 + 2));
    if (*(s16*)(desc + 4) >= 0) {
        fn_801F5A04(self + 0x6C, *(s16*)(desc + 4), lbl_80606328,
                    lbl_80606318);
    }
    *(u16*)(self + 0x22) = 4;
}
