typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

typedef struct QueryResult {
    u8 pad[8];
    Vec3 position;
    Vec3 direction;
    u8 pad2[8];
} QueryResult;

typedef struct TargetInfo {
    u8 pad[4];
    Vec3 position;
} TargetInfo;

typedef struct DebugPath {
    Vec3 start[10];
    Vec3 end[10];
    u32 active[10];
} DebugPath;

typedef struct PaletteEntry {
    u8 pad[4];
    int disabled;
} PaletteEntry;

typedef struct Palette {
    u8 pad[0x70];
    PaletteEntry **entries;
} Palette;

typedef struct Actor {
    u8 pad[0x9F];
    u8 kind;
} Actor;

extern void *fn_80156938(void);
extern void *fn_80201BC8();
extern void fn_80201ADC(void);
extern void fn_801EC9A8(void);
extern Palette *fn_8015C28C(int id);
extern void fn_8011FAEC(void *model);
extern void fn_80120A30();
extern void *fn_80201B8C(void *object);
extern Vec3 fn_80201E78(void *object);
extern int fn_8011F6A4(void *model, int a, int b, int c, QueryResult *out, int d);
extern void fn_801E7CBC(Vec3 a, Vec3 b, Vec3 c, Vec3 d, Color color);
extern void *fn_80205288(void *object);
extern u32 fn_80178E94(Vec3 *a, Vec3 *b);
extern void fn_80211A90(Vec3 *in, Vec3 *out, f32 scale);
extern void fn_80211A48(Vec3 *a, Vec3 *b, Vec3 *out);
extern void fn_80211C78(Vec3 *a, Vec3 *b, Vec3 *out);
extern void fn_80211AAC(Vec3 *in, Vec3 *out);
extern void fn_800EBA80(int a, Vec3 *pos, Color color, int b, f32 c);

extern DebugPath lbl_80303A18;
extern const Vec3 lbl_80238CC4;
extern u8 lbl_802FC5BC[];
extern void *lbl_8064C4E4;
extern int lbl_8064C5C4;
extern int lbl_8064C5C8;
extern int lbl_8064C710;
extern u8 *lbl_8064C718;
extern int lbl_8064CB5C;
extern int lbl_8064CB60;
extern u8 lbl_8064D5F8;
extern const Color lbl_8064E004;
extern const Color lbl_8064E008;
extern const Color lbl_8064E00C;
extern const Color lbl_8064E010;
extern const f32 lbl_8064E014;
extern const f32 lbl_8064E018;
extern const f32 lbl_8064E01C;
extern const f32 lbl_8064E020;
extern const f32 lbl_8064E024;

