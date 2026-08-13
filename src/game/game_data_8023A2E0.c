typedef unsigned int u32;

extern void fn_8010F9D8(void);
extern char lbl_8024C5FC, lbl_8024C664, lbl_8024C6B4, lbl_8024C714;
extern char lbl_8024C754, lbl_8024C7F4, lbl_8024C8AC, lbl_8024C95C;
extern char lbl_8024C9FC, lbl_8024CAE4, lbl_8024CA8C, lbl_8024CB6C;
extern char lbl_8024CCCC, lbl_8024CC2C;

typedef struct CodecMode {
    u32 flags;
    u32 index;
    void (*callback)(void);
    u32 reserved;
    u32 mask;
    u32 duration;
    u32 interval;
    u32 padding;
} CodecMode;

typedef struct CodecFormat {
    const char* resource;
    u32 format;
} CodecFormat;

/* Three codec operating modes followed by fourteen resource/format pairs. */
const volatile struct {
    CodecMode modes[3];
    CodecFormat formats[14];
} lbl_8023A2E0 = {
    {
        { 0x200C0000, 0, fn_8010F9D8, 0, 0x1FFFFFFF, 0x1E, 0xA, 0 },
        { 0x200C0000, 1, fn_8010F9D8, 0, 0x1FFFFFFE, 0, 0, 0 },
        { 0x200C0000, 0, fn_8010F9D8, 0, 0x1FFFFFFF, 0x1E, 0xA, 0 },
    },
    {
        { &lbl_8024C5FC, 0x0000000D }, { &lbl_8024C664, 0x0001000A },
        { &lbl_8024C6B4, 0x0002000C }, { &lbl_8024C714, 0x00030008 },
        { &lbl_8024C754, 0x00040014 }, { &lbl_8024C7F4, 0x00050017 },
        { &lbl_8024C8AC, 0x00060016 }, { &lbl_8024C95C, 0x00070014 },
        { &lbl_8024C9FC, 0x00080012 }, { &lbl_8024CAE4, 0x000A0011 },
        { &lbl_8024CA8C, 0x0009000B }, { &lbl_8024CB6C, 0x000B0018 },
        { &lbl_8024CCCC, 0x000D0013 }, { &lbl_8024CC2C, 0x000C0014 },
    },
};
