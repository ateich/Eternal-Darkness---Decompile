typedef unsigned char u8;
typedef unsigned int u32;

typedef struct RuntimeState {
    u8 pad[0x9E];
    u8 kind;
} RuntimeState;

extern int lbl_8064D18C;
extern const float lbl_8064F29C;
extern void *fn_80201B9C(void);
extern RuntimeState *fn_80201B8C(void *);
extern int fn_80201EB8(void *);
extern u32 fn_80201B54(void *);
extern void *fn_80201BC0(void *);
extern void fn_8020123C(int, u32, u32, void *);
extern void fn_8020104C(int, u32, u32, void *, float);

#pragma use_lmw_stmw on
int fn_800CAB80(int mode)
{
    void *object;
    int count;

    object = fn_80201B9C();
    count = 0;
    while (object != 0) {
        RuntimeState *state = fn_80201B8C(object);
        int owner = fn_80201EB8(object);
        u32 handle = fn_80201B54(object);

        if (state != 0 && lbl_8064D18C == owner && state->kind == 2) {
            switch (mode) {
            case 0:
                fn_8020123C(0x39, handle, handle, 0);
                break;
            case 1:
                fn_8020104C(0x39, handle, handle, 0, lbl_8064F29C);
                break;
            }
            count++;
        }
        object = fn_80201BC0(object);
    }
    return count;
}
