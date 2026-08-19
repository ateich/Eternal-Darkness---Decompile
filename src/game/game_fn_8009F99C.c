typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry8009F99C {
    u8 field_00;
    u8 pad01;
    u8 field_02;
    u8 field_03;
    u8 pad04[0x28];
} Entry8009F99C;

typedef struct State8009F99C {
    u8 pad00[0x18];
    char text[0x50];
    Entry8009F99C entries[1];
} State8009F99C;

typedef struct Context8009F99C {
    u8 pad00[8];
    short counter;
} Context8009F99C;

extern void *fn_8006ED3C();
extern void fn_8006EB60(void);
extern void fn_8006BEE4(Context8009F99C*, void (*)(void));
extern void fn_8006DEF8(State8009F99C*, int, void*, void*, int);
extern void fn_8006E20C(void);
extern void fn_8009FB0C(void);
extern void fn_8009FE98(void);
extern char* fn_800FD40C(char*, const char*);
extern u8 fn_801A9B28(void);
extern u8 fn_801A9B30(void);
extern char lbl_8024558C[];
extern u32 lbl_8064C938;
extern u32 lbl_8064C93C;
extern u32 lbl_8064C9DC;
extern u32 lbl_8064C9E0;

void fn_8009F99C(register State8009F99C* state)
{
    int index;
    Context8009F99C* context;

    context = fn_8006ED3C(state, 4, &index);
    context->counter = 0;
    fn_8006BEE4(context, fn_8006EB60);

    state->entries[index].field_02 = 0;
    state->entries[index].field_03 = 0;
    state->entries[index].field_00 = 4;
    fn_8006DEF8(state, 4, fn_8009FB0C, state, 0);

    state->entries[index].field_00 = 0;
    fn_8006DEF8(state, 4, fn_8006E20C, state, 10);

    state->entries[index].field_00 = 1;
    fn_8006DEF8(state, 4, fn_8009FE98, state, 10);

    state->entries[index].field_00 = 2;
    fn_8006DEF8(state, 4, 0, 0, 0);

    state->entries[index].field_00 = 0;
    fn_800FD40C(state->text, lbl_8024558C);
    lbl_8064C93C = 0;
    lbl_8064C938 = 0;
    lbl_8064C9E0 = fn_801A9B28();
    lbl_8064C9DC = fn_801A9B30();
}
