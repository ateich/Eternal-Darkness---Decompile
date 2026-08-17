typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 lbl_8063D378[];
extern float lbl_80650110;
extern s32 lbl_8064D738;

extern float fn_8017968C(void*, void*);
extern s32 fn_80126050(void*);
extern void fn_80120B58(void*);
extern void fn_801248FC(void*);
extern void fn_80124180(void*, s32);
extern void fn_801243A8(void*);
extern s32 fn_80130998(u16, float);
extern void* fn_80120744(void*, s32, float);
extern void* fn_801208AC(void*, s32, float);
extern void fn_80124A40(void*, void*, u32*, u32*);
extern void DCFlushRange(void*, u32);

#define U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define U32(p, o) (*(u32*)((u8*)(p) + (o)))
#define F32(p, o) (*(float*)((u8*)(p) + (o)))

void fn_80124DBC(void* owner)
{
    void* table = (void*)U32(owner, 0x3C);
    float scale = fn_8017968C(owner, lbl_8063D378);
    float frame = F32(owner, 0x2AC);
    s32 first_count;
    s32 second_count;
    u32 first;
    u32 second;
    s32 slot;

    if (U32(owner, 0x2A0) == 0 || frame == lbl_80650110 ||
        !fn_80126050(owner)) {
        return;
    }

    U32((void*)U32(owner, 0x2A0), 0) &= ~4;
    fn_80120B58(owner);
    if (U8(owner, 0x2DE) != 0) {
        if (U8(owner, 0x2DE) < U8(owner, 0x2DF))
            U8(owner, 0x2DE) = 0;
        else
            U8(owner, 0x2DE) -= U8(owner, 0x2DF);
    }

    if ((U32(owner, 0x254) & 0x80000) == 0)
        return;

    fn_801248FC(owner);
    fn_80124180(owner, 0);
    fn_801243A8(table);
    first_count = fn_80130998(U16(table, 0x1E), frame);
    second_count = fn_80130998(U16(table, 0x1E), frame);
    if (U32(owner, 0x254) & 0x400000)
        second_count *= 3;

    slot = lbl_8064D738;
    *(void**)((u8*)owner + 0x164 + slot * 4) =
        fn_80120744(owner, first_count, frame);
    *(void**)((u8*)owner + 0x16C + slot * 4) =
        fn_801208AC(owner, second_count, frame);

    if (*(void**)((u8*)owner + 0x164 + slot * 4) != 0 &&
        *(void**)((u8*)owner + 0x16C + slot * 4) != 0) {
        fn_80124A40(owner, table, &first, &second);
    } else {
        U32(owner, 0x254) &= ~0x80000;
        *(void**)((u8*)owner + 0x164 + slot * 4) = 0;
        *(void**)((u8*)owner + 0x16C + slot * 4) = 0;
    }

    DCFlushRange(*(void**)((u8*)owner + 0x164 + slot * 4), first_count * 6);
    DCFlushRange(*(void**)((u8*)owner + 0x16C + slot * 4), second_count * 6);
    (void)scale;
    (void)first;
    (void)second;
}
