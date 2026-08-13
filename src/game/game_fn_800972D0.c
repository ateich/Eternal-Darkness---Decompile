typedef unsigned char u8;
typedef unsigned int u32;

typedef struct State800972D0 {
    u8 pad00[0x28];
    u32 actor_id;
} State800972D0;

extern void* fn_80201BC8(void*);
extern int fn_80095D10(void*);
extern int fn_80095E64(void*, int);
extern int fn_80200C38(void*);
extern int fn_80200C20(void*);
extern void* fn_80201814(int);
extern void fn_80201D2C(void*, int);
extern void fn_80201D14(void*, int);
extern int fn_80201B54(void*);
extern int fn_80095FDC(void*, void*, int, State800972D0*, int);
extern void fn_80201138(int, void*, int, int, int, float);
extern const float lbl_8064ECE8;

int fn_800972D0(register void* object, register void* random,
                register State800972D0* state, void* unused,
                register int* output)
{
    register void* room;
    register int result;
    register int mode;
    register void* actor;

    result = 0;
    room = fn_80201BC8(object);
    mode = fn_80095D10(object);
    if (mode != 0 && fn_80095E64(object, mode) != 0) {
        if (fn_80200C38(random) == 1) {
            state->actor_id = fn_80200C20(random);
            actor = fn_80201814(state->actor_id);
            if (mode == 2 || mode == 7) {
                result = 1;
                fn_80201D2C(object, 0x47);
                fn_80201D14(object, 1);
            } else {
                fn_80095FDC(object, room, fn_80201B54(object), state, 0);
                fn_80201138(6, actor, 0x47, 2, 0, lbl_8064ECE8);
            }
        }
        if (output != 0) {
            *output = 1;
        }
    }
    return result;
}
