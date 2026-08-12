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
extern void *fn_80201B8C();

s32 fn_800360B0(void* object, u16* flags)
{
    InnerObject* inner;

    if (object != 0) {
        inner = ((Object*)fn_80201B8C(object))->inner;
        if (inner != 0) {
            *flags = inner->flags;
            return 1;
        }
    }
    return 0;
}
