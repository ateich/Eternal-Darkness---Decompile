typedef unsigned char u8;
typedef unsigned int u32;

typedef struct ActorWork {
    u8 pad00[0x20];
    u32 flags;
} ActorWork;

typedef struct Actor {
    u8 pad00[0x38];
    void* object_id;
    u8 pad3C[0x88];
    ActorWork* work;
} Actor;

typedef struct ObjectInfo {
    u8 pad00[0x38];
    Actor* actor;
} ObjectInfo;

typedef struct GlobalState {
    u8 pad00[8];
    int mode;
} GlobalState;

extern void* fn_80201B9C();
extern ObjectInfo* fn_80204844(void*, int);
extern void *fn_80201B8C();
extern int fn_8006BCE4(Actor*);
extern int fn_80070A6C(int);
extern int fn_801E79FC(void*, int);
extern int lbl_8064D18C;
extern GlobalState lbl_803003C8;
extern void* lbl_8064C4E0;

int fn_800A1060(void)
{
    int result = 0;
    ObjectInfo* object;
    Actor* actor;
    ActorWork* work;
    int kind;

    object = fn_80204844(fn_80201B9C(), 0x20);
    if (object != 0) {
        actor = ((ObjectInfo*)fn_80201B8C(object))->actor;
        if (actor != 0) {
            kind = fn_8006BCE4(actor);
            work = actor->work;
            switch (kind) {
            case 4:
            case 9:
            case 11:
            case 16:
            case 17:
            case 18:
            case 19:
            case 22:
            case 29:
            case 32:
            case 33:
            case 34:
            case 35:
            case 36:
                result = 1;
                break;
            case 13:
                result = 1;
                if ((work->flags & 4) != 0) {
                    result = 0;
                }
                break;
            }
            if (fn_80070A6C(0x20000) != 0) {
                result = 1;
            }
        }
    }
    if (lbl_8064D18C == 0xFF && lbl_803003C8.mode == 5 &&
        fn_801E79FC(lbl_8064C4E0, 0x373) != 0) {
        result = 1;
    }
    return result;
}
