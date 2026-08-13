typedef unsigned char u8;

typedef struct Work8009DC54 {
    u8 pad00[0xAC];
    void* field_AC;
    void* field_B0;
    void* field_B4;
    void* field_B8;
} Work8009DC54;

typedef struct State8009DC54 {
    u8 pad00[0xC4];
    Work8009DC54* work;
} State8009DC54;

extern void fn_8006ED98(State8009DC54*);
extern void fn_801A5B70(void*);
extern void fn_801A5BA0(void*);
extern void fn_801A5BD0(void*);
extern void fn_801A5C00(void*);

int fn_8009DC54(register State8009DC54* state)
{
    Work8009DC54* work = state->work;
    fn_8006ED98(state);
    fn_801A5B70(work->field_AC);
    fn_801A5BA0(work->field_B0);
    fn_801A5BD0(work->field_B4);
    fn_801A5C00(work->field_B8);
    return 1;
}
