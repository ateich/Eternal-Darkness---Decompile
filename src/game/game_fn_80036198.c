typedef int s32;

typedef struct InnerObject {
    unsigned char pad_00[0x1C];
    s32 value;
} InnerObject;

typedef struct Object {
    unsigned char pad_00[0x8C];
    InnerObject* inner;
} Object;

extern s32 fn_801A7498(void*);
extern void* fn_80201814(void);
extern Object* fn_80201B8C(void*);
extern void fn_8020123C(s32, s32, s32, void*);

s32 fn_80036198(void* object, void* argument)
{
    register InnerObject* inner;
    register unsigned long argument_r = (unsigned long)argument;
    register s32 id;

    id = fn_801A7498((void*)argument_r);
    inner = fn_80201B8C(fn_80201814())->inner;
    fn_8020123C(0x30, id, inner->value, (void*)argument_r);
    return 1;
}
