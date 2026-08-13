typedef unsigned int u32;

typedef struct State80092C30 {
    unsigned char pad00[0x2C];
    u32 flags;
} State80092C30;

extern u32 fn_80036D5C(void*);
extern int fn_80093264(void);

int fn_80092C30(void* object, register State80092C30* state)
{
    int result = 0;

    if (!(fn_80036D5C(object) & 0x80) && !(state->flags & 0x20)) {
        if (state != 0 &&
            ((state->flags & 0x200) || (state->flags & 0x40))) {
            result = 1;
        } else {
            int value = fn_80093264();
            if (value == -1) {
                state->flags |= 0x200;
                result = 1;
            } else if (value != 0) {
                result = 1;
            }
        }
    }
    return result;
}
