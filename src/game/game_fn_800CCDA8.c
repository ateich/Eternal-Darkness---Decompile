typedef unsigned char u8;

typedef struct RuntimeState {
    u8 pad[0x9E];
    u8 group;
    u8 kind;
} RuntimeState;

extern void *fn_80201B9C();
extern RuntimeState *fn_80201B8C();
extern int fn_80201EB8(void *);
extern void *fn_80201BC8();
extern void *fn_80201BC0(void *);
extern void fn_8012C478(void *, int, int);

#pragma use_lmw_stmw on
void fn_800CCDA8(int mode, int owner)
{
    void *object = fn_80201B9C();
    while (object != 0) {
        RuntimeState *state = fn_80201B8C(object);
        if (state != 0 && owner == fn_80201EB8(object) &&
            state->group == 2 && state->kind == 4) {
            void *resource = fn_80201BC8(object);
            if (resource != 0) {
                if (mode != 0) {
                    fn_8012C478(resource, 15, 0);
                } else {
                    fn_8012C478(resource, 15, 1);
                }
            }
        }
        object = fn_80201BC0(object);
    }
}
