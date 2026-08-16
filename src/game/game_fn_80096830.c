typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Candidate80096830 {
    u8 pad00[0x14];
    u32 value;
} Candidate80096830;

typedef struct State80096830 {
    u8 pad00[0xCC];
    void* query;
} State80096830;

typedef struct ObjectData80096830 {
    u8 pad00[0x8C];
    State80096830* state;
} ObjectData80096830;

extern const double lbl_8064EC90;
extern const float lbl_8064ECBC;
extern const double lbl_8064ECD8;

extern void *fn_80201B8C();
extern void fn_80201E78(Vec3*, void*);
extern void *fn_801294DC(void *, int, int, int);
extern Candidate80096830* fn_800935CC(int, void*, void*, int);
extern unsigned int fn_80178E94(Vec3*, Vec3*);
extern int fn_80200C38();
extern void fn_80128C44(void*, void*, int);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_80201138(int, void*, int, int, int, float);
extern void fn_80204810(void);

void fn_80096830(register int index, register void* object,
                 void* resource, void* random_context)
{
    register State80096830* state;
    register Candidate80096830* candidate;
    register void* action;
    register void* random;
    unsigned int distance;
    register float value;
    Vec3 position;

    action = resource;
    random = random_context;
    state = ((ObjectData80096830*)fn_80201B8C(object))->state;
    fn_80201E78(&position, object);
    action = fn_801294DC(action, 0x8E, 0x31, 8);
    if (action != 0) {
        candidate = fn_800935CC(0, 0, state->query, 4);
        distance = fn_80178E94((Vec3*)((u8*)candidate + 4), &position);
        if (candidate != 0 && distance < 0x50) {
            value = lbl_8064ECBC + (float)candidate->value;
        } else {
            value = lbl_8064ECBC + (float)fn_80200C38(random);
        }
        fn_80128C44(action, fn_80204810, (index << 8) | 7);
        fn_80201D2C(object, 0x4F);
        fn_80201D14(object, 1);
        fn_80201138(5, object, 0x4F, -1, 0, value);
    }
}
