typedef unsigned char u8;
typedef unsigned int u32;

typedef struct RuntimeState {
    u8 pad_00[0x34];
    u32 first_handle;
    u32 second_handle;
} RuntimeState;

extern u8 lbl_803003C8[];
extern RuntimeState lbl_8030241C;
extern int lbl_8064D18C;
extern u32 lbl_8064CCF4;
extern int lbl_8064C6A0;
extern int lbl_8064C69C;

extern void fn_801E8DB4(void);
extern void fn_800427E0(int);
extern int fn_80045230(void);
extern void fn_800451C4(int);
extern void fn_80054B04(void);
extern void fn_800E4648(void);
extern void fn_801A9964(u32);
extern void fn_8001D9FC(int);

void fn_80020D90(int mode)
{
    fn_801E8DB4();

    lbl_8064D18C = 96;
    *(int *)(lbl_803003C8 + 8) = 16;
    *(int *)(lbl_803003C8 + 0) = 0;
    *(int *)(lbl_803003C8 + 4) = 0;
    lbl_803003C8[0x1914] = 0;
    *(unsigned short *)(lbl_803003C8 + 0x1916) = 0;
    lbl_803003C8[0x191A] = 0;
    fn_800427E0(0);

    if (mode != 0) {
        fn_800451C4(fn_80045230());
        if ((u8)fn_80045230()) {
            lbl_8064CCF4 = *(u32 *)(lbl_803003C8 + 0x191C);
        }
        fn_80054B04();
    } else {
        fn_800451C4(0);
    }

    lbl_8064C6A0 = 96;
    lbl_8064C69C = -1;
    fn_800E4648();

    if (lbl_8030241C.first_handle != (u32)-1) {
        fn_801A9964(lbl_8030241C.first_handle);
        lbl_8030241C.first_handle = (u32)-1;
    }
    if (lbl_8030241C.second_handle != (u32)-1) {
        fn_801A9964(lbl_8030241C.second_handle);
        lbl_8030241C.second_handle = (u32)-1;
    }
    fn_8001D9FC(1);
}
