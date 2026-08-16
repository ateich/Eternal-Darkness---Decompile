typedef struct GameState {
    unsigned char pad[8];
    int mode;
} GameState;

extern int lbl_8064D5A8;
extern GameState lbl_803003C8;
extern void *fn_80201BC8();
extern int fn_80128EE4(void *);
extern int fn_80038308(void *, int, short *);
extern void fn_800389E0(void *, int, short, int);

void fn_800BEB04(void *object)
{
    int interval;
    short value;
    void *child;
    int flags;

    if (object == 0) {
        return;
    }

    child = fn_80201BC8(object);
    flags = child != 0 ? fn_80128EE4(child) : 0;
    interval = -1;
    if (((unsigned char)flags) & 0x2F) {
        interval = 40;
    }

    if (interval != -1 && lbl_8064D5A8 % interval == 0 &&
        fn_80038308(object, 2, &value)) {
        if (lbl_803003C8.mode == 12 || lbl_803003C8.mode == 0 ||
            lbl_803003C8.mode == 13) {
            value += 2;
        } else {
            value += 1;
        }
        fn_800389E0(object, 2, value, 0);
    }
}
