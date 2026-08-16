typedef signed char s8;
typedef unsigned int u32;

typedef struct Vec3 {
    u32 x;
    u32 y;
    u32 z;
} Vec3;

typedef struct ActorState {
    char pad_000[0x25C];
    s8 active;
} ActorState;

extern const Vec3 lbl_8023994C;
extern ActorState *fn_800A1D28(void *);
extern void fn_8012B690(void *, Vec3 *, Vec3 *);
extern int fn_800A4DD4(void *, Vec3 *, int, int);

int fn_800D3410(void *state, void *object, int value)
{
    int result = 0;
    ActorState *actor = fn_800A1D28(state);

    if (actor->active == 0) {
        Vec3 position = lbl_8023994C;
        fn_8012B690(object, &position, &position);
        result = fn_800A4DD4(state, &position, value, 120);
    }
    return result;
}
