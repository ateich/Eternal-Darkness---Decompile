typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry801A6F94 {
    u8 pad0[0x64];
    int field64;
    u8 pad68[0x10];
    unsigned int flags78;
    unsigned int field7C;
    unsigned int field80;
    unsigned int field84;
    unsigned int field88;
    unsigned int field8C;
    unsigned int field90;
    u8 pad94[4];
    unsigned int field98;
    unsigned int field9C;
    u8 padA0[4];
    unsigned int fieldA4;
    unsigned int fieldA8;
    u8 padAC[8];
    short fieldB4;
    u16 fieldB6;
    u8 padB8[0xE];
    short fieldC6;
    u8 padC8;
    u8 fieldC9;
} Entry801A6F94;

extern int OSReport(const char*, ...);
extern const char lbl_802513A8[];
extern int lbl_8064D270;
extern int lbl_8064D5A8;
extern const char lbl_8064C294;
extern const char lbl_8064C290;
extern Entry801A6F94* lbl_80607C10[];

int fn_801A6F94(void)
{
    const char* strings = lbl_802513A8;
    Entry801A6F94* entry;
    int count = 0;
    int i;

    OSReport(strings + 0xC, lbl_8064D270, lbl_8064D5A8);
    for (i = 0; i < 40; i++) {
        entry = lbl_80607C10[i];
        if (entry != 0) {
            count++;
            OSReport(strings + 0x68, count, lbl_8064D5A8 - entry->field64,
                     entry->fieldC6, entry->field9C, entry->field98,
                     (entry->flags78 & 1) ? &lbl_8064C290 : &lbl_8064C294,
                     entry->field7C, entry->field80, entry->field84,
                     entry->field88);
            OSReport(strings + 0xE0, entry->field8C, entry->field90,
                     entry->fieldA4, entry->fieldA8, entry->fieldB4,
                     entry->fieldB6, entry->fieldC9);
        }
    }
    OSReport(strings + 0x13C, count);
    return count;
}
