typedef unsigned short u16;
typedef int s32;

typedef struct InnerObject {
    unsigned char pad_00[0x144];
    u16 flags;
} InnerObject;

typedef struct Object {
    unsigned char pad_00[0x8C];
    InnerObject* inner;
} Object;

extern Object* fn_80201B8C(void*);

s32 fn_80036060(void* object, u16 flags)
{
    InnerObject* inner;

    if (object != 0) {
        inner = fn_80201B8C(object)->inner;
        if (inner != 0) {
            inner->flags = flags;
            return 1;
        }
    }
    return 0;
}
