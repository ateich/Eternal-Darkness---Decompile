typedef unsigned char u8;
typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct ActorState { u8 pad[0x286]; u8 count; } ActorState;

extern float lbl_8064F368;
extern float lbl_8064F394;
extern float lbl_8064F398;
extern void* fn_80201B94();
extern ActorState *fn_800A1D28(void *);
extern void fn_80129108(void *, int, int);
extern void fn_801296F8(void *, int);
extern void fn_8011F6A4(void *, int, int, int, Vec3 *, int);
extern void fn_80211A6C(Vec3 *, Vec3 *, Vec3 *);
extern int fn_800E62F8(Vec3 *, Vec3 *);
extern void fn_800A45B0(ActorState *, int);

int fn_800D373C(void *state, void *object, int alternate)
{
    Vec3 first;
    Vec3 second;
    Vec3 delta;
    ActorState *actor;
    int mode;

    fn_80201B94(object);
    actor = fn_800A1D28(object);
    actor->count++;
    if (actor->count >= 4) {
        fn_80129108(state, 1, 0);
        fn_801296F8(state, 0x10000);
    }
    mode = alternate ? 7 : 6;
    fn_8011F6A4(state, 29, mode, -1, &second, 1);
    fn_8011F6A4(state, 2, mode, -1, &first, 1);
    first.z += lbl_8064F394;
    fn_80211A6C(&first, &second, &delta);
    if (second.z <= lbl_8064F398) {
        second.z = lbl_8064F368;
    }
    fn_800A45B0(actor, fn_800E62F8(&second, &delta));
    return 1;
}
