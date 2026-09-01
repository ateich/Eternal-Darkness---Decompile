typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

extern u8* lbl_8064D3D0;
extern u32 lbl_8064D3CC;
extern u32 lbl_8064D3E0;
extern u32 lbl_8064D3E4;
extern u8 lbl_80619860[];
extern s32 fn_801CC6DC(u32);
extern u16 fn_801CBAE8(void*);
extern u16 fn_801CBC98(void*);
extern u16 fn_801CB9C8(void*);
extern u16 fn_801CBA10(void*);
extern u16 fn_801CB980(void*);
extern u16 fn_801CBBC0(void*);
extern u16 fn_801CBB78(void*);
extern u16 fn_801CBC50(void*);
extern u16 fn_801CBC08(void*);
extern u8 fn_801CC6D4(void);
extern void fn_801CCCC4(u32, u8, u32, u32, float, float, float);
extern void fn_801CC704(u32, u32, u8);
extern void fn_801B775C(void*, u32, u32);

#define U8(p, o)  (*(u8*)((p) + (o)))
#define U16(p, o) (*(u16*)((p) + (o)))
#define U32(p, o) (*(u32*)((p) + (o)))
#define S32(p, o) (*(s32*)((p) + (o)))
#define F32(p, o) (*(float*)((p) + (o)))
#define U64(p, o) (*(u64*)((p) + (o)))

void fn_801B6F1C(u32 index)
{
    u8* voice = lbl_8064D3D0 + index * 0x404;
    u32 delta;
    u32 changed;
    float volume;
    float pan;

    if (fn_801CC6DC(index) || U32(voice, 0x34) != 0) {
        delta = lbl_8064D3E4 - U32(voice, 0x30);
        U32(voice, 0x30) = lbl_8064D3E4;
        U32(voice, 0x2C) = lbl_8064D3E0;
        changed = 0;

        if (U64(voice, 0x114) & 0x8000ULL) {
            U32(voice, 0x19C) += U32(voice, 0x194) * (delta >> 8);
            if ((S32(voice, 0x194) < 0 && S32(voice, 0x19C) <= S32(voice, 0x198)) ||
                (S32(voice, 0x194) >= 0 && S32(voice, 0x19C) >= S32(voice, 0x198))) {
                U32(voice, 0x19C) = U32(voice, 0x198);
                U64(voice, 0x114) &= ~0x8000ULL;
            }
            U32(voice, 0x154) = U32(voice, 0x19C);
            changed = 1;
        } else {
            changed = (U64(voice, 0x114) & 0x1000ULL) == 0;
        }
        U64(voice, 0x114) &= ~0x1000ULL;

        volume = F32(lbl_80619860, 0x5D4 + (U8(voice, 0x11D) ? 0x16 * 0x30 : 0x15 * 0x30));
        volume *= F32(lbl_80619860, 0x5E8 + U8(voice, 0x11E) * 0x30);
        volume *= F32(lbl_80619860, 0x5D4 + U8(voice, 0x11E) * 0x30);
        if (U8(voice, 0x120) != 0xFF)
            volume *= lbl_80619860[0xBD4 + U8(voice, 0x120)] * (1.0f / 127.0f);
        if (F32(voice, 0x15C) != volume) {
            F32(voice, 0x15C) = volume;
            changed = 1;
        }

        pan = U32(voice, 0x154) * (1.0f / 8388608.0f);
        if (U16(voice, 0x16C) || U16(voice, 0x16E)) {
            s32 target;
            u32 mod = fn_801CBAE8(voice);
            target = (0x2000 - ((0x4000 - (s16)fn_801CBC98(voice)) >> 1));
            target = 0x2000 - target;
            F32(voice, 0x168) += F32(voice, 0x168) < target ? 1.0f : -1.0f;
            pan *= 1.0f - (mod & 0xFFFF) * (1.0f / 65535.0f) *
                   (1.0f - F32(voice, 0x168));
            changed = 1;
        }

        if (lbl_8064D3CC & 1) {
            U32(voice, 0x160) = 0x400000;
            U32(voice, 0x164) = 0;
            changed |= (U64(voice, 0x114) & 0x2000ULL) == 0;
            U64(voice, 0x114) &= ~0x2000ULL;
        } else if ((U64(voice, 0x114) & 0x2000ULL) ||
                   (U32(voice, 0x214) & 6)) {
            s32 value;
            U64(voice, 0x114) &= ~0x2000ULL;
            value = U32(voice, 0x170) + ((fn_801CB9C8(voice) - 0x2000) << 9);
            if (value < 0)
                value = 0;
            else if (value > 0x7F0000)
                value = 0x7F0000;
            U32(voice, 0x160) = value;
            if (lbl_8064D3CC & 2) {
                U32(voice, 0x164) = U32(voice, 0x174) + (fn_801CBA10(voice) << 9);
                if (U32(voice, 0x164) > 0x7F0000)
                    U32(voice, 0x164) = 0x7F0000;
            } else {
                U32(voice, 0x164) = 0;
            }
            changed = 1;
        } else if (!(lbl_8064D3CC & 2)) {
            U32(voice, 0x164) = 0;
        }

        if (changed || (U32(voice, 0x214) & 0xF01)) {
            float a = volume * pan * fn_801CB980(voice) * (1.0f / 8192.0f);
            float b = a * fn_801CBBC0(voice) * U8(voice, 0x190) * (1.0f / 8192.0f);
            float c = volume * fn_801CBB78(voice) * (1.0f / 8192.0f);
            c += b + fn_801CBC50(voice) * U8(voice, 0x191) * (1.0f / 8192.0f);
            U16(voice, 0x400) = (u16)(a * 32767.0f);
            fn_801CCCC4(index, U8(voice, 0x192), U32(voice, 0x160),
                        U32(voice, 0x164), a, c,
                        volume * fn_801CBC08(voice) * (1.0f / 8192.0f));
        }

        if (U32(voice, 0x110) != 0) {
            S32(voice, 0x110) -= U16(voice, 0x10E) * delta;
            if (S32(voice, 0x110) < 0)
                U32(voice, 0x110) = 0;
            fn_801CC704(index, (U8(voice, 0x10C) << 24) | (U32(voice, 0x110) >> 15),
                        U8(voice, 0x10C));
        }
        fn_801B775C(voice, 1, (5 - fn_801CC6D4()) << 8);
    }

    if (U8(voice, 0xA8) != 0) {
        U8(voice, 0xA8) = 0;
        U32(voice, 0x214) = 0x1FFF;
    }
}
