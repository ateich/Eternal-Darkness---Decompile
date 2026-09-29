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
    u8 pad1C[0x70];
} EffectInfo;

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
extern const float lbl_806510B8;
extern const float lbl_806510BC;
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

/*
 * Effect-object state callback.  The non-current-type teardown path and the
 * state discriminator are identified (the compiler removes its empty arms).
 * The four particle-construction arms still require their large stack-local
 * descriptor layouts to be typed.
 */
void fn_801D324C(GameObject* object)
{
    EffectInfo info;
    Vec3 position;
    s16 range[3];
    int count;
    int i;

    if (object->type != lbl_8064D18C) {
        fn_801FE22C(object->resource44);
        fn_801D31E0(object);
        return;
    }

    switch (object->stateFF4) {
    case 0:
        break;
    case 0x2E:
        fn_80181F5C(&info);
        info.count = 2;
        info.value04 = fn_801D3A34(object->owner, 0x42);
        info.word18 = 0;
        count = fn_801CEB2C(object->owner);
        for (i = 0; i < count; i++) {
            float angle = lbl_806510B8 * i / count;
            position.x = object->field38 + lbl_806510BC * fn_80048C2C(angle);
            position.y = object->field3C + lbl_806510BC * fn_80048C50(angle);
            position.z = object->field40;
            info.type = (fn_800FBFB0() & 7) + 10;
            range[0] = 0;
            range[1] = 0;
            range[2] = (fn_800FBFB0() & 3) + 10;
            {
                void* effect = fn_80148008(&position, range, &info, fn_80182014);
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
            position.x = object->field38 + lbl_806510BC * fn_80048C2C(angle);
            position.y = object->field3C + lbl_806510BC * fn_80048C50(angle);
            position.z = object->field40;
            info.type = (fn_800FBFB0() & 7) + 5;
            range[0] = 0;
            range[1] = 0;
            range[2] = (fn_800FBFB0() & 3) + 8;
            {
                void* effect = fn_80148008(&position, range, &info, fn_80182014);
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
            position.x = object->field38 + lbl_806510BC * fn_80048C2C(angle);
            position.y = object->field3C + lbl_806510BC * fn_80048C50(angle);
            position.z = object->field40;
            info.type = (fn_800FBFB0() & 3) + 4;
            {
                void* effect = fn_80148008(&position, (s16*)&lbl_806510AC,
                                            &info, fn_80181FD8);
                if (effect != 0)
                    fn_8017FF1C(fn_80156938(effect), 4);
            }
        }
        fn_801D31E0(object);
        break;
    }
}
