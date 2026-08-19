typedef signed int s32;
typedef signed short s16;

typedef struct RuntimeState {
    char pad[8];
    s16 stage;
} RuntimeState;

typedef struct GlobalState {
    char pad[8];
    s32 ready;
} GlobalState;

extern GlobalState lbl_803003C8;
extern void *lbl_8064C4E0;
extern RuntimeState *fn_8006D1DC(s32 size);
extern int fn_801E79FC(void*, int);
extern void fn_801E79A0(void *object, s32 value);

s32 fn_8006B804(void *unused, s32 event)
{
    s32 result = 0;
    RuntimeState *state;

    if (lbl_803003C8.ready != 0) {
        state = fn_8006D1DC(12);
        switch (event) {
        case 0xFF:
            if (fn_801E79FC(lbl_8064C4E0, 0x373) != 0) {
                result = 0;
            }
            break;
        case 0xBA:
            if (state->stage <= 0) {
                result = 1;
                fn_801E79A0(lbl_8064C4E0, 0x3BF);
                state->stage = 0;
            }
            break;
        case 0x131:
            if (state->stage <= 1) {
                result = 1;
                fn_801E79A0(lbl_8064C4E0, 0x3BF);
                state->stage = 1;
            }
            break;
        case 0xC4:
            if (state->stage <= 2 && fn_801E79FC(lbl_8064C4E0, 0x371) != 0) {
                result = 1;
                fn_801E79A0(lbl_8064C4E0, 0x3BF);
                state->stage = 2;
            }
            break;
        case 0xE1:
            if (state->stage <= 3) {
                result = 1;
                fn_801E79A0(lbl_8064C4E0, 0x3BF);
                state->stage = 3;
            }
            break;
        }
    }
    return result;
}