void fn_8002AC60(void) {
    QueryResult result;
    QueryResult hit;
    Vec3 position;
    Vec3 positionLow;
    Vec3 otherLow;
    Vec3 start;
    Vec3 startHigh;
    Vec3 target;
    Vec3 endHigh;
    Vec3 offset;
    Vec3 end;
    Vec3 side;
    Vec3 tip;
    Vec3 tipHigh;
    Vec3 lineEnd;
    Vec3 lineStart;
    Vec3 lineTip;
    Color offColor;
    Color onColor;
    Color color;
    Vec3 *starts;
    Vec3 *ends;
    u32 *active;
    void *object;
    void *model;
    void *current;
    Palette *palette;
    PaletteEntry **entries;
    void **info;
    void *partner;
    void *partnerModel;
    Actor *actor;
    int kind;
    int i;
    DebugPath *path;

    path = &lbl_80303A18;
    object = fn_80156938();
    model = fn_80201BC8();
    fn_80201ADC();
    current = fn_80201BC8();
    fn_801EC9A8();
    if (lbl_8064C5C4 == 0 && model == lbl_8064C4E4) {
        return;
    }
    if (lbl_8064C5C8 == 0 && current == model) {
        return;
    }
    if (model != 0) {
        palette = fn_8015C28C(2);
        fn_8011FAEC(model);
        entries = palette->entries;
        if (entries != 0) {
            if (entries[lbl_8064D5F8]->disabled != 0) {
                fn_80120A30(model, entries[lbl_8064D5F8], 0xBB8);
            } else {
                fn_80120A30(model, entries[0], 0xBB8);
            }
        } else {
            fn_80120A30(model, 0, 0xBB8);
        }

        if (lbl_8064CB5C != 0) {
            info = fn_80201B8C(object);
            if (info != 0 && info[1] != 0) {
                Vec3 fetched;
                Vec3 other;

                fetched = fn_80201E78(object);
                position = fetched;
                other = lbl_80238CC4;
                color = lbl_8064E004;
                if (fn_8011F6A4(model, 0x13, 0, -1, &result, 1) != -1) {
                    position = result.position;
                } else {
                    position.z += lbl_8064E014;
                }
                positionLow = position;
                positionLow.z -= lbl_8064E018;
                otherLow = other;
                otherLow.z -= lbl_8064E018;
                fn_801E7CBC(position, positionLow, other, otherLow, color);
                fn_801E7CBC(otherLow, other, positionLow, position, color);
            }
        }

        if (lbl_8064CB60 != 0) {
            info = fn_80201B8C(object);
            if (info != 0 && *info != 0) {
                partner = fn_80205288(object);
                if (partner != 0) {
                    partnerModel = fn_80201BC8();
                } else {
                    partnerModel = 0;
                }
                if (partner != 0) {
                    actor = fn_80201B8C(partner);
                } else {
                    actor = 0;
                }
                kind = actor != 0 ? actor->kind : 0x13;
                if (kind == 0x12 && partnerModel != 0) {
                    Vec3 fetched;
                    Color lineColor;

                    fetched = fn_80201E78(object);
                    start = fetched;
                    lineColor = lbl_8064E008;
                    offColor = lbl_8064E00C;
                    onColor = lbl_8064E010;
                    target = ((TargetInfo *)*info)->position;
                    if (fn_8011F6A4(partnerModel, 4, -1, -1, &hit, 1) != -1) {
                        start = hit.position;
                    }
                    fn_80211A90(&hit.direction, &offset, (f32)fn_80178E94(&start, &target));
                    fn_80211A48(&hit.position, &offset, &end);
                    startHigh = start;
                    startHigh.z += lbl_8064E01C;
                    endHigh = end;
                    endHigh.z += lbl_8064E01C;
                    lineStart = start;
                    lineEnd = end;
                    fn_801E7CBC(start, startHigh, end, endHigh, lineColor);
                    fn_801E7CBC(endHigh, end, startHigh, start, lineColor);

                    fn_800EBA80(0, &target, *(Color *)(lbl_802FC5BC + 0x14), 100, lbl_8064E020);

                    if (lbl_8064C718 != 0) {
                        fn_80211C78(&hit.direction, (Vec3 *)(lbl_8064C718 + 0x14), &side);
                        fn_80211AAC(&side, &side);
                        fn_80211A90(&side, &side, lbl_8064E024);
                        fn_80211A48(&end, &side, &tip);
                        tipHigh = tip;
                        tipHigh.z += lbl_8064E01C;
                        lineTip = tip;
                        fn_801E7CBC(end, endHigh, tip, tipHigh, lineColor);
                        fn_801E7CBC(tipHigh, tip, endHigh, end, lineColor);
                    }

                    starts = path->start;
                    ends = path->end;
                    active = path->active;
                    for (i = 0; i <= lbl_8064C710; i++) {
                        start = starts[i];
                        startHigh = start;
                        startHigh.z += lbl_8064E01C;
                        end = ends[i];
                        endHigh = end;
                        endHigh.z += lbl_8064E01C;
                        if (active[i] != 0) {
                            fn_801E7CBC(start, startHigh, end, endHigh, onColor);
                            fn_801E7CBC(endHigh, end, startHigh, start, onColor);
                        } else {
                            fn_801E7CBC(start, startHigh, end, endHigh, offColor);
                            fn_801E7CBC(endHigh, end, startHigh, start, offColor);
                        }
                    }
                }
            }
        }
    }
}
