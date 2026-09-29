typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct EffectInfo {
    u8 type;
    u8 count;
    u8 pad02[2];
    u16 value04;
    u8 pad06[0x12];
    u32 word18;
    u8 pad1C[0x78];
} EffectInfo;

typedef struct BurstInfo {
    u8 count;
    u8 enabled;
    u8 color0;
    u8 color1;
    u16 value04;
    u16 value06;
    u8 pad08[0xC];
    u8 color14;
    u8 color15;
    u8 color16;
    u8 pad17[2];
    u8 color19;
    u8 pad1A[2];
    u32 word1C;
    u8 pad20[0x14];
    float scale34;
    u8 pad38[4];
    u8 flag3C;
    u8 color3D;
    u8 color3E;
    u8 pad3F[0x51];
    void (*callback90)(void);
    u8 pad94[4];
    Vec3 position98;
    u8 padA4[6];
    u8 modeAA;
    u8 padAB;
} BurstInfo;

typedef struct GameObject {
    u8 pad00[4];
    void* owner;
    int type;
    u8 pad0C[0x24];
    void* link30;
    u8 pad34[4];
    float field38;
    float field3C;
    float field40;
    void* resource44;
    u8 pad48[0xFA8];
    u8 flagsFF0;
    u8 padFF1[3];
    u16 stateFF4;
} GameObject;

extern int lbl_8064D18C;
extern u32 lbl_806510AC;
extern u16 lbl_806510B0;
extern u32 lbl_806510B4;
extern const float lbl_806510B8;
extern const float lbl_806510BC;
extern const float lbl_806510C0;
extern const float lbl_806510C4;
extern void fn_801FE22C(void*);
extern void fn_801D31E0(GameObject*);
extern void fn_80181F5C(EffectInfo*);
extern int fn_801D3A34(void*, int);
extern s16 fn_801CEB2C(void*);
extern float fn_80048C2C(float);
extern float fn_80048C50(float);
extern u32 fn_800FBFB0(void);
extern void* fn_80148008(Vec3*, s16*, EffectInfo*, void (*)(void));
extern void* fn_80156938(void*);
extern void fn_8017FF1C(void*, int);
extern void fn_80182014(void);
extern void fn_80181FD8(void);
extern void* fn_800CE9A4(u32*, int, int);
extern void fn_801E8328(int, void*);
extern void fn_80182380(EffectInfo*);
extern void fn_80182448(void);
extern void fn_8019B13C(BurstInfo*);
extern void fn_8019AD40(void);
extern void fn_80147EC4(BurstInfo*);

/*
 * Effect-object state callback.  The non-current-type teardown path and the
 * state discriminator are identified (the compiler removes its empty arms).
 * The four particle-construction arms still require their large stack-local
 * descriptor layouts to be typed.
 */
