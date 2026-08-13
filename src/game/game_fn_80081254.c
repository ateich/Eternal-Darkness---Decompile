typedef unsigned char u8;
typedef signed char s8;

typedef struct RuntimeState {
    u8 pad[0x418];
    int counter;
} RuntimeState;

typedef struct GameState {
    u8 pad[0x1CB];
    s8 selection;
} GameState;

extern RuntimeState lbl_8031CD84;
extern GameState lbl_8031CBA0;
extern void *lbl_8064C8E8;
extern void *lbl_8064C8EC;

extern void fn_8007D744(int);
extern void fn_80144680(void *);
extern void fn_801E5FB0(void *);
extern void fn_800073B0(void);
extern void fn_8016B400(int, int, int);

void fn_80081254(int unused, int event)
{
    if (event == 1) {
        if (lbl_8031CD84.counter != 0) {
            lbl_8031CD84.counter--;
            fn_8007D744(7);
        } else {
            fn_80144680(lbl_8064C8E8);
            lbl_8031CBA0.selection = -1;
            lbl_8064C8E8 = 0;
            fn_801E5FB0(lbl_8064C8EC);
            lbl_8064C8EC = 0;
            fn_800073B0();
            fn_8016B400(0x7EB, 0, 0);
        }
    }
}
