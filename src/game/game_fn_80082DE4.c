typedef unsigned char u8;
typedef signed char s8;

typedef struct GameState {
    u8 pad[0x1CB];
    s8 selection;
} GameState;

typedef struct RuntimeState {
    u8 pad[0x498];
    void *resources[3];
} RuntimeState;

extern GameState lbl_8031CBA0;
extern RuntimeState lbl_8031CD84;
extern int lbl_8064D18C;
extern void *lbl_8064C8E8;
extern void *lbl_8064C8EC;

extern void fn_80144680(void *);
extern void fn_801E5FB0(void *);
extern void fn_80144C40(void);
extern void fn_8016B400(int, int, int);

void fn_80082DE4(void)
{
    fn_80144680(lbl_8064C8E8);
    lbl_8031CBA0.selection = -1;
    fn_801E5FB0(lbl_8064C8EC);
    lbl_8064C8E8 = 0;
    lbl_8064C8EC = 0;
    fn_80144C40();

    fn_801E5FB0(lbl_8031CD84.resources[0]);
    fn_801E5FB0(lbl_8031CD84.resources[1]);
    fn_801E5FB0(lbl_8031CD84.resources[2]);
    lbl_8031CD84.resources[0] = 0;
    lbl_8031CD84.resources[1] = 0;
    lbl_8031CD84.resources[2] = 0;

    switch (lbl_8064D18C) {
    case 0xDA:
        fn_8016B400(0x8D5, 0, 0);
        break;
    case 0x47:
        fn_8016B400(0x23F, 0, 0);
        break;
    default:
        fn_8016B400(0x8CE, 0, 0);
        break;
    }
}
