typedef unsigned char u8;
typedef signed short s16;

typedef struct Entry8009ED44 {
    u8 field_00;
    u8 pad01;
    u8 field_02;
    u8 field_03;
    u8 pad04[0x28];
} Entry8009ED44;

typedef struct Owner8009ED44 {
    u8 pad00[0x15C];
    u8* resource;
} Owner8009ED44;

typedef struct State8009ED44 {
    u8 pad00[0x18];
    char text[0x50];
    Entry8009ED44 entries[1];
    u8 pad94[0x30];
    Owner8009ED44* owner;
} State8009ED44;

typedef struct Context8009ED44 {
    u8 pad00[8];
    s16 counter;
} Context8009ED44;

extern Context8009ED44* fn_8006ED3C(State8009ED44*, int, int*);
extern void fn_8006EA4C(void);
extern void fn_8006BEE4(Context8009ED44*, void (*)(void));
extern void fn_8006DEF8(State8009ED44*, int, void*, void*, int);
extern void fn_8009EEBC(void);
extern void* memset(void*, int, unsigned int);
extern void fn_800FD40C(char*, const char*);
extern char lbl_80245514[];

void fn_8009ED44(register State8009ED44* state)
{
    int index;
    Context8009ED44* context;
    u8* resource;

    context = fn_8006ED3C(state, 0xE, &index);
    resource = state->owner->resource;
    context->counter = 0;
    fn_8006BEE4(context, fn_8006EA4C);
    state->entries[index].field_02 = 0;
    state->entries[index].field_03 = 4;
    memset(resource, 0, 0xB00);
    memset(resource + 0xB00, 0, 0xC40);
    state->entries[index].field_00 = 4;
    fn_8006DEF8(state, 0xE, fn_8009EEBC, state, 10);
    state->entries[index].field_00 = 0;
    fn_8006DEF8(state, 0xE, 0, 0, 0);
    state->entries[index].field_00 = 1;
    fn_8006DEF8(state, 0xE, 0, 0, 0);
    state->entries[index].field_00 = 2;
    fn_8006DEF8(state, 0xE, 0, 0, 0);
    state->entries[index].field_00 = 0;
    fn_800FD40C(state->text, lbl_80245514);
}
