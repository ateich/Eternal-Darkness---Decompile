typedef unsigned char u8;

typedef struct State {
    u8 pad[0x90];
    u8 flags;
} State;

extern void *lbl_803251E4[3];
extern int lbl_8064CA88;
extern int lbl_8064B714;

extern State **fn_80201B8C();
extern void *fn_80200C38(void *);
extern void fn_801A7324(void *, void *);
extern void fn_801A74D8(void *, int);

void fn_800C4AA0(void *context, void *resource_id, void **out)
{
    State **state_ref = fn_80201B8C(context);
    void *resource = fn_80200C38(resource_id);
    State *state = *state_ref;

    resource_id = 0;

    if (lbl_8064CA88 < 3) {
        fn_801A7324(resource, lbl_803251E4[lbl_8064CA88]);
        resource_id = lbl_803251E4[lbl_8064CA88];
        fn_801A74D8(resource_id, 2);
        if (lbl_8064B714 == -1) {
            lbl_8064B714 = lbl_8064CA88;
        }
        lbl_8064CA88++;
        state->flags |= 0x10;
    }
    if (out != 0) {
        *out = resource_id;
    }
}
