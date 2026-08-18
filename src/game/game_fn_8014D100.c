typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

#pragma options align=packed
typedef struct EffectWork {
    u8 kind;
    u8 pad01[0x1B];
    int owner;
    u8 pad20[0x90];
} EffectWork;
#pragma options align=reset

typedef struct SearchResult {
    u8 pad00[8];
    Vec3 position;
    Vec3 offset;
} SearchResult;

extern Vec3 lbl_8023A744;
extern float lbl_8064CF04;
extern float lbl_806504F8;
extern float lbl_806504FC;
extern float lbl_80650500;
extern float lbl_80650504;
extern void* lbl_8064C4E0;
extern int lbl_802FC5BC[];

extern int fn_8011F6A4(void*, int, int, int, SearchResult*, int);
extern void fn_8012B690(void*, Vec3*, Vec3*);
extern int fn_800FBFB0(void);
extern void fn_8017EA58(EffectWork*);
extern void fn_80183DD4(EffectWork*);
extern int fn_801E79FC(void*, int);
extern void* fn_80148008(Vec3*, u16*, EffectWork*, void (*)(void));
extern void fn_8017EAA8(void);
extern void fn_80183EE0(void);
extern void* fn_80156938(void*);
extern void fn_8017FF1C(void*, int);
extern void* fn_80201A84(void*);
extern void* fn_80201814(void*);
extern void* fn_80201B8C(void*);
extern int fn_800676C8(u8);
extern void fn_80052310(int, u16*);

/*
 * Honest NonMatching reconstruction of both effect-spawn paths. Retail
 * aggressively overlays SearchResult, two packed EffectWork records and
 * conversion temporaries in one 0x130-byte frame; this keeps those logical
 * lifetimes explicit while preserving the recovered behavior.
 */
void fn_8014D100(void* context, int* source, int first_kind, int second_kind)
{
    u16 range[3];
    u16 sound_position[3];
    Vec3 position;
    Vec3 spawn_position;
    Vec3 basis = lbl_8023A744;
    SearchResult search;
    EffectWork work;
    void* object;
    void* owner;
    int kind;
    int sound;

    if (lbl_8064CF04 >= lbl_806504F8)
        return;

    if (fn_8011F6A4(context, 0x12, 0, -1, &search, 1) != -1) {
        position = search.position;
        range[0] = (short)(search.offset.x * lbl_80650504);
        range[1] = (short)(search.offset.y * lbl_80650504);
        range[2] = (short)(search.offset.z * lbl_80650504);
    } else {
        fn_8012B690(context, &basis, &position);
        range[0] = 1 - (fn_800FBFB0() & 3);
        range[1] = 1 - (fn_800FBFB0() & 3);
        range[2] = -3;
    }

    fn_8017EA58(&work);
    work.owner = *source;
    if (fn_801E79FC(lbl_8064C4E0, 0x2ED) != 0)
        work.owner = lbl_802FC5BC[9];
    if (lbl_8064CF04 >= lbl_806504FC) {
        kind = (first_kind >> 2) & 0x3F;
        if (kind <= 0)
            kind = first_kind & 0xFF;
    } else if (lbl_8064CF04 >= lbl_80650500) {
        kind = (first_kind >> 1) & 0x7F;
        if (kind <= 0)
            kind = first_kind & 0xFF;
    } else {
        kind = first_kind & 0xFF;
    }
    work.kind = kind;
    spawn_position = position;
    object = fn_80148008(&spawn_position, range, &work, fn_8017EAA8);
    if (object != 0)
        fn_8017FF1C(fn_80156938(object), 4);

    if ((fn_800FBFB0() & 1) != 0) {
        owner = fn_80201B8C(fn_80201814(fn_80201A84(context)));
        fn_80183DD4(&work);
        work.owner = *source;
        if (fn_801E79FC(lbl_8064C4E0, 0x2ED) != 0)
            work.owner = lbl_802FC5BC[9];
        if (lbl_8064CF04 >= lbl_806504FC) {
            kind = (second_kind >> 2) & 0x3F;
            if (kind <= 0)
                kind = second_kind & 0xFF;
        } else if (lbl_8064CF04 >= lbl_80650500) {
            kind = (second_kind >> 1) & 0x7F;
            if (kind <= 0)
                kind = second_kind & 0xFF;
        } else {
            kind = second_kind & 0xFF;
        }
        work.kind = kind;
        spawn_position = position;
        object = fn_80148008(&spawn_position, range, &work, fn_80183EE0);
        if (object != 0)
            fn_8017FF1C(fn_80156938(object), 4);
        sound_position[0] = (short)position.x;
        sound_position[1] = (short)position.y;
        sound_position[2] = (short)position.z;
        sound = 50;
        if (fn_800676C8(*(u8*)((char*)context + 0x9F)) != 0)
            sound = 84;
        fn_80052310(sound, sound_position);
        (void)owner;
    }
}
