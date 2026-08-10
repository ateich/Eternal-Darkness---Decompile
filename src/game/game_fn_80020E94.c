typedef unsigned char u8;
typedef unsigned int u32;

typedef struct RuntimeState {
    u8 pad_00[0x2C];
    u32 table_index;
    u32 pad_30;
    u32 first_handle;
} RuntimeState;

extern u8 lbl_803003C8[];
extern RuntimeState lbl_8030241C;
extern int lbl_8023D600[];
extern int lbl_8064B2BC;
extern void* lbl_8064C4E0;
extern u32 lbl_8064CCF4;
extern int lbl_8064D18C;
extern void* lbl_8064D74C;

extern void fn_801EFE84(int);
extern void fn_8001E644(int, int, int);
extern void fn_801E7974(void*, int);
extern u32 fn_8015AA0C(void);
extern u32 fn_80024638(void*, u32, u32*);
extern void fn_8015DAB0(void);
extern void fn_800242B8(u32);
extern void fn_801EF530(void);
extern void fn_801EF580(void*);
extern void fn_801EB194(int);
extern void fn_801AD404(int, int, int);
extern void fn_801AD4B4(int, int, int, int);
extern void fn_801A99B4(void);
extern int fn_801AD898(void);
extern void fn_800073DC(int);
extern void fn_801E8DB4(void);
extern void fn_801A9964(u32);
extern int fn_80045230(void);
extern void fn_80054B04(void);
extern void fn_8001D9FC(int);

extern char lbl_8023DA60[];

void fn_80020E94(void)
{
    int i;
    u32 mode;
    u32 size;

    lbl_8064B2BC = 5;
    mode = *(u32*)(lbl_803003C8 + 8);
    fn_801EFE84(1);

    switch (mode) {
    case 0:
        if (lbl_8023D600[lbl_8030241C.table_index] == 100) {
            mode = 16;
        }
        break;
    case 10:
        mode = 9;
        break;
    case 9:
        mode = 10;
        break;
    case 15:
        mode = 10;
        break;
    }

    for (i = 0; i < (int)mode; i++) {
        switch (i) {
        case 9:
            fn_8001E644(10, 0, 1);
            break;
        case 10:
            fn_8001E644(9, 0, 1);
            break;
        default:
            fn_8001E644(i, 0, 1);
            break;
        }
    }

    switch (*(u32*)(lbl_803003C8 + 8)) {
    case 0:
    case 1:
    case 16:
        break;
    case 12:
    case 13:
    default:
        fn_801E7974(lbl_8064C4E0, 0x25C);
        fn_801E7974(lbl_8064C4E0, 0x25B);
        /* fall through */
    case 8:
    case 9:
    case 10:
    case 11:
    case 14:
    case 15:
        fn_801E7974(lbl_8064C4E0, 0xAA);
        fn_801E7974(lbl_8064C4E0, 0xA9);
        /* fall through */
    case 6:
    case 7:
        fn_801E7974(lbl_8064C4E0, 0x25D);
        fn_801E7974(lbl_8064C4E0, 0x25E);
        /* fall through */
    case 4:
    case 5:
        fn_801E7974(lbl_8064C4E0, 0x1F5);
        fn_801E7974(lbl_8064C4E0, 0x1F6);
        fn_801E7974(lbl_8064C4E0, 0x3DF);
        fn_801E7974(lbl_8064C4E0, 0x3E0);
        fn_801E7974(lbl_8064C4E0, 0x3B);
        fn_801E7974(lbl_8064C4E0, 0x3D);
        fn_801E7974(lbl_8064C4E0, 0x3C);
        fn_801E7974(lbl_8064C4E0, 0x26E);
        fn_801E7974(lbl_8064C4E0, 0x34F);
        fn_801E7974(lbl_8064C4E0, 0x25A);
        fn_801E7974(lbl_8064C4E0, 0x259);
        fn_801E7974(lbl_8064C4E0, 0x1F3);
        fn_801E7974(lbl_8064C4E0, 0x1F4);
        fn_801E7974(lbl_8064C4E0, 0x3DD);
        fn_801E7974(lbl_8064C4E0, 0x3DE);
        fn_801E7974(lbl_8064C4E0, 0x10A);
        fn_801E7974(lbl_8064C4E0, 0x258);
        fn_801E7974(lbl_8064C4E0, 0x257);
        /* fall through */
    case 3:
        fn_801E7974(lbl_8064C4E0, 0x2CD);
        fn_801E7974(lbl_8064C4E0, 0x2CC);
        /* fall through */
    case 2:
        fn_801E7974(lbl_8064C4E0, 0x360);
        fn_801E7974(lbl_8064C4E0, 0x2B6);
        break;
    }

    {
        u32 input = fn_8015AA0C();
        u32 resource = fn_80024638(lbl_8023DA60, input, &size);
        int j;

        fn_8015DAB0();
        for (j = 0; j < 2; j++) {
            fn_800242B8(resource);
        }
    }
    fn_801EF530();
    fn_801EF580(lbl_8064D74C);
    fn_801EB194(1);
    fn_801AD404(100, 100, 1);
    fn_801AD4B4(105, 0, 1, 0);
    while (fn_801AD898() == 0) {
        fn_801A99B4();
    }
    fn_800073DC(3);
    fn_801E8DB4();

    lbl_8064D18C = lbl_8023D600[lbl_8030241C.table_index];
    fn_801E7974(lbl_8064C4E0, 0x1E2);
    if (lbl_8030241C.first_handle != (u32)-1) {
        fn_801A9964(lbl_8030241C.first_handle);
        lbl_8030241C.first_handle = (u32)-1;
    }
    if ((u8)fn_80045230()) {
        lbl_8064CCF4 = *(u32*)(lbl_803003C8 + 0x191C);
        fn_80054B04();
    }
    fn_8001D9FC(1);
}
