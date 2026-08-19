typedef unsigned char u8;
typedef signed short s16;

typedef struct Entry8009E39C {
    u8 field_00;
    u8 pad01;
    u8 field_02;
    u8 field_03;
    u8 pad04[0x28];
} Entry8009E39C;

typedef struct State8009E39C {
    u8 pad00[0x18];
    char text[0x50];
    Entry8009E39C entries[1];
} State8009E39C;

typedef struct Context8009E39C {
    u8 pad00[8];
    s16 counter;
} Context8009E39C;

extern void *fn_8006ED3C();
extern void fn_8006EB60(void);
extern void fn_8006BEE4(Context8009E39C*, void (*)(void));
extern void fn_8006C9E4(Context8009E39C*, int);
extern void fn_8006DEF8(State8009E39C*, int, void (*)(void), void*, int);
extern void fn_8009E4BC(void);
extern void fn_8009E5C4(void);
extern void fn_800FD40C(char*, const char*);
extern char lbl_80245464[];

void fn_8009E39C(register State8009E39C* state)
{
    int index;
    Context8009E39C* context;
    register int i;
    context = fn_8006ED3C(state, 0x16, &index);
    fn_8006BEE4(context, fn_8006EB60);
    fn_8006C9E4(context, 0);
    context->counter = 0;
    state->entries[index].field_02 = 1;
    state->entries[index].field_03 = 4;
    state->entries[index].field_00 = 4;
    fn_8006DEF8(state, 0x16, fn_8009E5C4, state, 0);
    for (i = 0; i < 3; i++) {
        state->entries[index].field_00 = i;
        fn_8006DEF8(state, 0x16, fn_8009E4BC, state, 0x1E);
    }
    state->entries[index].field_00 = 0;
    fn_800FD40C(state->text, lbl_80245464);
}
