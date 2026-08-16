typedef struct CallbackState {
    unsigned char pad0[4];
    int target;
    int done;
    unsigned char padC[0x16];
    unsigned short status;
    unsigned char pad24[0x20];
    int timer;
} CallbackState;

typedef struct Inner {
    unsigned char pad0[0xA4];
    signed char active;
    unsigned char value;
} Inner;

typedef struct Outer {
    unsigned char pad0[0x5C];
    Inner* inner;
} Outer;

extern CallbackState* fn_801FD6F4(void*);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern Outer*fn_80201B8C();
extern void* fn_8011F130(void*);
extern void fn_801FDEB4(void*, void*);
extern void fn_801FDF74(void*, int);
extern int fn_801FE05C(void*);

int fn_800AA6F4(void* object)
{
    CallbackState* state = fn_801FD6F4(object);

    if (state != 0 && state->done == 0) {
        void* target = fn_80201814((void*)state->target);
        if (target != 0) {
            void* position = fn_80201BC8(target);
            Outer* outer = fn_80201B8C(target);
            Inner* inner = outer->inner;

            if (inner->active == 1) {
                void* point = fn_8011F130(position);
                fn_801FDEB4(object, point);
                if (state->timer < 100000) {
                    fn_801FDF74(object, state->timer + 3125);
                }
            } else {
                inner->value = 0;
                state->done = 1;
            }
        } else {
            state->done = 1;
        }
    } else if (fn_801FE05C(object) != 0) {
        state->status = 2;
    }
    return 0;
}
