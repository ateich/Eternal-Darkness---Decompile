typedef unsigned char u8;

typedef struct ModeState {
    u8 pad[8];
    int mode;
} ModeState;

typedef struct RuntimeState {
    u8 pad[0x628];
    void *resource;
} RuntimeState;

extern ModeState lbl_803003C8;
extern RuntimeState lbl_8031CD84;
extern int lbl_8064C904;
extern int lbl_8064C908;

extern int fn_801AF8E4(int);
extern void fn_8011E310(int, int, int, int, int, int, int);
extern int fn_801E7578(void *);

void fn_800812E4(int unused, int event)
{
    if (event == 1) {
        if (lbl_803003C8.mode == 0xD) {
            if (lbl_8064C904 != -1 && fn_801AF8E4(lbl_8064C904) != 0) {
                lbl_8064C904 = -1;
                lbl_8064C908 = 0;
            }
            if (lbl_8064C908 == 0) {
                fn_8011E310(2, 0x3C, 0, 0, 0x32, 0, 0);
            }
        } else if (fn_801E7578(lbl_8031CD84.resource) <= 1) {
            fn_8011E310(2, 0x3E, 0, 0, 0x32, 0, 0);
        } else {
            fn_8011E310(2, 0x2F, 0, 0, 0x32, 0, 0);
        }
    }
}
