typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Action800A2B8C {
    u8 pad00[4];
    s16 value04;
    s16 value06;
    s16 value08;
    u8 pad0A[6];
    u8 value10;
    u8 pad11[2];
    signed char value13;
    u8 value14;
    u8 pad15[3];
    u8 flags18;
    u8 value19;
    u8 pad1A[2];
    u16 value1C;
    u8 pad1E[0x32];
    float value50;
    u8 pad54[0x24];
    u32 value78;
    u8 pad7C[0x14];
    void (*callback)(void);
    u32 value94;
    Vec3 position;
    u8 params[6];
    u8 padAA[0xA];
    u8 typeB4;
} Action800A2B8C;

typedef struct Runtime800A2B8C {
    u8 pad000[0x84];
    u16 flags84;
    u8 pad086[2];
    Vec3 position88;
    float value94;
    float value98;
    u8 pad09C[0x30];
    Action800A2B8C actionCC;
    u32 handle160;
} Runtime800A2B8C;

typedef struct Context800A2B8C {
    u8 pad00[0x64];
    Runtime800A2B8C* runtime;
} Context800A2B8C;

extern u32 lbl_80651A18;
extern u16 lbl_80651A1C;
extern float lbl_8064EE70;
extern float lbl_8064EE8C;
extern float lbl_8064EE90;
extern float lbl_8064EE94;
extern double lbl_8064EE98;

extern Context800A2B8C* fn_80201B8C(void);
extern void* fn_80035628(void*);
extern void fn_801857B4(Action800A2B8C*);
extern void fn_801D38BC(void*, u32*, s16*);
extern void fn_80185A44(void);
extern void fn_80201E78(Vec3*, void*);
extern void* memcpy(void*, const void*, unsigned int);
extern int fn_801E8328(int, Action800A2B8C*);

void fn_800A2B8C(void* object, u16 value)
{
    Context800A2B8C* context = fn_80201B8C();
    Runtime800A2B8C* runtime = context->runtime;
    u32 positionWord;
    s16 actionValue;
    u8 params[6];
    Vec3 position;
    void* source;

    if ((runtime->flags84 & 0x20) == 0 && runtime->handle160 == 0) {
        params[0] = ((u8*)&lbl_80651A18)[0];
        params[1] = ((u8*)&lbl_80651A18)[1];
        params[2] = ((u8*)&lbl_80651A18)[2];
        params[3] = ((u8*)&lbl_80651A18)[3];
        params[4] = ((u8*)&lbl_80651A1C)[0];
        params[5] = ((u8*)&lbl_80651A1C)[1];
        runtime->flags84 |= 0x20;
        source = fn_80035628(object);
        runtime->handle160 = 0;
        fn_801857B4(&runtime->actionCC);
        fn_801D38BC(source, &positionWord, &actionValue);
        runtime->actionCC.value04 = actionValue;
        runtime->actionCC.value08 = 0;
        runtime->actionCC.value06 = 0;
        runtime->actionCC.value10 = 100;
        runtime->actionCC.value13 = -10;
        runtime->actionCC.value19 = 16;
        runtime->actionCC.value78 = positionWord;
        runtime->actionCC.value1C = value;
        runtime->actionCC.value14 = 0;
        runtime->actionCC.value50 = lbl_8064EE8C;
        runtime->actionCC.flags18 |= 3;
        runtime->actionCC.callback = fn_80185A44;
        runtime->value98 = lbl_8064EE90;
        runtime->value94 = lbl_8064EE94 * (float)value;
        fn_80201E78(&position, object);
        runtime->position88 = position;
        runtime->position88.z = lbl_8064EE70;
        runtime->actionCC.position = runtime->position88;
        memcpy(runtime->actionCC.params, params, 6);
        runtime->actionCC.value94 = 0;
        runtime->actionCC.typeB4 = 2;
        fn_801E8328(16, &runtime->actionCC);
    }
}
