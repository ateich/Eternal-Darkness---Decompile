typedef unsigned char u8;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct State {
    u8 pad[0x284];
    short timer;
} State;

extern void* fn_801A7498(void *);
extern void *fn_80201814();
extern State *fn_800A1D28(void *);
extern int fn_8003BD48(void *, void *);
extern int fn_80201B54();
extern void *fn_801A74B8(void *);
extern void fn_800A37CC(int, void *, void *);
extern int fn_801A7468(void *);
extern void fn_8011F114();
extern int fn_8011F6A4(void *, int, int, int, Vec3 *, int);
extern void fn_80211A6C();
extern float fn_80211B08(Vec3 *);

/* Honest C reconstruction; stack scheduling and register allocation remain open. */
int fn_800D082C(void *object, void *context)
{
    void *owner;
    State *state;
    int id;
    int kind;
    int variant = 0;
    Vec3 position;
    Vec3 transformed;
    Vec3 work;
    Vec3 output;

    fn_801A7498(context);
    owner = fn_80201814();
    state = fn_800A1D28(owner);
    if (state->timer != 0 || !(fn_8003BD48(object, context) & 3)) {
        return 1;
    }

    id = fn_80201B54(owner);
    fn_800A37CC(id, fn_801A74B8(context), context);
    state->timer = 210;
    kind = fn_801A7468(context);
    fn_8011F114(&position, object);

    if (kind == 4 || kind == 6) {
        variant = 7;
    } else if (kind == 5 || kind == 7) {
        variant = 6;
    } else if (kind == 25) {
        variant = -1;
    }

    fn_8011F6A4(object, 2, variant, -1, &transformed, 1);
    fn_80211A6C(&work, &output, &position);
    fn_80211B08(&position);
    fn_8011F6A4(object, 3, variant, -1, &transformed, 1);
    fn_80211A6C(&work, &output, &position);
    fn_80211B08(&position);
    fn_8011F6A4(object, 28, variant, -1, &transformed, 1);
    fn_80211A6C(&work, &output, &position);
    fn_80211B08(&position);
    fn_8011F6A4(object, 29, variant, -1, &transformed, 1);
    fn_80211A6C(&work, &output, &position);
    fn_80211B08(&position);
    return 1;
}
