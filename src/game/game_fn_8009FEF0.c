typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry8009FEF0 {
    u8 field_00;
    u8 pad01;
    u8 field_02;
    u8 field_03;
    u8 pad04[0x28];
} Entry8009FEF0;

typedef struct State8009FEF0 {
    u8 pad00[0x18];
    char text[0x50];
    Entry8009FEF0 entries[1];
} State8009FEF0;

typedef struct Context8009FEF0 {
    u8 pad00[8];
    short counter;
    u8 pad0A[0xE];
    u32 flags;
} Context8009FEF0;

extern void *fn_8006ED3C();
extern void fn_8006EB60(void);
extern void fn_8006BEE4(Context8009FEF0*, void (*)(void));
extern void fn_8006DEF8(State8009FEF0*, int, void*, void*, int);
extern void fn_8009DBE4(void);
extern void fn_8009EF8C(void);
extern char* fn_800FD40C(char*, const char*);
extern char lbl_802455A0[];

void fn_8009FEF0(register State8009FEF0* state)
{
    int index;
    Context8009FEF0* context;
    int i;

    context = fn_8006ED3C(state, 16, &index);
    fn_8006BEE4(context, fn_8006EB60);
    state->entries[index].field_02 = 1;
    state->entries[index].field_03 = 4;
    context->counter = 0;
    state->entries[index].field_00 = 4;
    fn_8006DEF8(state, 16, fn_8009DBE4, state, 0);

    for (i = 0; i < 3; i++) {
        state->entries[index].field_00 = i;
        fn_8006DEF8(state, 16, fn_8009EF8C, state, 100);
    }

    state->entries[index].field_00 = 0;
    context->flags |= 0x4014;
    fn_800FD40C(state->text, lbl_802455A0);
}
