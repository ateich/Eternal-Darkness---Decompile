typedef unsigned char u8;
typedef unsigned int u32;

typedef struct State800A0018 {
    u8 pad00[0x18];
    char text[0x50];
    u8 field_68;
    u8 pad69;
    u8 field_6A;
    u8 field_6B;
} State800A0018;

typedef struct Context800A0018 {
    int mode;
    u8 pad04[4];
    short counter;
    u8 pad0A[0xE];
    u32 flags;
} Context800A0018;

extern Context800A0018* fn_8006ED98(State800A0018*);
extern void fn_8006EB60(void);
extern void fn_8006BEE4(Context800A0018*, void (*)(void));
extern void fn_8006DEF8(State800A0018*, int, void*, void*, int);
extern void fn_800A0140(void);
extern void fn_800FD40C(char*, const char*);
extern char lbl_802455B8[];
extern char lbl_802455D0[];
extern float lbl_8064C930;
extern float lbl_8064C934;
extern float lbl_8064EE0C;
extern float lbl_8064EE10;
extern float lbl_8064EE14;
extern float lbl_8064EE18;

void fn_800A0018(register State800A0018* state)
{
    Context800A0018* context;
    int i;

    context = fn_8006ED98(state);
    fn_8006BEE4(context, fn_8006EB60);
    state->field_6A = 1;
    state->field_6B = 4;
    state->field_68 = 4;
    fn_8006DEF8(state, context->mode, fn_800A0140, state, 10);

    for (i = 0; i < 3; i++) {
        state->field_68 = i;
        fn_8006DEF8(state, context->mode, fn_800A0140, state, 5);
    }

    state->field_68 = 0;
    switch (context->mode) {
    case 0x21:
        lbl_8064C934 = lbl_8064EE0C;
        lbl_8064C930 = lbl_8064EE10;
        fn_800FD40C(state->text, lbl_802455B8);
        break;
    default:
        lbl_8064C934 = lbl_8064EE14;
        lbl_8064C930 = lbl_8064EE18;
        fn_800FD40C(state->text, lbl_802455D0);
        break;
    }

    context->counter = 0;
    context->flags |= 0x10;
}
