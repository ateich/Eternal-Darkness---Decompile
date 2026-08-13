typedef unsigned char u8;

typedef struct Work8009DBE4 {
    u8 pad00[0xAC];
    void* field_AC;
    void* field_B0;
    void* field_B4;
    void* field_B8;
} Work8009DBE4;

typedef struct State8009DBE4 {
    u8 pad00[0xC4];
    Work8009DBE4* work;
} State8009DBE4;

extern void fn_8006ED98(State8009DBE4*);
extern void fn_80027F0C(void);
extern void* fn_801A5B70(void*);
extern void* fn_801A5BA0(void*);
extern void* fn_801A5BD0(void*);
extern void* fn_801A5C00(void*);

int fn_8009DBE4(register State8009DBE4* state)
{
    Work8009DBE4* work = state->work;
    fn_8006ED98(state);
    work->field_AC = fn_801A5B70(fn_80027F0C);
    work->field_B0 = fn_801A5BA0(fn_80027F0C);
    work->field_B4 = fn_801A5BD0(fn_80027F0C);
    work->field_B8 = fn_801A5C00(fn_80027F0C);
    return 1;
}
