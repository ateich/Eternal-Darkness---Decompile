typedef unsigned char u8;

typedef struct Work8009DDC8 {
    u8 pad00[0xAC];
    void* field_AC;
} Work8009DDC8;

typedef struct State8009DDC8 {
    u8 pad00[0xC4];
    Work8009DDC8* work;
} State8009DDC8;

extern void* fn_8006ED3C(State8009DDC8*, int, int*);
extern void fn_80027F0C(void);
extern void* fn_801A5BA0(void*);

int fn_8009DDC8(register State8009DDC8* state)
{
    int index;
    Work8009DDC8* work = state->work;
    fn_8006ED3C(state, 0x13, &index);
    work->field_AC = fn_801A5BA0(fn_80027F0C);
    return 1;
}
