/* NonMatching: independent reconstruction of the 0x80151D00 event callback. */
#include "src/game/types.h"
typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

extern u32 lbl_80651C38;
extern u16 lbl_80651C3C;
extern u32 lbl_80651C40;
extern u16 lbl_80651C44;
extern u32 lbl_80651C48;
extern u16 lbl_80651C4C;
extern float lbl_80650584;
extern s32 lbl_8064D18C;

extern void fn_80199128(void*, s32);
extern unsigned long long fn_8020123C(s32, s32, s32, s32);
extern void fn_8019B134(void*, s32);
extern void fn_8019B13C(void*);
extern void* fn_80148008(Vec3f*, void*, void*, void (*)(void));
extern void fn_8019ADE4(void);
extern void* fn_80156938(void);
extern void fn_8017FF1C(void*, s32);
extern void fn_8017FE1C(void*, void (*)(void));
extern void fn_8018B058(void);
extern void fn_801809B8(void*, u8);
extern void fn_80152260(s32, void*, Vec3f*, u16, u16, s32, u32, u32, void*, u16);
extern void fn_8019A3A4(void*);
extern void fn_8019A300(void);
extern Vec3s* fn_8017FDA8(void*, s32);
extern void* memcpy(void*, const void*, u32);
extern int fn_801E8328(s32, void*);
extern void fn_80199EBC(void*);
extern void fn_80199E18(void);
extern void fn_8014F700(Vec3f*, s16, void*);
extern void fn_80149E28(void*);
void fn_80151D00(u8* instance)
{
    u8* work = instance + 8;
    u16 frame;
    u16 end;
    void* object;
    Vec3s* object_position;
    Vec3f position;
    u8 key[8];
    u8 descriptor[60];
    u8* command;

    if (*(s32*)(instance + 8) != 0 && *(s32*)(work + 4) == 0) {
        *(u16*)(work + 0x18) = *(u16*)(instance + 0x132C) + *(u16*)(work + 0x16);
        if (*(void**)(work + 0x238) != 0)
            fn_80199128(*(void**)(work + 0x238), 0);
        *(u16*)(work + 0x1E) = *(u16*)(work + 0x18) - 50;
        if (*(s32*)(work + 0x28) > 0)
            fn_8020123C(0xE2, *(s32*)(work + 0x28), *(s32*)(work + 0x28), 0);
        *(s32*)(work + 4) = 1;
    }

    frame = *(u16*)(instance + 0x132C);
    if (*(void**)(work + 0x254) != 0 && frame == *(u16*)(work + 0x1E))
        fn_8019B134(*(void**)(work + 0x254), 0);

    end = *(u16*)(work + 0x12);
    if (frame == end - 60) {
        *(u32*)key = lbl_80651C38;
        *(u16*)(key + 4) = lbl_80651C3C;
        fn_8019B13C(descriptor);
        descriptor[1] = 1;
        descriptor[2] = 0xF5;
        descriptor[3] = (u8)-7;
        *(u16*)(descriptor + 4) = *(s16*)(work + 0x0E);
        *(u16*)(descriptor + 6) = *(u16*)(work + 0x18) - end + 20;
        descriptor[0x16] = 7;
        descriptor[0x17] = 0xF5;
        *(u32*)(descriptor + 0x1C) = 0;
        *(u32*)(descriptor + 0x20) = 0;
        *(u32*)(descriptor + 0x28) = 1;
        *(float*)(descriptor + 0x34) = lbl_80650584;
        *(u32*)(descriptor + 0x38) = *(u32*)(work + 0x24);
        position = *(Vec3f*)(work + 0x2C);
        if (fn_80148008(&position, key, descriptor, fn_8019ADE4) != 0) {
            object = fn_80156938();
            fn_8017FF1C(object, 2);
            fn_8017FE1C(object, fn_8018B058);
            *(void**)(work + 0x254) = object;
        }
    } else if (frame >= end - 58 && frame <= end - 10 && *(void**)(work + 0x254) != 0) {
        fn_801809B8(*(void**)(work + 0x254), frame - (end - 56));
    }

    if (frame >= *(u16*)(work + 0x18) - 50 && *(void**)(work + 0x254) != 0) {
        u8 value = *(u16*)(work + 0x18) - frame - 1;
        if (value != 0)
            fn_801809B8(*(void**)(work + 0x254), value);
    }

    if (frame == end) {
        void* optional = 0;
        if (*(s32*)(work + 0x28) > 0)
            optional = work;
        fn_80152260(*(s32*)(instance + 0x1324), *(void**)(work + 0x20),
                     (Vec3f*)(work + 0x38), 50, *(u16*)(work + 0x14),
                     (s32)*(void**)(work + 0x254),
                     *(u32*)(work + 0x24), *(u32*)(work + 0x28), optional,
                     *(u16*)(work + 0x0A));
    } else if (frame == end + 10 && *(s32*)work == 0) {
        *(u32*)key = lbl_80651C40;
        *(u16*)(key + 4) = lbl_80651C44;
        command = work + 0x1A4;
        fn_8019A3A4(command);
        *(u16*)(command + 4) = *(s16*)(work + 0x10);
        *(u16*)(command + 6) = *(u16*)(work + 0x14) - 20;
        *(void**)(command + 0x14) = *(void**)(work + 0x254);
        *(u32*)(command + 0x18) = *(u32*)(work + 0x24);
        *(void (**)(void))(command + 0x90) = fn_8019A300;
        object_position = fn_8017FDA8(*(void**)(work + 0x254), 0);
        *(Vec3f*)(command + 0x98) = (Vec3f){object_position->x, object_position->y, object_position->z};
        memcpy(command + 0xA4, key, 6);
        *(u32*)(command + 0x94) = 0;
        command[0xAA] = 2;
        fn_801E8328(0x10, command);
    }

    if (*(s32*)(instance + 0x1324) == lbl_8064D18C) {
        if (frame == 0) {
            *(u32*)key = lbl_80651C48;
            *(u16*)(key + 4) = lbl_80651C4C;
            command = work + 0x44;
            fn_80199EBC(command);
            *(u16*)(command + 6) = end - 10;
            *(u16*)(command + 4) = *(s16*)(work + 0x0E);
            *(u16*)(command + 0x20) = *(float*)(work + 0x2C);
            *(u16*)(command + 0x22) = *(float*)(work + 0x30);
            *(u16*)(command + 0x24) = *(float*)(work + 0x34);
            *(u32*)(command + 0x2C) = *(u32*)(work + 0x24);
            *(void (**)(void))(command + 0x90) = fn_80199E18;
            memcpy(command + 0xA4, key, 6);
            *(u32*)(command + 0x94) = 0;
            command[0xAA] = 4;
            fn_801E8328(0x10, command);
        }
        if (frame == *(u16*)(work + 0x1A) || frame == *(u16*)(work + 0x1A) + 10 ||
            frame == *(u16*)(work + 0x1A) + 20) {
            object_position = fn_8017FDA8(*(void**)(work + 0x254), 0);
            position.x = object_position->x;
            position.y = object_position->y;
            position.z = object_position->z;
            *(u32*)key = *(u32*)(work + 0x258);
            fn_8014F700(&position, *(s16*)(work + 0x0C), key);
        }
    }

    if (frame == *(u16*)(work + 0x1A) + 20)
        *(u16*)(work + 0x1A) += 0x8D;

    if (*(s32*)(work + 0x28) > 0) {
        if (*(s32*)work != 0 && frame == *(u16*)(work + 0x18))
            fn_80149E28(instance);
    } else if (frame == *(u16*)(work + 0x18)) {
        fn_80149E28(instance);
    }
}
