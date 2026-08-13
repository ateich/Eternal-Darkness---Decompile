typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

#pragma use_lmw_stmw on

typedef struct Info {
    u8 pad_00[0x3A];
    u8 value;
    u8 count;
    u8 limit;
} Info;

typedef struct State {
    u8 pad_00[0x1C0];
    u8 ready;
} State;

typedef struct World {
    u8 pad_00[0x44];
    State *state;
    u8 pad_48[0x48];
    void *info_handle;
} World;

typedef struct Status {
    u16 flags;
} Status;

extern int fn_800FBFB0(void);
extern void *fn_80201B8C();
extern Info *fn_80072354(void *);
extern void fn_800360B0(void *, Status *);
extern int fn_80066D04(void *, int);

/* NonMatching: behavior-complete randomized state-selection helper. Remaining
 * differences are MWCC callee-saved allocation and a redundant branch after
 * the low-bit test; all calls and data accesses are recovered in honest C. */
int fn_80074864(void *object, void *unused, int *kind, u16 *count, u8 *value)
{
    register int result;
    register State *state;
    register u8 *value_r;
    register u16 *count_r;
    register int *kind_r;
    register void *object_r;
    register Info *info;
    register s8 limit;
    register int random_value;
    World *world;
    Status status;

    object_r = object;
    kind_r = kind;
    count_r = count;
    value_r = value;
    random_value = fn_800FBFB0() % 100;
    *kind_r = -1;
    *value_r = 0;
    result = 0;
    world = fn_80201B8C(object_r);
    state = world->state;
    info = fn_80072354(world->info_handle);
    fn_800360B0(object_r, &status);
    limit = info->limit;
    if (fn_80066D04(object_r, 3) == 0) {
        status.flags |= 1;
    }
    if (fn_80066D04(object_r, 2) == 0) {
        status.flags |= 2;
    }
    if ((status.flags & 0x80) == 0) {
        if ((status.flags & 1) == 0) {
            if (random_value <= limit || state->ready != 0) {
                *kind_r = 7;
                result = 1;
                *value_r = info->value;
                *count_r = info->count;
                state->ready = 0;
            }
        }
    }
    return result;
}
