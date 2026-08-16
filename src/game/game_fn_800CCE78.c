typedef unsigned char u8;

typedef struct RuntimeState {
    u8 pad[0x9E];
    u8 group;
    u8 kind;
} RuntimeState;

extern const float lbl_8064F308;
extern void *fn_80201B9C(void);
extern RuntimeState *fn_80201B8C(void *);
extern int fn_80201EB8(void *);
extern void *fn_80201BC0(void *);
extern void fn_800C96D4(void *, int, int, int, int, int, float);

#pragma use_lmw_stmw on
void fn_800CCE78(int mode, int owner)
{
    void *object = fn_80201B9C();
    while (object != 0) {
        RuntimeState *state = fn_80201B8C(object);
        if (state != 0 && owner == fn_80201EB8(object) &&
            state->group == 2 && state->kind == 6) {
            if (mode != 0) {
                fn_800C96D4(object, 255, -5, 0, 100, 1, lbl_8064F308);
            } else {
                fn_800C96D4(object, 0, 5, 255, 100, 1, lbl_8064F308);
            }
        }
        object = fn_80201BC0(object);
    }
}
