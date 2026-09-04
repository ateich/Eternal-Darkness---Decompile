typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

#pragma pack(4)
typedef struct Voice {
    u8 pad_000[0xF4];
    u32 id_F4;
    u8 pad_0F8[0x1C];
    u64 flags_114;
    u8 pad_11C[2];
    u8 value_11E;
    u8 value_11F;
    u8 value_120;
    u8 value_121;
    u8 value_122;
    u8 value_123;
    u32 value_124;
    u32 value_128;
    u8 pad_12C[3];
    u8 value_12F;
    u8 value_130;
    u8 value_131;
    u16 value_132;
    u32 value_134;
    u8 pad_138[4];
    u32 value_13C;
    u8 pad_140[0x10];
    u16 value_150;
    u8 pad_152[2];
    u32 value_154;
    u32 value_158;
    u8 pad_15C[0x10];
    u16 value_16C;
    u8 pad_16E[2];
    u32 value_170;
    u32 value_174;
    u8 pad_178[8];
    u32 value_180;
    u32 value_184;
    u8 pad_188[8];
    u8 value_190;
    u8 value_191;
    u8 value_192;
    u8 value_193;
    u8 pad_194[0x74];
    u8 source_208;
    u8 source_209;
    u8 source_20A;
    u8 source_20B;
    u8 source_20C;
    u8 source_20D;
    u8 source_20E;
    u8 source_20F;
    u8 source_210;
} Voice;
#pragma pack()

extern void fn_801CC8C4(u8);
extern void fn_801CBE58(Voice*);
extern u8 fn_801CB4B4(u8, u8);
extern void fn_801CB470(u8, u8, u8);
extern void fn_801C26F8(Voice*);
extern u16 fn_801CAFAC(u32, u8, u8);

/*
 * The remainder of this large command dispatcher is still being recovered.
 * This prefix deliberately remains honest C and receives no matching credit.
 */
void fn_801BEF40(Voice* voice)
{
    u8 value;

    if ((voice->flags_114 & 3) != 0) {
        if ((voice->flags_114 & 1) != 0) {
            voice->flags_114 &= ~1ULL;
            fn_801CC8C4((u8)voice->id_F4);
        }

        voice->value_180 = (u32)voice->source_209 << 16;
        voice->value_170 = (u32)voice->source_209 << 16;
        voice->value_184 = 0;
        voice->value_174 = 0;
        voice->value_154 = (u32)voice->source_208 << 16;
        voice->value_192 = 0;
        voice->value_158 = voice->value_154;
        voice->value_121 = voice->source_20A;
        voice->value_122 = voice->source_20B;
        voice->value_123 = voice->source_20C;
        voice->value_120 = voice->source_20D;
        voice->value_193 = voice->source_210;
        voice->value_150 = 0;
        voice->value_16C = 0;
        fn_801CBE58(voice);

        value = fn_801CB4B4(voice->value_121, voice->value_122);
        if (value != 0xFF) {
            voice->value_130 = value;
        } else {
            voice->value_130 = voice->value_12F;
        }
        fn_801CB470(voice->value_121, voice->value_122, voice->value_12F);
        fn_801C26F8(voice);

        voice->value_11E = voice->source_20E;
    }
}
