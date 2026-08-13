typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Entry8009F534 {
    u8 field_00;
    u8 pad01;
    u8 field_02;
    u8 field_03;
    u8 pad04[0x28];
} Entry8009F534;

typedef struct State8009F534 {
    u8 pad00[0x18];
    char text[0x50];
    Entry8009F534 entries[1];
} State8009F534;

typedef struct Context8009F534 {
    u8 pad00[8];
    s16 counter;
} Context8009F534;

extern Context8009F534* fn_8006ED3C(State8009F534*, int, int*);
extern void fn_8006EB60(void);
extern void fn_8006BEE4(Context8009F534*, void (*)(void));
extern void fn_8006DEF8(State8009F534*, int, void*, void*, int);
extern void fn_8009F664(void);
extern void fn_8009F700(void);
extern void fn_800FD40C(char*, const char*);
extern char lbl_8024555C[];

void fn_8009F534(register State8009F534* state)
{
    int index;
    Context8009F534* context;
    int i;

    context = fn_8006ED3C(state, 10, &index);
    context->counter = 0;
    fn_8006BEE4(context, fn_8006EB60);
    state->entries[index].field_02 = 0;
    state->entries[index].field_03 = 0;
    state->entries[index].field_00 = 4;
    fn_8006DEF8(state, 10, fn_8009F664, state, 1);
    state->entries[index].field_00 = 0;
    fn_8006DEF8(state, 10, fn_8009F700, state, 1);
    for (i = 1; i < 3; i++) {
        state->entries[index].field_00 = i;
        fn_8006DEF8(state, 10, 0, 0, 1);
    }
    state->entries[index].field_00 = 0;
    fn_800FD40C(state->text, lbl_8024555C);
}
