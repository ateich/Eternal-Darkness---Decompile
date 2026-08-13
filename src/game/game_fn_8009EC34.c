typedef unsigned char u8;
typedef signed short s16;

typedef struct Entry8009EC34 {
    u8 field_00;
    u8 pad01;
    u8 field_02;
    u8 field_03;
    u8 pad04[0x28];
} Entry8009EC34;

typedef struct State8009EC34 {
    u8 pad00[0x18];
    char text[0x50];
    Entry8009EC34 entries[1];
} State8009EC34;

typedef struct Context8009EC34 {
    u8 pad00[8];
    s16 counter;
} Context8009EC34;

extern Context8009EC34* fn_8006ED3C(State8009EC34*, int, int*);
extern void fn_8006EB60(void);
extern void fn_8006BEE4(Context8009EC34*, void (*)(void));
extern void fn_8006C9E4(Context8009EC34*, int);
extern void fn_8006DEF8(State8009EC34*, int, void*, void*, int);
extern void fn_800FD40C(char*, const char*);
extern char lbl_802454FC[];

void fn_8009EC34(register State8009EC34* state)
{
    int index;
    Context8009EC34* context;
    register int i;

    context = fn_8006ED3C(state, 0x1E, &index);
    fn_8006BEE4(context, fn_8006EB60);
    fn_8006C9E4(context, 0);
    state->entries[index].field_02 = 1;
    state->entries[index].field_03 = 4;
    state->entries[index].field_00 = 4;
    fn_8006DEF8(state, 0x1E, 0, 0, 0);
    for (i = 0; i < 3; i++) {
        state->entries[index].field_00 = i;
        fn_8006DEF8(state, 0x1E, 0, 0, 0);
    }
    state->entries[index].field_00 = 0;
    context->counter = 0;
    fn_800FD40C(state->text, lbl_802454FC);
}
