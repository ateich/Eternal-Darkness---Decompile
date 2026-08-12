typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct EffectDescriptor {
    u8 pad00;
    u8 enabled;
    u8 pad02[2];
    u16 type;
    u16 duration;
    u8 pad08[0xE];
    u8 mode16;
    u8 mode17;
    u8 pad18[4];
    u32 value1C;
    u32 value20;
    u8 pad24[0x10];
    float scale;
    u8 pad38[4];
    u8 active;
    u8 alpha;
    u8 size;
    u8 pad3F[0x51];
    void (*callback)(void);
    u8 pad94[0x14];
    u32 owner;
    u8 padAC[0x20];
} EffectDescriptor;

typedef struct SpawnedEffect {
    u8 pad00[8];
    s32 kind;
    u8 pad0C[0x3C];
    s32 channel;
} SpawnedEffect;

typedef struct QueryResult {
    u8 data[0x28];
} QueryResult;

typedef struct ChannelList {
    s32 value[3];
} ChannelList;

extern volatile const ChannelList lbl_80238D58;
extern const float lbl_8064E160;

extern void* fn_80155DB4(void);
extern void *fn_80201BC8();
extern int fn_80201B54();
extern int fn_80035628(void*);
extern void fn_80147E88(EffectDescriptor*);
extern void fn_8019B13C(EffectDescriptor*);
extern s32 fn_801D3A24(s32, s32);
extern s32 fn_8011F598(void*, s32, s32, s32, QueryResult*, s32);
extern SpawnedEffect* fn_80149E04(void);
extern void fn_8014F4CC(EffectDescriptor*, SpawnedEffect*);
extern void fn_8019B090(void);
extern u32 fn_80148300(void*, EffectDescriptor*, SpawnedEffect*);
extern void fn_80149EB8(SpawnedEffect*);

void fn_800317AC(s32 object_id, s32 alternate)
{
    ChannelList channels;
    QueryResult query;
    EffectDescriptor effect;
    void* manager;
    void* object;
    s32 i;

    manager = fn_80155DB4();
    if (manager == 0) {
        return;
    }

    object = fn_80201BC8(object_id);
    if (object == 0) {
        return;
    }

    fn_80147E88(&effect);
    effect.owner = fn_80201B54(object_id);
    fn_8019B13C(&effect);
    effect.enabled = 0;
    effect.type = fn_801D3A24(fn_80035628((void*)object_id), 0x31);
    effect.value1C = 0;
    effect.value20 = 0;
    effect.mode16 = 0;
    effect.scale = lbl_8064E160;
    effect.active = 1;

    if (alternate == 0) {
        effect.duration = 20;
        effect.alpha = 200;
        effect.size = 20;
        effect.mode17 = 0x60;
    } else {
        effect.duration = 15;
        effect.alpha = 100;
        effect.size = 10;
        effect.mode17 = 0x40;
    }

    for (i = 0; i < 3; i++) {
        SpawnedEffect* spawned;

        channels = lbl_80238D58;
        if (fn_8011F598(object, 0x13, channels.value[i], -1, &query, 1) == -1) {
            continue;
        }

        spawned = fn_80149E04();
        if (spawned == 0) {
            continue;
        }

        fn_8014F4CC(&effect, spawned);
        effect.callback = fn_8019B090;
        spawned->kind = 0x13;
        spawned->channel = channels.value[i];
        if (fn_80148300(manager, &effect, spawned) == 0) {
            fn_80149EB8(spawned);
            break;
        }
    }
}
