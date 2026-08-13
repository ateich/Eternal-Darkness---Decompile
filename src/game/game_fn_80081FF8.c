typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

typedef struct GameState {
    u8 pad[0x120];
    s16 type[2];
    s16 value[2];
    u8 pad2[0xA3];
    s8 selection;
} GameState;

extern GameState lbl_8031CBA0;
extern volatile int lbl_8064D18C;
extern void *lbl_8064C4E0;
extern void *lbl_8064C8E8;
extern void *lbl_8064C8EC;

extern void fn_80144680(void *);
extern void fn_801E5FB0(void *);
extern void fn_801E7974(void *, int);
extern void fn_8016B400(int, int, int);
extern void fn_80144C40(void);

void fn_80081FF8(int unused, int unused2)
{
    int alternate = lbl_8064D18C != 0x4E;

    fn_80144680(lbl_8064C8E8);
    lbl_8031CBA0.selection = -1;
    fn_801E5FB0(lbl_8064C8EC);
    lbl_8064C8E8 = 0;
    lbl_8064C8EC = 0;

    if (lbl_8031CBA0.type[alternate] == 3 &&
        lbl_8031CBA0.value[alternate] >= 340 &&
        lbl_8031CBA0.value[alternate] <= 346) {
        if (lbl_8064D18C == 0x4E) {
            fn_801E7974(lbl_8064C4E0, 0x289);
            fn_8016B400(0x85E, 0, 0);
        } else {
            fn_801E7974(lbl_8064C4E0, 0x12E);
            fn_8016B400(0xA4F, 0, 0);
        }
    } else if (lbl_8064D18C == 0x4E) {
        fn_8016B400(0x60F, 0, 0);
    } else {
        fn_8016B400(0x30E, 0, 0);
    }
    fn_80144C40();
}
