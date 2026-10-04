typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Info {
    u8 pad00[0xC];
    u32 handle;
    u32 end;
    u32 fade;
    u32 argument;
    u8 pad1C[0x14];
    u32 flags;
    u8 pad34[4];
    u32 resource;
    u16 kind;
    u8 mode;
    u8 pad3F;
    u8 limit;
    u8 pad41[3];
} Info;

typedef struct Timings {
    u32 first;
    u32 second;
    u32 third;
    u32 fourth;
} Timings;

typedef struct Work {
    u32 field00;
    u32 field04;
    u32 field08;
    u32 field0C;
    u32 field10;
    u16* values;
    u8 pad18[0x10];
} Work;

typedef struct MenuEntry {
    u32 flags;
    u32 field04;
    void (*handler)(void);
    u32 field0C;
    u32 mask;
    u32 field14;
    u32 field18;
    u32 field1C;
} MenuEntry;

extern MenuEntry lbl_80238978;
extern MenuEntry lbl_80238998;
extern u32 lbl_8064C6D0;
extern u32 lbl_8064C6C4;
extern u32 lbl_8064C6C8;
extern u32 lbl_8064C670;
extern void* lbl_8064C504;
extern u32 lbl_8064C51C;
extern u32 lbl_8064CA68;

extern void* memset(void*, int, u32);
extern void fn_8001D56C(void);
extern void fn_8001E894(void);
extern void fn_8001F754(void);
extern void fn_8001F758(void);
extern void fn_8001FB94(void);
extern void fn_8001FE1C(void);
extern void fn_8002014C(void);
extern void fn_8001DE68(void);
extern void fn_8001DE84(int, int);
extern u32 fn_80024638(void*, void*, u32*);
extern void fn_80023B40(void);
extern void fn_80042E3C(void);
extern void fn_80042EDC(void);
extern void fn_800B177C(int, void*);
extern void fn_800B2548(int, int);
extern void fn_800B689C(u32, u32);
extern void* fn_80138164(void);
extern void* fn_8015AA0C(void);
extern void* fn_8015AA14(void);
extern void fn_8015D458(void*, void*, void*);
extern void fn_8015DAB0(void*);
extern int fn_801A98F4(int, int);
extern void fn_801A99B4(void);
extern void fn_801AD4B4(u32, u32, u32, u32);
extern void* fn_801E6CA0(void*, int, int, int, int);
extern void fn_801E6F9C(void*, u32);
extern void fn_801E85A8(void);
extern void fn_801EFE84(u32);
extern void fn_8020EF54(void*, void*);
extern void fn_8022A814(u32, u32);

static Timings timings;
static u8 tlut[0xC];
static u16 values[0x100];
static Work work;
static u8 object[0x38];
static Info info;
static u8 head[0x1C];

