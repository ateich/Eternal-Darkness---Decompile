typedef unsigned char u8;

typedef struct Inner800A3D90 {
    u8 pad0[0x190];
    int value;
} Inner800A3D90;

typedef struct Runtime800A3D90 {
    u8 pad0[0x64];
    Inner800A3D90* inner;
} Runtime800A3D90;

extern float lbl_8064EEC8;
extern float lbl_8064EECC;

extern void* fn_80200C38(void*);
extern Runtime800A3D90*fn_80201B8C();
extern int fn_801A7770(void*);
extern int fn_800A4EC8(void*, void*);
extern int fn_800A2068(void*, void*);
extern void fn_80066888(void*, void*, float, float);
extern void fn_800A4978(void*, void*, Runtime800A3D90*);
extern void* fn_80201B54();
extern void fn_80066754(void*, void*, void*);
extern void fn_801F74C8(int, int, int);
extern void fn_801441C0(int, int, int);

void fn_800A3D90(void* object, void* context, void* source, void* argument)
{
    void* resolved = fn_80200C38(source);
    Runtime800A3D90* runtime;
    int selection;

    selection = 1;
    runtime = fn_80201B8C(object);

    runtime->inner->value = fn_801A7770(resolved);
    if (fn_800A4EC8(object, resolved) > 0) {
        selection = fn_800A2068(object, context);
    }

    switch (selection) {
    case 0:
        fn_80066888(context, resolved, lbl_8064EEC8, lbl_8064EECC);
        fn_800A4978(object, context, runtime);
        break;
    case 1:
        fn_80201B54(object);
        fn_80066754(object, source, argument);
        break;
    }

    fn_801F74C8(0x28, 0, 6);
    fn_801441C0(1, 1, 0x28);
}
