typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

typedef struct Inner {
    u8 pad[0x146];
    u16 value;
} Inner;

typedef struct Object {
    u8 pad[0x8C];
    Inner* inner;
} Object;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201B8C();
extern char lbl_8023BEF8[];

s32 fn_8001BFD0(void* arg)
{
    s32 id;
    s32 value;
    Object* object;

    if (fn_8016A598(arg) != 2) {
        fn_80163BB4(arg, lbl_8023BEF8, 2, fn_8016A598(arg));
        return 0;
    }

    id = (s32)fn_8016A694(arg, 1);
    value = (s32)fn_8016A694(arg, 2);
    object = fn_80201B8C(fn_80201814(id));
    object->inner->value = value;
    return 1;
}
