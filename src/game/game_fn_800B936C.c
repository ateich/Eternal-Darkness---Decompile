typedef unsigned char u8;
typedef signed short s16;

typedef struct GameState {
    u8 pad[0x1914];
    u8 ready;
    u8 pad1915;
    s16 value;
} GameState;

extern GameState lbl_803003C8;
extern int lbl_8064CDC8;
extern void fn_802021EC(void);
extern void fn_801570AC(void (*)(void));
extern void fn_80155D9C(int);
extern void fn_8006E53C(void);
extern int fn_800B05F8(void *);

void fn_800B936C(void)
{
    fn_801570AC(fn_802021EC);
    if (lbl_8064CDC8 == 3) {
        fn_80155D9C(0);
    }
    fn_8006E53C();
    fn_801570AC(fn_802021EC);
    lbl_803003C8.value = fn_800B05F8((u8 *)&lbl_803003C8 + 0x14);
    lbl_803003C8.ready = 1;
    if (lbl_8064CDC8 == 3) {
        fn_80155D9C(1);
    }
}
