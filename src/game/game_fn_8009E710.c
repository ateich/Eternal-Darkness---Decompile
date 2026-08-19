typedef unsigned char u8;

typedef struct Entry8009E710 {
    u8 field_00;
    u8 pad01;
    u8 field_02;
    u8 field_03;
    u8 pad04[0x28];
} Entry8009E710;

typedef struct State8009E710 {
    u8 pad00[0x18];
    char text[0x50];
    Entry8009E710 entries[1];
} State8009E710;

extern void *fn_8006ED3C();
extern void fn_8006BEE4(void*, void (*)(void));
extern void fn_8006EB60(void);
extern void fn_8006DEF8(State8009E710*, int, void (*)(void), void*, int);
extern void fn_8009E808(void);
extern void fn_800FD40C(char*, const char*);
extern char lbl_802454C8[];

void fn_8009E710(register State8009E710* state)
{
    int index;
    register int i;
    void* context = fn_8006ED3C(state, 0xC, &index);

    fn_8006BEE4(context, fn_8006EB60);
    state->entries[index].field_02 = 1;
    state->entries[index].field_03 = 4;
    state->entries[index].field_00 = 4;
    fn_8006DEF8(state, 0xC, fn_8009E808, state, 0);
    for (i = 0; i < 3; i++) {
        state->entries[index].field_00 = i;
        fn_8006DEF8(state, 0xC, 0, 0, 0);
    }
    state->entries[index].field_00 = 0;
    fn_800FD40C(state->text, lbl_802454C8);
}
