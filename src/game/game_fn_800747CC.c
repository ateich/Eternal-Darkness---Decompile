typedef unsigned char u8;

typedef struct State {
    u8 pad_00[0x1BD];
    u8 active;
} State;

extern int fn_80128EAC(void *);
extern void *fn_801A7498(void *);
extern void *fn_801A7490(void *);
extern void *fn_80201814();
extern void *fn_80201B8C();
extern void fn_80128BE4(void *);
extern unsigned long long fn_8020123C();

/* NonMatching: behavior-complete paired-object activation handler. Retail and
 * base are equal-sized with identical relocations; MWCC assigns the two
 * callee-saved registers in the opposite order. */
int fn_800747CC(void *object, void *link)
{
    register void *object_r = object;
    register void *resolved = link;
    State *state;
    int type;

    type = fn_80128EAC(object_r);
    if (type == 7) {
        resolved = fn_801A7498(resolved);
        link = fn_801A7490(link);
        state = *(State **)((u8 *)fn_80201B8C(fn_80201814(resolved)) + 0x44);
        state->active = 1;
        fn_80128BE4(object_r);
        fn_8020123C(0x6F, link, link, 0);
    }
    return 1;
}
