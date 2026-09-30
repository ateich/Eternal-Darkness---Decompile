typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Runtime {
    u8 pad0[0x6C];
    Vec3 source;
    Vec3 destination;
    u16 flags;
} Runtime;

extern Runtime *fn_800A1D28(void *);
extern void *fn_800A1CD0(void *);
extern void* fn_80201B94();
extern int fn_80201B54();
extern void *fn_80201C48(void *);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void fn_8011F114();
extern int fn_80179064(int, int, int, int);
extern unsigned long long fn_8020123C();

#pragma opt_propagation off
int fn_800D9278(void *unused, void *object)
{
    void *saved_object;
    Runtime *runtime;
    void *attached;
    void *candidate;
    void *owner;

    saved_object = object;
    runtime = fn_800A1D28(saved_object);
    fn_800A1CD0(saved_object);
    owner = fn_80201B94(saved_object);
    attached = (void *)fn_80201B54(saved_object);
    candidate = fn_80201C48(owner);
    if (candidate != 0) {
        Vec3 position;
        void *source = fn_80201BC8(fn_80201814(candidate));
        int distance;
        unsigned long long result;
        unsigned int low;

        fn_8011F114(&position, source);
        distance = fn_80179064((int)runtime->source.x, (int)runtime->source.y,
                              (int)position.x, (int)position.y);
        result = fn_8020123C(0x99, attached, candidate, 0);
        low = result & 0xFFFFFFFFULL;
        if (distance > 175 || low == 0) {
            runtime->destination = position;
        } else {
            runtime->flags |= 0x10;
        }
    }
    return 1;
}
#pragma opt_propagation reset
