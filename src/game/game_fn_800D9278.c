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

int fn_800D9278(void *unused, void *object)
{
    Runtime *runtime = fn_800A1D28(object);
    void *owner;
    void *attached;
    void *candidate;

    (void)unused;
    fn_800A1CD0(object);
    owner = fn_80201B94(object);
    attached = ((void *)fn_80201B54(object));
    candidate = fn_80201C48(owner);
    if (candidate != 0) {
        Vec3 position;
        void *source = fn_80201BC8(fn_80201814(candidate));
        int distance;
        unsigned long long result;

        fn_8011F114(&position, source);
        distance = fn_80179064((int)runtime->source.x, (int)runtime->source.y,
                              (int)position.x, (int)position.y);
        result = fn_8020123C(0x99, attached, candidate, 0);
        if (distance > 175 || (unsigned int)result != 0) {
            runtime->flags |= 0x10;
        } else {
            runtime->destination = position;
        }
    }
    return 1;
}
