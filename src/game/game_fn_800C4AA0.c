typedef unsigned char u8;

typedef struct State {
    u8 pad[0x90];
    u8 flags;
} State;

extern void *lbl_803251E4[3];
extern int lbl_8064CA88;
extern int lbl_8064B714;

extern void *fn_80201B8C();
extern int fn_80200C38();
extern void fn_801A7324(void *, void *);
extern void fn_801A74D8(void *, int);

void fn_800C4AA0(void *object, void *id, void **out)
{
    void *context = object;
    void *handle = id;
    State **state_ref = ((State **)fn_80201B8C(context));
    void *resource = (void *)fn_80200C38(handle);
    State *state = *state_ref;

    handle = 0;

    if (lbl_8064CA88 < 3) {
        fn_801A7324(resource, lbl_803251E4[lbl_8064CA88]);
        handle = lbl_803251E4[lbl_8064CA88];
        fn_801A74D8(lbl_803251E4[lbl_8064CA88], 2);
        if (lbl_8064B714 == -1) {
            lbl_8064B714 = lbl_8064CA88;
        }
        lbl_8064CA88++;
        state->flags |= 0x10;
    }
    if (out != 0) {
        *out = handle;
    }
}
