typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Vec4 { float x, y, z, w; } Vec4;

typedef struct ActorInfo {
    char pad0[0x90];
    void *resource;
    char pad94[0x9A - 0x94];
    short spriteId;
} ActorInfo;

typedef struct Resource {
    char pad0[0x40];
    short mode;
} Resource;

typedef struct CodecEntry {
    void *unk0;
    void *model;
    char pad8[0x20 - 0x8];
    void *actor;
    void *owner;
    int unk28;
} CodecEntry;

typedef struct SearchResult {
    char pad0[0x8];
    Vec3 pos;
    char pad14[0x34 - 0x14];
} SearchResult;

extern Vec3 lbl_8023A298;
extern Vec3 lbl_8023A2A4;
extern int lbl_8064CCDC;
extern int lbl_8064D18C;
extern const float lbl_8064FE70;
extern const float lbl_8064FE74;

extern void fn_80117F30(void);
extern void fn_80117FA0(void);
extern void fn_80117FDC(void);
extern void *fn_800070E4(int, int, float, float, float, int, u16);
extern Resource *fn_80072354(void *);
extern u8 fn_800CC2D8(void *, int);
extern short fn_8010DA50(int);
extern short fn_8010DA94(int);
extern void fn_8011EAB4(void *, int);
extern int fn_8011EB04(void *);
extern int fn_8011F598(void *, int, int, int, void *, int);
extern void fn_8011FB54(void *, int);
extern void fn_80120AD0(void *, int, int, int, float, float);
extern void fn_80124664(void *, int, int, float);
extern void fn_801261F4(void *);
extern void fn_801294DC(void *, int, int, int);
extern int fn_8012A100(void *, int);
extern void fn_8012C478(void *, int, int);
extern void fn_8012CCF0(void *, int, Vec3, Vec3, Vec3, int);
extern void fn_8012CDF0(void *, int, Vec4, int);
extern void fn_801568B8(void *, void (*)(void));
extern void fn_801568C0(void *, void (*)(void));
extern void fn_801568FC(void *, int);
extern void fn_80156904(void *, int);
extern void fn_8015690C(void *, void (*)(void));
extern void fn_80156918(void *, void *);
extern void *fn_80156DA0(int, int);
extern Vec4 fn_80157824(void *);
extern void *fn_8015784C(void *);
extern u16 fn_80157994(void *);
extern void fn_801F69F0(int *, Vec3 *, int);
extern ActorInfo *fn_80201B8C(void *);
extern void *fn_80201C24(void *);
extern int fn_8020492C(void *);

void fn_80109FA0(CodecEntry *entry, void *actor, int slot)
{
    void *owner;
    ActorInfo *info;
    Resource *resource;
    void *handle;
    Vec4 color;
    SearchResult search;
    Vec3 world;
    int pos[3];

    owner = fn_80201C24(actor);
    info = fn_80201B8C(actor);
    entry->unk28 = fn_8020492C(owner);
    entry->owner = owner;
    pos[0] = fn_8010DA50(slot);
    pos[1] = fn_8010DA94(slot);
    entry->unk0 = (void *)(pos[2] = (int)fn_8015784C(owner));
    fn_801F69F0(pos, &world, 0);
    resource = fn_80072354(info->resource);
    entry->actor = actor;
    entry->model = fn_800070E4(info->spriteId, resource->mode, world.x, world.y, world.z,
                               lbl_8064D18C, 0);
    if (info->spriteId == 0xCD) {
        fn_801261F4(entry->model);
        fn_80120AD0(entry->model, 0, 100, 0x20A, lbl_8064FE70, lbl_8064FE74);
    }
    if (fn_8012A100(entry->model, 0xF) != 0) {
        fn_8011EAB4(entry->model, 0xF);
        fn_801294DC(entry->model, 0xF, 1, 1);
    }
    fn_8011FB54(entry->model, lbl_8064D18C);
    fn_801261F4(entry->model);
    if (fn_8011EB04(entry->model) == 0x70) {
        if (fn_80157994(owner) != 0) {
            fn_80124664(entry->model, 0x1A, 8, lbl_8064FE70);
        } else {
            fn_80124664(entry->model, 0x1A, 8, lbl_8064FE74);
        }
    }
    color = fn_80157824(owner);
    fn_8012C478(entry->model, 0xF, 1);
    handle = fn_80156DA0(3, 0);
    fn_80156904(handle, 0);
    fn_801568FC(handle, 0);
    fn_801568C0(handle, fn_80117FDC);
    fn_801568B8(handle, fn_80117F30);
    fn_8015690C(handle, fn_80117FA0);
    fn_80156918(handle, entry->model);
    if (fn_8011F598(entry->model, 1, 0xF, -1, &search, 1) != -1) {
        search.pos.x = world.x - search.pos.x;
        search.pos.y = world.y - search.pos.y;
        search.pos.z = world.z - search.pos.z;
        fn_8012CCF0(entry->model, 0xF, search.pos, lbl_8023A298, lbl_8023A2A4, 1);
    }
    if (color.x != lbl_8064FE74 || color.y != lbl_8064FE74 || color.z != lbl_8064FE74 ||
        color.w != lbl_8064FE74) {
        fn_8012CDF0(entry->model, 0xF, color, 1);
    }
    if (fn_800CC2D8(entry->model, 0)) {
        fn_8012C478(entry->model, 0x10, 0);
    }
    if (fn_800CC2D8(entry->model, 1)) {
        fn_8012C478(entry->model, 0x11, 0);
    }
    lbl_8064CCDC = -1;
}
