typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    u8 pad00[0x24];
    u32 flags;
    u8 pad28[0x68];
    u8 field90;
    u8 pad91[3];
    u32 field94;
    u32 field98;
    u8 field9C;
    u8 pad9D[7];
    u8 fieldA4;
    u8 padA5[0x13];
    u32 fieldB8;
    u32 fieldBC;
    u16 fieldC0;
    u8 padC2[2];
    u32 fieldC4;
    u8 padC8[2];
    u8 fieldCA;
    u8 padCB[0x29];
} Entry;

extern Entry* lbl_8064D4AC;
extern u8 lbl_80252B2C[];
extern u32 fn_801C2AAC(u32);

void fn_801CC914(u32 index, u8* data, u8 type)
{
    u32 offset;
    u32 value;

    switch (type) {
    case 0: {
        offset = index * 0xF4;
        lbl_8064D4AC[index].fieldA4 = 0;
        lbl_8064D4AC[index].fieldB8 = *(u16*)&data[0];
        lbl_8064D4AC[index].fieldBC = *(u16*)&data[2];
        value = *(volatile u16*)&data[4] << 3;
        if (value > 0x7FFF) {
            value = 0x7FFF;
        }
        lbl_8064D4AC[index].fieldC0 = value;
        lbl_8064D4AC[index].fieldC4 = *(u16*)&data[6];
        break;
    }
    case 1:
    case 2:
        offset = index * 0xF4;
        lbl_8064D4AC[index].fieldA4 = 1;
        lbl_8064D4AC[index].fieldCA = 0;
        if (type == 1) {
            lbl_8064D4AC[index].fieldB8 = (u16)fn_801C2AAC(*(u32*)&data[0]);
            lbl_8064D4AC[index].fieldBC = (u16)fn_801C2AAC(*(u32*)&data[4]);
            value = *(u16*)&data[8] >> 2;
            if (value > 0x3FF) {
                value = 0x3FF;
            }
            lbl_8064D4AC[index].fieldC0 = 0xC1 - lbl_80252B2C[value];
        } else {
            lbl_8064D4AC[index].fieldB8 = (u16)*(u32*)&data[0];
            lbl_8064D4AC[index].fieldBC = (u16)*(u32*)&data[4];
            lbl_8064D4AC[index].fieldC0 = *(u16*)&data[8];
        }
        lbl_8064D4AC[index].fieldC4 = *(u16*)&data[10];
        break;
    }
    lbl_8064D4AC[index].flags |= 0x10;
}