static u32 table[304] = {
    0x01B400F3, 0xFFFF025B, 0x00F3FFFF, 0x025B0131, 0xFFFF01B4, 0x0131FFFF,
    0x01AB0117, 0xFFFF024A, 0x0117FFFF, 0x024A0154, 0xFFFF01AB, 0x0154FFFF,
    0x01C40143, 0xFFFF022C, 0x0143FFFF, 0x022C017A, 0xFFFF01C4, 0x017AFFFF,
    0x016F015C, 0xFFFF0266, 0x015CFFFF, 0x026601AC, 0xFFFF016F, 0x01ACFFFF,
    0x01BA017E, 0xFFFF0234, 0x017EFFFF, 0x023401B9, 0xFFFF01BA, 0x01B9FFFF,
    0x004000EB, 0xFFFF0101, 0x00EBFFFF, 0x01010119, 0xFFFF0040, 0x0119FFFF,
    0x003B0112, 0xFFFF0133, 0x0112FFFF, 0x01330152, 0xFFFF003B, 0x0152FFFF,
    0x00390140, 0xFFFF0147, 0x0140FFFF, 0x01470185, 0xFFFF0039, 0x0185FFFF,
    0x0036016F, 0xFFFF00D6, 0x016FFFFF, 0x00D601A4, 0xFFFF0036, 0x01A4FFFF,
    0x008C009A, 0xFFFF01F4, 0x009AFFFF, 0x01F40146, 0xFFFF008C, 0x0146FFFF,
    0x009C00A7, 0xFFFF01E4, 0x00A7FFFF, 0x01E40139, 0xFFFF009C, 0x0139FFFF,
    0x011100F4, 0xFFFF0139, 0x00F4FFFF, 0x01390119, 0xFFFF0111, 0x0119FFFF,
    0x011200E8, 0xFFFF0149, 0x00E8FFFF, 0x0149011D, 0xFFFF0112, 0x011DFFFF,
    0x00800035, 0xFFFF0127, 0x0035FFFF, 0x012700FA, 0xFFFF0080, 0x00FAFFFF,
    0x00230000, 0xFFFF0188, 0x0000FFFF, 0x01880156, 0xFFFF0023, 0x0156FFFF,
    0x00440023, 0xFFFF015E, 0x0023FFFF, 0x015E0126, 0xFFFF0044, 0x0126FFFF,
    0x00A50085, 0xFFFF0102, 0x0085FFFF, 0x010200CD, 0xFFFF00A5, 0x00CDFFFF,
    0x00440092, 0xFFFF00B1, 0x0092FFFF, 0x00B100C0, 0xFFFF0044, 0x00C0FFFF,
    0x004000C0, 0xFFFF00C4, 0x00C0FFFF, 0x00C400EA, 0xFFFF0040, 0x00EAFFFF,
    0x00E7009F, 0xFFFF0110, 0x009FFFFF, 0x011000C1, 0xFFFF00E7, 0x00C1FFFF,
    0x00E9008D, 0xFFFF0121, 0x008DFFFF, 0x012100C7, 0xFFFF00E9, 0x00C7FFFF,
    0x00E600C2, 0xFFFF0115, 0x00C2FFFF, 0x011500E9, 0xFFFF00E6, 0x00E9FFFF,
    0x00E600C3, 0xFFFF015E, 0x00C3FFFF, 0x015E00E8, 0xFFFF00E6, 0x00E8FFFF,
    0x00EB0179, 0xFFFF0132, 0x0179FFFF, 0x013201A1, 0xFFFF00EB, 0x01A1FFFF,
    0x00DF0175, 0xFFFF012D, 0x0175FFFF, 0x012D01A4, 0xFFFF00DF, 0x01A4FFFF,
    0x00DF0172, 0xFFFF01A3, 0x0172FFFF, 0x01A301A5, 0xFFFF00DF, 0x01A5FFFF,
    0x0047006F, 0xFFFF00D6, 0x006FFFFF, 0x00D600B5, 0xFFFF0047, 0x00B5FFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0x00000001, 0x00000000, 0x00000000, 0xFFFFFFFF,
    0x000000C8, 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000001, 0x00000000,
    0x00000001, 0x00000001, 0x0000012C, 0x00000001, 0x00000002, 0x00000001,
    0x0000012C, 0x00000001, 0x00000003, 0x00000001, 0x0000012C, 0x00000001,
    0x00000004, 0x00000002, 0x0000012C, 0x00000001, 0x00000005, 0x00000002,
    0x0000012C, 0x00000001, 0x00000006, 0x00000002, 0x0000012C, 0x00000001,
    0x00000007, 0x00000003, 0x0000012C, 0x00000001, 0x00000008, 0x00000003,
    0x0000012C, 0x00000001, 0x00000009, 0x00000003, 0x0000012C, 0x00000001,
    0x0000000A, 0x00000004, 0x0000012C, 0x00000001, 0x0000000B, 0x00000004,
    0x0000012C, 0x00000001, 0x0000000C, 0x00000005, 0x0000012C, 0x00000001,
    0x0000000D, 0x00000005, 0x0000012C, 0x00000001, 0x0000000E, 0x00000005,
    0x0000012C, 0x00000001, 0x0000000F, 0x00000006, 0x0000012C, 0x00000001,
    0x00000010, 0x00000006, 0x0000012C, 0x00000001, 0x00000011, 0x00000006,
    0x0000012C, 0x00000001, 0x0000001B, 0x00000007, 0x0000012C, 0x00000001,
    0x00000012, 0x00000007, 0x0000012C, 0x00000001, 0x00000013, 0x00000007,
    0x0000012C, 0x00000001, 0x00000014, 0x00000008, 0x0000012C, 0x00000001,
    0x00000015, 0x00000008, 0x0000012C, 0x00000001, 0x00000016, 0x00000008,
    0x0000012C, 0x00000001, 0x00000017, 0x00000009, 0x0000012C, 0x00000001,
    0x00000018, 0x00000009, 0x0000012C, 0x00000001, 0x00000019, 0x00000009,
    0x0000012C, 0x00000001, 0x0000001A, 0xFFFFFFFF, 0x000000C8, 0x00000001,
    0xFFFFFFFF, 0xFFFFFFFF, 0x00000004, 0x00000001, 0xFFFFFFFF, 0x0000000A,
    0x00000064, 0x00000001, 0xFFFFFFFF, 0x0000000B, 0x0000012C, 0x00000000,
    0x00000000, 0x00000000, 0x00530000, 0xFFFF022D, 0x0000FFFF, 0x022D01E0,
    0xFFFF0053, 0x01E0FFFF, 0x00000000, 0x00000000
};

