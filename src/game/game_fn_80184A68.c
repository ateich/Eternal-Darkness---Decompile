typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#pragma use_lmw_stmw on

typedef struct SixBytes {
    u32 word;
    u16 half;
} SixBytes;

extern u32 lbl_80651D30;
extern u16 lbl_80651D34;
extern void* lbl_8064D224;
extern float lbl_806509E8;
extern u8 lbl_80606318[];
extern u8 lbl_80606328[];

extern void* memset(void*, int, u32);
extern void* memcpy(void*, const void*, u32);
extern void fn_801804AC(void*, void*, void*, void*);
extern void fn_80180518(void*, u32, int);
extern void fn_80180554(void*, void*, void*, void*, u16, int);
extern void fn_801805E0(void*, int, u8, u8, void*, float);
extern void fn_80184E3C(void*, void*, u8, u8, u8);
extern void fn_8018C2D0(void*, u8, int);
extern void fn_801F5A04(void*, s16, void*, void*);

void fn_80184A68(u8* self, void* arg1, void* arg2, u8* desc)
{
    SixBytes setup;
    u32 effect;
    u32 step_count;
    int i;
    u8 count;
    u8 step;
    s16 remaining;
    u8* entry;

    setup.word = lbl_80651D30;
    setup.half = lbl_80651D34;
    entry = *(u8**)(self + 0x4C);
    count = desc[0];
    step_count = desc[0x15];
    fn_801804AC(self, arg1, arg2, &setup);

    self[0] = 0x80;
    self[1] = count;
    *(u16*)(self + 0xC) = *(u16*)(desc + 6);
    *(s16*)(self + 0xE) = *(s16*)(desc + 4);
    *(u16*)(self + 0xA) = 0;
    *(u32*)(self + 0x38) = *(u32*)(desc + 0x28);
    *(u32*)(self + 0x44) = 0;
    self[4] = desc[3];
    *(void**)(self + 0x68) = lbl_8064D224;
    memset(self + 0x24, 0, 0x10);

    memcpy(&effect, desc + 0x2C, sizeof(effect));
    step = desc[1];
    fn_80184E3C(*(void**)(self + 0x58), &effect, count, desc[0x14],
                step_count);
    remaining = ((u8*)&effect)[3];

    for (i = 0; (u8)i < count; i++) {
        u8 index;

        ((u8*)&effect)[3] = remaining;
        if (*(int*)(desc + 0x18) != 0) {
            index = i;
            if ((i & 1) != 0 || index <= 3) {
                ((u8*)&effect)[3] = 0;
            }
        }
        fn_80180554(entry, arg1, arg2, &setup, *(u16*)(desc + 8), 0);
        fn_801805E0(entry + 0x20, step_count, step,
                    i * step_count, &effect, lbl_806509E8);
        remaining -= desc[0x14];
        if (remaining < 0) {
            remaining = 0;
        }
        entry += 0x38;
    }

    fn_80180518(self + 0x24, 0, 1);
    fn_8018C2D0(*(void**)(self + 0x54), count, 4);
    if (*(s16*)(desc + 4) >= 0) {
        fn_801F5A04(self + 0x6C, *(s16*)(desc + 4), lbl_80606328,
                    lbl_80606318);
    }
}
