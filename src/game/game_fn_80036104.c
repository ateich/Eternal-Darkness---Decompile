typedef int s32;

typedef struct InnerObject {
    unsigned char pad_00[0x1C];
    s32 value;
} InnerObject;

typedef struct Object {
    unsigned char pad_00[0x8C];
    InnerObject* inner;
} Object;

extern float lbl_8064E1F8;

extern s32 fn_801A7498(void*);
extern void* fn_80201814();
extern void* fn_80201B8C();
extern unsigned long long fn_8020123C();
extern void fn_8020104C(int, void*, void*, int, float);
#define fn_8020104C(a, b, c, d, e) fn_8020104C((a), (void*)(b), (void*)(c), (d), (e))
extern void fn_80128BE4(void*);

s32 fn_80036104(void* object, void* argument)
{
    register InnerObject* inner;
    register unsigned long argument_r = (unsigned long)argument;
    register s32 id;

    id = fn_801A7498((void*)argument_r);
    inner = ((Object*)fn_80201B8C(fn_80201814(id)))->inner;
    fn_8020123C(0x2F, id, inner->value, (void*)argument_r);
    fn_8020104C(0x30, id, inner->value, (int)argument_r,
                lbl_8064E1F8);
    fn_80128BE4(object);
    return 1;
}