static u32 block4C0[6] = {
    0x00000000, 0xFFFF0280, 0x0000FFFF, 0x028001E0, 0xFFFF0000, 0x01E0FFFF
};

static u32 block4D8[48] = {
    0x00000000, 0x02000000, 0x02000200, 0x00000200, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00020000, 0xFFFF0282,
    0x0000FFFF, 0x028201E0, 0xFFFF0002, 0x01E0FFFF, 0x00000000, 0x00000000,
    0x00000002, 0xFFFF0280, 0x0002FFFF, 0x028001E2, 0xFFFF0000, 0x01E2FFFF,
    0x00000000, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005,
    0x00000006, 0x00000007, 0x00000008, 0x0000000A, 0x00000009, 0x0000000B,
    0x00000000, 0x0000000D, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000005,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0000000A, 0x00000009, 0xFFFFFFFF
};

static u32 block5B8[18] = {
    0x00000045, 0x00000155, 0x000000A6, 0x00000096, 0x00000152, 0x000000F9,
    0x0000012F, 0x00000067, 0x00000052, 0x000000ED, 0x0000001B, 0x00000032,
    0x00000064, 0x00000040, 0x00000117, 0x00000027, 0x00000060, 0x00000000
};

static u32 block600[24] = {
    0x00000045, 0x00000155, 0x000000A6, 0x00000096, 0x00000152, 0x000000F9,
    0x0000012F, 0x00000067, 0x00000052, 0x0000001B, 0x000000ED, 0x00000032,
    0x00000064, 0x00000040, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000124,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0000004F, 0x00000117, 0xFFFFFFFF
};

static u32 settings[71] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000000FF, 0x00000004,
    0x00000004, 0x00000001, 0x00000000, 0x00000000, 0x00000001, 0x000000FF,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};

static MenuEntry entries[7] = {
    {0x00000C10, 0, fn_8001F754, 0, 1},
    {0x00001100, 0, fn_8001E894, 0, 1},
    {0x00000200, 0, fn_8001F758, 0, 1},
    {0x200C0000, 0, fn_8001FE1C, 0, 0x3FFFFFFF},
    {0x10030000, 0, fn_8001FB94, 0, 0x3FFF0001},
    {0x00000800, 0, fn_8002014C, 0, 1},
    {0x20CC0000, 0, 0, 0, 0x1FFFFFFF, 0x14, 5},
};

