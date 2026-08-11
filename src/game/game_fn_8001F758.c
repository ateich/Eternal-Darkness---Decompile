typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef struct RuntimeState {
    u8 pad_00[0x1C];
    s32 value;
    s32 previous_value;
    u8 pad_24[4];
    s32 state;
    s32 counter;
    u32 flags;
    u8 pad_34[4];
    u32 handle;
    u8 pad_3C[2];
    u8 mode;
    u8 previous_mode;
} RuntimeState;

typedef struct Block {
    u32 words[8];
} Block;

extern RuntimeState lbl_8030241C;
extern s32 lbl_803003C8[];
extern u8 lbl_803026DC[];
extern u8 lbl_8023D77C[];
extern Block lbl_80238B04;

extern s32 lbl_8064C6D0;
extern u32 lbl_8064C650;
extern s32 lbl_8064B2C0;
extern void* lbl_8064C4E0;
extern void* lbl_8064CE80;

extern void fn_80144C40(void);
extern void fn_8001DA18(void);
extern void fn_800B283C(void);
extern void fn_8001DFEC(s32, s32);
extern s32 fn_800B193C(void);
extern void fn_8001DE68(void);
extern unsigned int fn_801A98F4(int, int);
extern void fn_8001DE84(int, int);
extern void fn_801E7974(void*, int);
extern void fn_801E79A0(void*, s32);
extern void fn_801A9964(u32);
extern s32 fn_800AFCD0(void*);
extern void fn_800B177C(s32, void*);
extern void fn_800B689C(s32, s32);
extern void fn_800B2548(s32, s32);
extern void fn_800236A0(s32);
extern void fn_80023674(void);
extern void fn_8001FE1C(void);
extern void fn_801E8AC4(void*);
extern void fn_801F85A4(void);
extern void fn_8011C830(s32);

void fn_8001F758(void)
{
    RuntimeState* runtime;
    u8 mode;

    fn_80144C40();
    runtime = &lbl_8030241C;
    mode = runtime->mode;

    switch (mode) {
    case 1:
    case 2:
    case 23:
    case 24:
    case 25:
    case 26:
        lbl_8030241C.flags |= 1;
        fn_8001DA18();
        break;

    case 3:
        lbl_8064C6D0++;
        break;

    case 4:
    case 5:
    case 6:
        fn_800B283C();
        break;

    case 250:
        if (lbl_803003C8[2] == 1) {
            if (lbl_8030241C.counter == 0) {
                lbl_8030241C.counter = 12;
            } else if (lbl_8030241C.counter <= 12) {
                lbl_8030241C.counter--;
            }
            fn_8001DFEC(9, lbl_8030241C.counter);
            lbl_8030241C.state = 12;
        } else {
            fn_8001DFEC(11, lbl_803003C8[3] - 1);
            lbl_8030241C.state = 3;
        }
        break;

    case 30:
        if (fn_800B193C() != 0) {
            fn_800B283C();
        } else {
            fn_8001DE68();
            lbl_8064C650 = fn_801A98F4(0x2D2, 100);
            fn_8001DE84(9, 0);
            fn_801E7974(lbl_8064C4E0, 0x37E);
            lbl_8030241C.state = 12;
            fn_801E79A0(lbl_8064C4E0, 13);
        }
        break;

    case 8:
        if (fn_800B193C() != 0) {
            fn_800B283C();
        } else {
            lbl_8030241C.handle = fn_801A98F4(0x275, 100);
            fn_8001DE68();
            fn_8001DE84(7, 0);
            fn_8001DA18();
            lbl_8030241C.state = 5;
        }
        break;

    case 13:
        fn_800B283C();
        break;

    case 14:
        if (fn_800B193C() != 0) {
            fn_800B283C();
        } else if (fn_800AFCD0(lbl_803026DC) != 0) {
            fn_800B177C(1, fn_80023674);
            fn_800B689C(0, 1);
            fn_800B2548(11, 0);
        } else {
            fn_800236A0(1);
        }
        break;

    case 9:
    case 17:
        fn_8001DE84(7, 3);
        fn_801A9964(lbl_8064C650);
        lbl_8030241C.handle = fn_801A98F4(0x2D4, 100);
        fn_8001DA18();
        lbl_8030241C.state = 5;
        break;

    case 11:
    case 20:
    case 21:
        if (lbl_8030241C.counter == 0) {
            lbl_8030241C.counter = 12;
        } else if (lbl_8030241C.counter <= 12) {
            lbl_8030241C.counter--;
        }
        fn_8001DFEC(9, lbl_8030241C.counter);
        lbl_8030241C.state = 12;
        break;

    case 22:
        fn_8001DFEC(17, lbl_8030241C.counter - 12);
        lbl_8030241C.state = 12;
        break;

    case 15:
        *(void**)(lbl_8023D77C + 0x68) = fn_8001FE1C;
        *(u32*)(lbl_8023D77C + 0xC8) = 0;
        fn_801E8AC4(lbl_8064CE80);
        fn_8001DE84(14, 5);
        lbl_8064B2C0 = 1;
        lbl_8030241C.state = 7;
        break;

    case 16:
        runtime->previous_mode = mode;
        runtime->mode = 14;
        runtime->previous_value = runtime->value;
        runtime->value = 4;
        runtime->state = 7;
        lbl_8064B2C0 = 1;
        *(Block*)(lbl_8023D77C + 0x80) = lbl_80238B04;
        fn_801F85A4();
        fn_8011C830(0);
        break;
    }
}
