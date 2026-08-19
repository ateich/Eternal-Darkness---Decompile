typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Entry8009F07C {
    u8 field_00;
    u8 pad01;
    u8 field_02;
    u8 field_03;
    u8 pad04[0x28];
} Entry8009F07C;

typedef struct State8009F07C {
    u8 pad00[0x18];
    char text[0x50];
    Entry8009F07C entries[1];
} State8009F07C;

typedef struct Context8009F07C {
    u8 pad00[8];
    s16 counter;
    u8 pad0A[0xE];
    u32 flags;
} Context8009F07C;

extern void *fn_8006ED3C();
extern void fn_8006EB60(void);
extern void fn_8006BEE4(Context8009F07C*, void (*)(void));
extern void fn_8006DEF8(State8009F07C*, int, void*, void*, int);
extern void fn_8009F1C4(void);
extern void fn_8009F258(void);
extern void fn_800FD40C(char*, const char*);
extern char lbl_80245528[];

void fn_8009F07C(register State8009F07C* state)
{
    int index;
    Context8009F07C* context;
    int i;

    context = fn_8006ED3C(state, 0x1D, &index);
    context->counter = 0;
    fn_8006BEE4(context, fn_8006EB60);
    state->entries[index].field_02 = 1;
    state->entries[index].field_03 = 1;
    state->entries[index].field_00 = 4;
    fn_8006DEF8(state, 0x1D, fn_8009F1C4, state, 70);
    state->entries[index].field_00 = 0;
    fn_8006DEF8(state, 0x1D, fn_8009F258, state, 0);
    for (i = 1; i < 3; i++) {
        state->entries[index].field_00 = i;
        fn_8006DEF8(state, 0x1D, 0, 0, 1);
    }
    state->entries[index].field_00 = 0;
    context->flags |= 0x14;
    fn_800FD40C(state->text, lbl_80245528);
}