void fn_8001E144(int mode)
{
    fn_8022A814(0, 0);
    memset(&info, 0, 0x44);
    info.limit = 200;
    info.kind = 7;
    info.fade = 255;
    lbl_8064C6C8 = 0;
    lbl_8064C6C4 = 0;
    lbl_8064C670 = 0;
    info.argument = mode;
    info.flags = 0;
    fn_8020EF54(object, "MainMenu");
    lbl_8064C6D0 = 0;
    fn_8001DE84(3, 0);
    fn_8001DE84(3, 0);
    info.fade = 255;
    info.flags |= 0x20;
    timings.first = 2000;
    timings.second = 1000;
    timings.third = 1000;
    timings.fourth = 1000;

    if (mode == 0) {
        fn_801AD4B4(7, 0, 0, 0);
        fn_8001D56C();
        fn_801A99B4();
    }
    {
        Info* active = &info;
        active->handle = 0;
        active->end = 0;

        switch (mode) {
        case 1:
        case 12:
        case 13:
            fn_8001DE84(1, 0);
            fn_8001DE84(1, 0);
            info.fade = 255;
            info.flags |= 1;
            info.flags |= 0x10;
            timings.second = 3000;
            timings.third = 1500;
            timings.fourth = 1500;
        case 0:
            {
                u32 size;
                u32 start = (u32)fn_80138164();
                active->handle = fn_80024638("Nintendo.tpl", (void*)start, &size);
                fn_8015DAB0((void*)active->handle);
                start += (size + 31) & ~31;
                active->end = start;
            }
            if (info.flags & 4) {
                info.resource = fn_801A98F4(629, 100);
                fn_8001DE84(25, 0);
                info.fade = 255;
                info.flags |= 1;
            }
            fn_80042EDC();
            fn_80042E3C();
            break;
        case 3: {
            u32 size;
            void* start = fn_80138164();
            active->handle = fn_80024638("Nintendo.tpl", start, &size);
            fn_8015DAB0((void*)active->handle);
            active->end = (u32)start + ((size + 31) & ~31);
            fn_8015D458("EMnMenu.cmp", (void*)active->end, fn_8015AA14());
            fn_8015DAB0((void*)active->end);
            active->mode = 253;
            break;
        }
        case 4: {
            u32 size;
            void* start = fn_80138164();
            active->handle = fn_80024638("Nintendo.tpl", start, &size);
            fn_8015DAB0((void*)active->handle);
            active->end = (u32)start + ((size + 31) & ~31);
            fn_8015D458("EMnMenu.cmp", (void*)active->end, fn_8015AA14());
            fn_8015DAB0((void*)active->end);
            fn_801E6F9C(fn_801E6CA0(lbl_8064C504, 0, 39, 0, 1), 0);
            active->mode = 254;
            break;
        }
        case 5:
            {
                void* second = fn_8015AA0C();
                u32 size;
                void* start = fn_80138164();
                active->handle = fn_80024638("Nintendo.tpl", start, &size);
                fn_8015DAB0((void*)active->handle);
                active->end = (u32)start + ((size + 31) & ~31);
                fn_8015D458("EMnMenu.cmp", (void*)active->end, fn_8015AA14());
                fn_8015DAB0((void*)active->end);
                lbl_8064C51C = fn_80024638("EMemcardText.bin", second, &size);
            }
            fn_801E85A8();
            lbl_8064CA68 = 1;
            fn_800B177C(1, (void*)fn_80023B40);
            fn_800B689C(0, 1);
            fn_800B2548(12, 0);
            entries[3] = lbl_80238978;
            entries[4] = lbl_80238998;
            fn_8001DE84(27, 0);
            fn_8001DE84(6, 0);
            lbl_8064C6C8 = 1;
            break;
        case 14: {
            u32 size;
            void* start = fn_80138164();
            active->handle = fn_80024638("Nintendo.tpl", start, &size);
            fn_8015DAB0((void*)active->handle);
            active->end = (u32)start + ((size + 31) & ~31);
            fn_8015D458("EMnMenu.cmp", (void*)active->end, fn_8015AA14());
            fn_8015DAB0((void*)active->end);
            active->mode = 252;
            fn_8001DE84(27, 0);
            fn_8001DE84(252, 0);
            fn_801EFE84(0);
            break;
        }
        }
    }

    fn_8001DE68();
}
