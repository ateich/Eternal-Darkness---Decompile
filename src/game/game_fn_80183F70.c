typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct SixBytes {
    u32 word;
    u16 half;
} SixBytes;

extern u32 lbl_80651D18;
extern u16 lbl_80651D1C;
extern void* lbl_8064D224;
extern float lbl_806509D8;
extern u8 lbl_80607120[];
extern u8 lbl_80606318[];
extern u8 lbl_80606328[];

extern void fn_801804AC(void*, void*, void*, void*);
extern void fn_80180554(void*, void*, void*, void*, u16, int);
extern void fn_801805E0(void*, int, u8, u32, void*, float);
extern void fn_8018CEC0(void*, u8);
extern void fn_8018C540(void*, void*, u8, int, u16);
extern void fn_801F5A04(void*, s16, void*, void*);

void fn_80183F70(self, arg1, arg2, desc)
u8* desc;
u8* self;
void* arg1;
void* arg2;
{
    register u8* desc_local = desc;
    register u8* self_local = self;
    SixBytes setup;
    register u8* entry;

    (void)desc;
    (void)self;
    setup.word = lbl_80651D18;
    setup.half = lbl_80651D1C;
    entry = *(u8**)(self_local + 0x4C);
    fn_801804AC(self_local, arg1, arg2, &setup);
    self_local[0] = 0x80;
    self_local[1] = 1;
    self_local[2] = desc_local[2];
    self_local[4] = desc_local[3];
    *(s16*)(self_local + 0xE) = *(s16*)(desc_local + 4);
    *(void**)(self_local + 0x68) = lbl_8064D224;
    *(u16*)(self_local + 0xA) = 0;
    *(u32*)(self_local + 0x44) = 0;
    *(void**)(self_local + 0x5C) = *(void**)(desc_local + 0x1C);
    fn_80180554(entry, arg1, arg2, &setup, *(u16*)(desc_local + 8), 0);
    fn_801805E0(entry + 0x20, 4, desc_local[1], 0, desc_local + 0x1C,
                lbl_806509D8);
    fn_8018CEC0(*(void**)(self_local + 0x54), 1);
    fn_8018C540(*(void**)(self_local + 0x58), desc_local + 0x1C, 1, 4,
                *(u16*)(lbl_80607120 + 2));
    *(u16*)(self_local + 0x22) = 4;
    if (*(s16*)(desc_local + 4) >= 0) {
        fn_801F5A04(self_local + 0x6C, *(s16*)(desc_local + 4), lbl_80606328,
                    lbl_80606318);
    }
}
