typedef unsigned char u8;

typedef struct Header {
    u8 padding[0x210];
    u8 count;
} Header;

typedef struct Entry {
    u8 padding[8];
    u8 active;
    u8 trailing[0x5B];
} Entry;

extern u8 lbl_8064D3E8;
extern u8 lbl_8064D3E9;
extern int lbl_8064D3EC;
extern Header lbl_80619C20;
extern Entry lbl_8061AE48[];

void fn_801B9350(void)
{
    int i;

    lbl_8064D3E8 = 0;
    lbl_8064D3E9 = 3;
    for (i = 0; i < lbl_80619C20.count; i++) {
        lbl_8061AE48[i].active = 0;
    }
    lbl_8064D3EC = 0;
}
