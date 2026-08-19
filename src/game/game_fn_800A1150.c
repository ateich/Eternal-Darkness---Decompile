typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry800A1150 {
    u8 field_00;
    u8 pad01;
    u8 field_02;
    u8 field_03;
    u8 pad04[0x28];
} Entry800A1150;

typedef struct State800A1150 {
    u8 pad00[0x18];
    char text[0x50];
    Entry800A1150 entries[1];
} State800A1150;

typedef struct Context800A1150 {
    u32 event;
    u8 pad04[4];
    short counter;
    u8 pad0A[0xE];
    u32 flags;
} Context800A1150;

extern void *fn_8006ED3C();
extern void fn_8006EB60(void);
extern void fn_8006BEE4(Context800A1150*, void (*)(void));
extern void fn_8006DEF8(State800A1150*, int, void*, void*, int);
extern void fn_800A1278(void);
extern void fn_800FD40C(char*, const char*);
extern char lbl_802456B8[];

void fn_800A1150(register State800A1150* state)
{
    int index;
    Context800A1150* context;
    int i;

    context = fn_8006ED3C(state, 0x23, &index);
    fn_8006BEE4(context, fn_8006EB60);

    state->entries[index].field_02 = 1;
    state->entries[index].field_03 = 4;
    state->entries[index].field_00 = 4;
    fn_8006DEF8(state, context->event, fn_800A1278, state, 10);

    for (i = 0; i < 3; i++) {
        state->entries[index].field_00 = i;
        fn_8006DEF8(state, context->event, fn_800A1278, state, 5);
    }

    state->entries[index].field_00 = 0;
    fn_800FD40C(state->text, lbl_802456B8);
    context->counter = 0;
    context->flags |= 0x10;
}
