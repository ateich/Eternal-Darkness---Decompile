typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry8009FB0C {
    u8 field_00;
    u8 pad01[3];
    u8 pad04[0x28];
} Entry8009FB0C;

typedef struct State8009FB0C {
    u8 pad00[0x68];
    Entry8009FB0C entries[1];
} State8009FB0C;

typedef struct Context8009FB0C {
    u8 pad00[8];
    short counter;
} Context8009FB0C;

extern void *fn_8006ED3C();
extern void fn_8009FD08(void);
extern int fn_80070CD8(int);
extern void* fn_8006D488(State8009FB0C*);
extern void fn_8011E174(int, int);
extern void fn_802020B4(void*, int);
extern void fn_801A5C30(int);
extern int fn_801AF824(void*);
extern void* fn_801B05E8(int, int, int, int, int, int, int, int);
extern u8 fn_801A9B28(void);
extern u8 fn_801A9B30(void);
extern void fn_801A9A40(int, int, int);
extern void fn_8006EA4C(void);
extern void fn_8006BEE4(Context8009FB0C*, void (*)(void));
extern void fn_8006DEF8(State8009FB0C*, int, void*, void*, int);
extern void* lbl_8064B638;
extern void* lbl_8064C8C4;
extern int lbl_8064C938;
extern int lbl_8064C93C;
extern u32 lbl_8064C9DC;
extern u32 lbl_8064C9E0;

int fn_8009FB0C(register State8009FB0C* state)
{
    int result = 0;
    int index;
    Context8009FB0C* context;
    int status;
    void* linked;
    int i;

    context = fn_8006ED3C(state, 4, &index);
    lbl_8064C8C4 = fn_8009FD08;
    status = fn_80070CD8(0);
    context->counter++;
    linked = fn_8006D488(state);
    fn_8011E174(0x100, 1);

    if (context->counter == 1) {
        fn_802020B4(linked, 0);
        fn_801A5C30(0);
        if (fn_801AF824(lbl_8064B638) == 0) {
            lbl_8064B638 = fn_801B05E8(20, 100, 6, 1, 0, 5, 0, 0);
        }
        lbl_8064C9E0 = fn_801A9B28();
        lbl_8064C9DC = fn_801A9B30();
        fn_801A9A40(5, 0, 0);
    }

    if (context->counter > 100) {
        fn_8006BEE4(context, fn_8006EA4C);
        fn_801A9A40(5, lbl_8064C9E0, lbl_8064C9DC);
        result = 1;
    }

    if (status == 0) {
        fn_801A9A40(5, lbl_8064C9E0, lbl_8064C9DC);
        lbl_8064C8C4 = 0;
        fn_8006BEE4(context, fn_8006EA4C);
        for (i = 0; i < 4; i++) {
            state->entries[index].field_00 = i;
            fn_8006DEF8(state, 4, 0, 0, 1);
        }
        fn_801A5C30(1);
        fn_802020B4(linked, 1);
        result = 1;
    }

    lbl_8064C93C += 100;
    if (lbl_8064C93C > 239) {
        lbl_8064C93C = 239;
    }
    if (lbl_8064C93C >= 239) {
        lbl_8064C938 += 40;
    }
    if (lbl_8064C938 > 320) {
        lbl_8064C938 = 320;
    }
    return result;
}
