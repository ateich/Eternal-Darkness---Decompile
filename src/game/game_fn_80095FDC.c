typedef unsigned char u8;
typedef unsigned int u32;

typedef struct State80095FDC {
    void* object0;
    void* object4;
    int value8;
    int valueC;
    int value10;
    int value14;
    int value18;
    int value1C;
    int value20;
    int value24;
    u8 pad28[4];
    u32 flags;
} State80095FDC;

extern void* lbl_8064C50C;
extern int lbl_8064D1BC;
extern int lbl_8064D1C4;
extern int lbl_8064D1DC;
extern int lbl_8064D1E0;

extern int fn_80128EAC(void*);
extern void fn_8012B344(void*);
extern int fn_80095D10(void*);
extern int fn_80095E64(void*, unsigned int);
extern int fn_8011EB04(void*);
extern void* fn_801E6CA0(void*, int, int, int, int);
extern void fn_80027730(void*, int, int);
extern void fn_8020123C(int, void*, void*, void*);
extern void fn_8016B400(void*, int, int);

int fn_80095FDC(register void* object, register void* owner,
                register int value, register State80095FDC* state,
                register int preserve_owner)
{
    register int mode;
    int kind;

    kind = fn_80128EAC(owner);
    if (preserve_owner != 0 && kind != 47) {
        fn_8012B344(owner);
    }
    state->flags &= ~2U;
    mode = fn_80095D10(object);
    fn_80095E64(object, mode);

    switch (mode) {
    case 7: {
        int slot;
        switch (fn_8011EB04(owner)) {
        case 103:
            slot = 2;
            break;
        case 132:
            slot = 3;
            break;
        case 105:
        case 107:
            slot = 1;
            break;
        case 133:
            slot = 0;
            break;
        case 117:
            slot = 4;
            break;
        default:
            slot = 0;
            break;
        }
        fn_80027730(fn_801E6CA0(lbl_8064C50C, 7, slot, 0, 1), 0, 0);
        state->flags &= ~0x400U;
        break;
    }
    case 1:
        fn_8020123C(0x5B, (void*)value, (void*)value, state->object0);
        state->object0 = 0;
        break;
    case 2:
        if (lbl_8064D1BC != 0) {
            lbl_8064D1C4 = (int)state->object4;
            lbl_8064D1E0 = value;
            lbl_8064D1DC = 0;
        } else {
            fn_8016B400(state->object4, value, 0);
        }
        state->flags |= 2;
        break;
    case 3:
        fn_80027730(fn_801E6CA0(lbl_8064C50C, state->value10,
                               state->value14, 0, 1), 0, 0);
        break;
    case 4:
        fn_80027730(fn_801E6CA0(lbl_8064C50C, state->value8,
                               state->valueC, 0, 1), 0, 0);
        break;
    case 5:
        fn_80027730(fn_801E6CA0(lbl_8064C50C, state->value20,
                               state->value24, 0, 1), 0, 0);
        break;
    case 6:
        fn_80027730(fn_801E6CA0(lbl_8064C50C, state->value18,
                               state->value1C, 0, 1), 0, 0);
        break;
    }
    return 1;
}
