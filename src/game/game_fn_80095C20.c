typedef unsigned int u32;

typedef struct State80095C20 {
    unsigned char pad00[0x2C];
    u32 flags;
} State80095C20;

extern int lbl_8064D5A8;

extern void fn_80094DD0(void*, void*, void*);
extern int fn_80036D5C(void*);
extern int fn_80093264(void);
extern void *fn_801294DC(void *, int, int, int);
extern void fn_80128C28(void*, void*, int);
extern void fn_80204810(void);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

void fn_80095C20(register void* object, register void* resource,
                 register int index, register State80095C20* state)
{
    register void* action;
    register u32 flags;

    fn_80094DD0(object, resource, 0);
    flags = state->flags;
    if ((flags & 8) == 0 && (lbl_8064D5A8 & 0x3F) == 0 &&
        (((flags & 0x40) == 0 && (flags & 0x200) == 0) ||
         (fn_80036D5C(object) & 0x80) != 0) &&
        fn_80093264() == 0) {
        action = fn_801294DC(resource, 0x9D, 0x24, 6);
        if (action != 0) {
            state->flags |= 8;
            fn_80128C28(action, fn_80204810, (index << 8) | 6);
        } else {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
        }
    }
}
