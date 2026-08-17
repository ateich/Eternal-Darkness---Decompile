typedef struct GameState {
    int pad[2];
    int mode;
} GameState;

extern void* fn_80201C24();
extern int fn_80201B54();
extern unsigned char fn_80157AB8(void *);
extern int fn_801D1AC0(int);
extern int fn_801E79FC(void *, int);
extern void fn_801E7974(void *, int);
extern void fn_801D1318(int);
extern GameState lbl_803003C8;
extern void *lbl_8064C4E0;
extern int lbl_8064C5D8;

void fn_800DB150(void *context)
{
    void *object = fn_80201C24(context);
    int owner = fn_80201B54(context);

    if (object != 0 && (fn_80157AB8(object) || fn_801D1AC0(owner))) {
        if (lbl_803003C8.mode == 3 && fn_801E79FC(lbl_8064C4E0, 0x258) == 0) {
            fn_801E7974(lbl_8064C4E0, 0x257);
            lbl_8064C5D8 = 1;
        }
        fn_801D1318(0);
    }
}
