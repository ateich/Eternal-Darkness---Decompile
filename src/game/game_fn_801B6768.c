typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

extern u8* lbl_8064D3D0;
extern u32 lbl_8064D3E0;
extern u32 lbl_8064D3E4;
extern s32 fn_801CC6DC(u32);
extern s16 fn_801CC304(u16);
extern s32 fn_801C30D4(void*, u16*, u16*);
extern u16 fn_801CBA58(void*);
extern u32 fn_801CBAE8(void*);
extern u16 fn_801CAFAC(s32, u8, u8);
extern u16 fn_801C29BC(u8, u32);
extern u16 fn_801C2980(u16);
extern u16 fn_801CBAA0(void*);
extern void fn_801CCB98(u32);
extern void fn_801B775C(void*, u32, u32);

#define U8(p, o)  (*(u8*)((p) + (o)))
#define S8(p, o)  (*(s8*)((p) + (o)))
#define U16(p, o) (*(u16*)((p) + (o)))
#define S16(p, o) (*(s16*)((p) + (o)))
#define U32(p, o) (*(u32*)((p) + (o)))
#define S32(p, o) (*(s32*)((p) + (o)))
#define U64(p, o) (*(u64*)((p) + (o)))

void fn_801B6768(u32 index)
{
    u8* voice = lbl_8064D3D0 + index * 0x404;
    u32 delta;
    u32 i;
    u32 pitch;
    u32 value;

    if (fn_801CC6DC(index) || U32(voice, 0x34) != 0) {
        delta = lbl_8064D3E4 - U32(voice, 0x28);
        U32(voice, 0x28) = lbl_8064D3E4;
        U32(voice, 0x24) = lbl_8064D3E0;

        for (i = 0; i < 2; i++) {
            u8* timer = voice + i * 12;
            if (U32(timer, 0x1C0) != 0) {
                u32 period = U32(timer, 0x1C0);
                U32(timer, 0x1BC) += delta;
                U16(timer, 0x1C4) = fn_801CC304((u16)((U32(timer, 0x1BC) % period) * 16 / (period >> 8)));
                if (S16(timer, 0x1C4) != S16(timer, 0x1C6)) {
                    S16(timer, 0x1C6) = S16(timer, 0x1C4);
                    if (U8(voice, 0x1D4 + i) != 0) {
                        U8(voice, 0x1D4 + i) = 0;
                        U32(voice, 0x214) |= 0x1FFF;
                    }
                }
            }
        }

        if (U64(voice, 0x114) & 0x2000ULL) {
            u32 period = U32(voice, 0x144);
            U32(voice, 0x148) += delta;
            S32(voice, 0x14C) = (s16)fn_801CC304((u16)((U32(voice, 0x148) % period) * 16 / (period >> 8)));
        }

        if (U8(voice, 0x1B8) || U8(voice, 0x1B9)) {
            u32 whole = (delta & 0xFFFFFF) << 4;
            u32 fraction = delta & 0xF;
            u8* env = voice;
            if (U8(env, 0x1B8)) {
                U32(env, 0x1B0) -= whole;
                if (S32(env, 0x1B0) <= 0) {
                    U32(env, 0x1B0) = U8(env, 0x1B8) << 16;
                    U32(env, 0x1A0) = 0;
                } else {
                    U32(env, 0x1A0) += (S32(env, 0x1A8) >> 12) * fraction;
                }
            }
            env = voice + 4;
            if (U8(voice, 0x1B9)) {
                U32(env, 0x1B0) -= whole;
                if (S32(env, 0x1B0) <= 0) {
                    U32(env, 0x1B0) = U8(voice, 0x1B9) << 16;
                    U32(env, 0x1A0) = 0;
                } else {
                    U32(env, 0x1A0) += (S32(env, 0x1A8) >> 12) * fraction;
                }
            }
        }

        if (U32(voice, 0x170) != U32(voice, 0x180)) {
            U32(voice, 0x188) -= delta;
            if (S32(voice, 0x188) <= 0) {
                U32(voice, 0x170) = U32(voice, 0x180);
                U32(voice, 0x188) = 0;
            } else {
                U32(voice, 0x170) = U32(voice, 0x180) - (U32(voice, 0x188) >> 8) * U32(voice, 0x178);
                if (S32(voice, 0x170) < 0)
                    U32(voice, 0x170) = 0;
                else if (U32(voice, 0x170) > 0x7F0000)
                    U32(voice, 0x170) = 0x7F0000;
            }
            U64(voice, 0x114) |= 0x200000000000ULL;
        }
        if (U32(voice, 0x174) != U32(voice, 0x184)) {
            u8* side = voice + 4;
            U32(side, 0x188) -= delta;
            if (S32(side, 0x188) <= 0) {
                U32(side, 0x170) = U32(side, 0x180);
                U32(side, 0x188) = 0;
            } else {
                U32(side, 0x170) = U32(side, 0x180) - (U32(side, 0x188) >> 8) * U32(side, 0x178);
                if (S32(side, 0x170) < 0)
                    U32(side, 0x170) = 0;
                else if (U32(side, 0x170) > 0x7F0000)
                    U32(side, 0x170) = 0x7F0000;
            }
            U64(voice, 0x114) |= 0x200000000000ULL;
        }

        if (U64(voice, 0x114) & 0x20000000000ULL) {
            u16 a, b;
            if (fn_801C30D4(voice + 0x1DC, &a, &b))
                U64(voice, 0x114) &= ~0x20000000000ULL;
        }

        pitch = (U16(voice, 0x12C) << 16) + (((s32)S8(voice, 0x12E) << 16) / 100);
        if (U64(voice, 0x114) & 0x10010ULL) {
            u16 bend;
            if (U8(voice, 0x121) != 0xFF) {
                bend = fn_801CBA58(voice);
                U16(voice, 0x1D8) = bend;
            } else {
                bend = U16(voice, 0x1D8);
            }
            if (bend != 0x2000) {
                s32 distance = bend - 0x2000;
                if (distance < 0)
                    pitch += U8(voice, 0x1D6) * distance * 8;
                else
                    pitch += U8(voice, 0x1D7) * distance * 8;
            }
        }

        if (U64(voice, 0x114) & 0x2000ULL) {
            u32 mod = fn_801CBAE8(voice);
            s32 depth = (U8(voice, 0x141) << 8) / 100;
            s32 amount = (U8(voice, 0x140) << 8) + depth;
            if (S16(voice, 0x150) != 0)
                amount += (S16(voice, 0x150) * ((mod >> 7) & 0x1FF)) >> 7;
            if (U64(voice, 0x114) & 0x4000ULL)
                depth = (S32(voice, 0x14C) * ((mod >> 7) & 0x1FF)) >> 7;
            else
                depth = S32(voice, 0x14C);
            pitch += (amount * depth) >> 4;
        }

        if (U8(voice, 0x121) != 0xFF) {
            u16 control = fn_801CAFAC(0x41, U8(voice, 0x121), U8(voice, 0x122));
            if (control != U16(voice, 0x132) ||
                (U64(voice, 0x114) & 0x21000ULL) == 0x20000ULL) {
                if (control <= 0x1F80) {
                    U64(voice, 0x114) &= ~0x400ULL;
                } else {
                    if (!(U64(voice, 0x114) & 0x20400ULL)) {
                        if (U8(voice, 0x131) == 1) {
                            if (!(U64(voice, 0x114) & 0x1000ULL))
                                U32(voice, 0x13C) = 0;
                            else
                                U32(voice, 0x13C) = U32(voice, 0x134);
                        } else {
                            U32(voice, 0x13C) = U32(voice, 0x134);
                        }
                        U32(voice, 0x138) = U8(voice, 0x130) << 16;
                    }
                    U64(voice, 0x114) |= 0x400ULL;
                }
                U64(voice, 0x114) |= 0x1000ULL;
                U16(voice, 0x132) = control;
            }
        }

        value = pitch;
        if (U64(voice, 0x114) & 0x400ULL) {
            u32 elapsed = U32(voice, 0x13C);
            u32 duration = U32(voice, 0x134);
            u32 steps = (duration - elapsed) >> 8;
            if ((s32)steps > 0) {
                u32 start = U32(voice, 0x138);
                u32 next = start + (delta * ((s32)(pitch - start) >> 8)) / (s32)steps;
                U32(voice, 0x138) = next;
                if ((start < pitch && next < pitch) || (start > pitch && next > pitch)) {
                    U32(voice, 0x13C) += delta;
                    value = next;
                } else {
                    U32(voice, 0x13C) = duration;
                }
            }
        }

        if (U64(voice, 0x114) & 0x20000000000ULL)
            value += (S16(voice, 0x204) * (S32(voice, 0x1E4) >> 16)) >> 7;

        pitch = fn_801C29BC((u8)(value >> 16), U32(voice, 0x124)) << 16;
        if ((value & 0xFFFF) != 0) {
            u16 base = pitch >> 16;
            pitch += (value & 0xFFFF) * (fn_801C2980(base) - base);
        }
        pitch += U32(voice, 0x1A4);
        pitch += U32(voice, 0x1A0);
        U16(voice, 0x206) = ((pitch >> 16) * fn_801CBAA0(voice)) >> 13;
        fn_801CCB98(index);
        fn_801B775C(voice, 0, 0xF00);
    }

    if (U8(voice, 0xA8) != 0) {
        U8(voice, 0xA8) = 0;
        U32(voice, 0x214) = 0x1FFF;
    }
}
