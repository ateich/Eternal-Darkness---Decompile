typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Block32 { u32 word[8]; } Block32;
typedef struct Entry {
    u8 pad00[0x18]; u32 arg8; u32 arg7; u32 pad20; u32 flags[19];
    u16 value; u16 pad72; Block32 block; u8 pad94[0x10]; u8 byteA4;
    u8 padA5[0x13]; u32 fieldB8; u32 fieldBC; u16 fieldC0;
    u8 padC2[2]; u32 fieldC4; u8 padC8[0x1C]; u8 bytesE4[4];
    u8 padE8[8]; u32 fieldF0;
} Entry;

extern Entry* volatile lbl_8064D4AC;
extern u8 lbl_8064D4D8;
extern void fn_801CCC10(u32, u32);
extern void fn_801CCC3C(u32, u32);
extern void fn_801CCC68(u32, u32);

void fn_801CC718(u32 index, u16 value, Block32* source, u32 initialize,
                 u32 arg7, u32 arg8, u32 configure, u32 arg10)
{
    u32 offset = 0;
    u32 zero = offset;
    u32 flags = 0;
    u8 i = 0;

    while (i <= lbl_8064D4D8) {
        u8* cursor = (u8*)lbl_8064D4AC + offset;
        u32* field = (u32*)(cursor + 0x24 + index * 0xF4);
        flags |= *field & 0x20;
        *field = zero;
        offset += 4;
        i++;
    }

    lbl_8064D4AC[index].flags[0] = flags;
    lbl_8064D4AC[index].arg7 = arg7;
    lbl_8064D4AC[index].arg8 = arg8;
    lbl_8064D4AC[index].fieldF0 = 0;
    lbl_8064D4AC[index].value = value;
    lbl_8064D4AC[index].block = *source;
    if (initialize != 0) {
        lbl_8064D4AC[index].byteA4 = 0;
        lbl_8064D4AC[index].fieldB8 = 0;
        lbl_8064D4AC[index].fieldBC = 0;
        lbl_8064D4AC[index].fieldC0 = 0x7FFF;
        lbl_8064D4AC[index].fieldC4 = 0;
    }
    lbl_8064D4AC[index].bytesE4[0] = 0xFF;
    lbl_8064D4AC[index].bytesE4[1] = 0xFF;
    lbl_8064D4AC[index].bytesE4[2] = 0xFF;
    lbl_8064D4AC[index].bytesE4[3] = 0xFF;
    if (configure != 0) {
        fn_801CCC10(index, 0);
        fn_801CCC3C(index, 1);
    }
    fn_801CCC68(index, arg10);
}
