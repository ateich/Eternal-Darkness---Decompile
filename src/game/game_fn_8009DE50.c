typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry8009DE50 {
    u8 field_00;
    u8 pad01[0x2B];
} Entry8009DE50;

typedef struct State8009DE50 {
    u8 pad00[0x18];
    char text[0x50];
    Entry8009DE50 entries[1];
} State8009DE50;

typedef struct Context8009DE50 {
    u8 pad00[0x18];
    u32 flags;
} Context8009DE50;

extern Context8009DE50* fn_8006ED3C(State8009DE50*, int, int*);
extern void fn_8006EA4C(void);
extern void fn_8006BEE4(Context8009DE50*, void (*)(void));
extern void fn_8006DEF8(State8009DE50*, int, void*, void*, int);
extern void fn_800FD40C(char*, const char*);
extern char lbl_80245430[];

void fn_8009DE50(register State8009DE50* state)
{
    int index;
    register int i;
    Context8009DE50* context = fn_8006ED3C(state, 0x15, &index);
    fn_8006BEE4(context, fn_8006EA4C);
    state->entries[index].field_00 = 4;
    fn_8006DEF8(state, 0x15, 0, 0, 0);
    for (i = 0; i < 3; i++) {
        state->entries[index].field_00 = i;
        fn_8006DEF8(state, 0x15, 0, 0, 0);
    }
    state->entries[index].field_00 = 0;
    context->flags |= 0x2004;
    fn_800FD40C(state->text, lbl_80245430);
}
