typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct SixBytes {
    u32 word;
    u16 half;
} SixBytes;

typedef struct ThreeWords {
    u32 x;
    u32 y;
    u32 z;
} ThreeWords;

extern u32 lbl_80651D40;
extern u16 lbl_80651D44;

extern void* memcpy(void*, const void*, u32);
extern void fn_80185F10(void*, void*, u16, void*);

void fn_80185E0C(u8* self, u8* desc)
{
    SixBytes setup;
    u8* state = self + 0x8C;

    setup.word = lbl_80651D40;
    setup.half = lbl_80651D44;
    *(s16*)(self + 0x98) = *(s16*)(desc + 0xC);
    *(u16*)(self + 0x96) = *(u16*)(desc + 6);
    *(u16*)(self + 0x92) = *(u16*)(desc + 8);
    *(u16*)(self + 0x94) = *(u16*)(desc + 0xA);
    self[0x8D] = desc[0];
    self[0x8C] = 0;
    *(float*)(self + 0xBC) = *(float*)(desc + 0x18);
    self[0x8E] = desc[1];
    self[0x91] = desc[4] & 0x1F;
    self[0x90] = 1;
    *(ThreeWords*)(self + 0xEC) = *(ThreeWords*)(desc + 0x28);
    *(ThreeWords*)(self + 0xF8) = *(ThreeWords*)(desc + 0x34);
    *(ThreeWords*)(self + 0xE0) = *(ThreeWords*)(desc + 0x1C);
    memcpy(state + 0x34, self + 0x10, 6);
    fn_80185F10(state, self, *(u16*)(state + 6), &setup);
}