void fn_801D324C(GameObject* object)
{
    EffectInfo info;
    Vec3 position0, position2E, position42, position56;
    Vec3 work0, work2E, work42, work56;
    s16 range2E[3], range42[3], defaultRange[3];
    int count;
    int i;
    u32 resource;
    BurstInfo burst;

    if (object->type != lbl_8064D18C) {
        fn_801FE22C(object->resource44);
        fn_801D31E0(object);
        return;
    }

    *(u32*)&defaultRange[0] = lbl_806510AC;
    defaultRange[2] = lbl_806510B0;

    switch (object->stateFF4) {
    case 0:
        resource = lbl_806510B4;
        if (object->flagsFF0 & 4) {
            object->link30 = fn_800CE9A4(&resource, 10, 0);
            if (object->link30 != 0)
                fn_801E8328(13, object->link30);
        }

        fn_80182380(&info);
        info.type = 8;
        info.count = 1;
        info.value04 = fn_801D3A34(object->owner, 0x42);
        *(u16*)&info.pad06[0] = 30;
        *(u16*)&info.pad06[2] = 8;
        info.pad1C[3] = 2;
        count = fn_801CEB2C(object->owner);
        for (i = 0; i < (s16)count; i++) {
            float angle = lbl_806510B8 * i / (s16)count;
            work0.x = object->field38 + lbl_806510BC * fn_80048C2C(angle);
            work0.y = object->field3C + lbl_806510BC * fn_80048C50(angle);
            work0.z = object->field40;
            position0 = work0;
            {
                void* effect = fn_80148008(&position0, defaultRange,
                                            &info, fn_80182448);
                if (effect != 0)
                    fn_8017FF1C(fn_80156938(effect), 4);
            }
        }

        fn_8019B13C(&burst);
        burst.count = (u8)count;
        burst.enabled = 0;
        burst.color0 = 0xFC;
        burst.color1 = (u8)-6;
        burst.value04 = fn_801D3A34(object->owner, 0x31);
        burst.value06 = 0;
        burst.color14 = 0xF0;
        burst.color15 = 0x96;
        burst.color16 = 0;
        burst.color19 = (u8)-10;
        burst.word1C = 0;
        burst.scale34 = lbl_806510C0;
        burst.flag3C = 1;
        burst.color3D = 0xFC;
        burst.color3E = 12;
        burst.callback90 = fn_8019AD40;
        burst.position98.x = object->field38;
        burst.position98.y = object->field3C;
        burst.position98.z = object->field40 + lbl_806510C4;
        burst.modeAA = 4;
        fn_80147EC4(&burst);
        break;
    case 0x2E:
        fn_80181F5C(&info);
        info.count = 2;
        info.value04 = fn_801D3A34(object->owner, 0x42);
        info.word18 = 0;
        count = fn_801CEB2C(object->owner);
        for (i = 0; i < count; i++) {
            float angle = lbl_806510B8 * i / count;
            work2E.x = object->field38 + lbl_806510BC * fn_80048C2C(angle);
            work2E.y = object->field3C + lbl_806510BC * fn_80048C50(angle);
            work2E.z = object->field40;
            info.type = (fn_800FBFB0() & 7) + 10;
            range2E[0] = 0;
            range2E[1] = 0;
            range2E[2] = (fn_800FBFB0() & 3) + 10;
            position2E = work2E;
            {
                void* effect = fn_80148008(&position2E, range2E, &info, fn_80182014);
                if (effect != 0)
                    fn_8017FF1C(fn_80156938(effect), 4);
            }
        }
        break;
    case 0x42:
        fn_80181F5C(&info);
        info.count = 2;
        info.value04 = fn_801D3A34(object->owner, 0x42);
        info.word18 = 0;
        count = fn_801CEB2C(object->owner);
        for (i = 0; i < count; i++) {
            float angle = lbl_806510B8 * i / count;
            work42.x = object->field38 + lbl_806510BC * fn_80048C2C(angle);
            work42.y = object->field3C + lbl_806510BC * fn_80048C50(angle);
            work42.z = object->field40;
            info.type = (fn_800FBFB0() & 7) + 5;
            range42[0] = 0;
            range42[1] = 0;
            range42[2] = (fn_800FBFB0() & 3) + 8;
            position42 = work42;
            {
                void* effect = fn_80148008(&position42, range42, &info, fn_80182014);
                if (effect != 0)
                    fn_8017FF1C(fn_80156938(effect), 4);
            }
        }
        break;
    case 0x56:
        fn_80181F5C(&info);
        info.count = 2;
        info.value04 = fn_801D3A34(object->owner, 0x42);
        info.word18 = 0;
        count = fn_801CEB2C(object->owner);
        for (i = 0; i < count; i++) {
            float angle = lbl_806510B8 * i / count;
            work56.x = object->field38 + lbl_806510BC * fn_80048C2C(angle);
            work56.y = object->field3C + lbl_806510BC * fn_80048C50(angle);
            work56.z = object->field40;
            info.type = (fn_800FBFB0() & 3) + 4;
            position56 = work56;
            {
                void* effect = fn_80148008(&position56, defaultRange,
                                            &info, fn_80181FD8);
                if (effect != 0)
                    fn_8017FF1C(fn_80156938(effect), 4);
            }
        }
        fn_801D31E0(object);
        break;
    }
}
